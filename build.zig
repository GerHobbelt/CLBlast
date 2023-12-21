const std = @import("std");

/// dummy OpenCL finder, no clue how to find it cross platform
pub const OpenCL = struct {
    include_path: []const u8,
    lib_path: []const u8,

    //TODO: Intel opencl-sdl
    //  $(INTELOCLSDKROOT)\lib\
    // https://www.intel.com/content/www/us/en/docs/opencl-sdk/developer-reference-processor-graphics/2015-1/installable-client-driver-on-windows-os.html

    // for use with: https://github.com/GPUOpen-LibrariesAndSDKs/OCL-SDK/releases
    pub fn fromOCL(
        b: *std.Build,
        target: std.zig.CrossTarget,
    ) ?OpenCL {
        const root = std.process.getEnvVarOwned(b.allocator, "OCL_ROOT") catch {
            std.log.scoped(.OpenCl).debug("No OCL root exists", .{});
            return null;
        };
        const libp = b.pathJoin(&[_][]const u8{ root, "lib", @tagName(target.getCpuArch()) });
        if (std.fs.openDirAbsolute(libp, .{})) |*f| @constCast(f).close() else |_| {
            std.log.scoped(.OpenCl).warn("OpenCl.fromOCL() can't find path to libraries for selected cpuArch() at: {s}", .{libp});
            return null;
        }
        std.log.scoped(.OpenCl).debug("OCL headers/libs found", .{});
        return .{
            .include_path = b.pathJoin(&[_][]const u8{ root, "include" }),
            .lib_path = libp,
        };
    }

    pub fn link(self: @This(), comp: *std.Build.CompileStep) void {
        comp.addIncludePath(.{ .path = self.include_path });
        comp.addLibraryPath(.{ .path = self.lib_path });
        comp.linkSystemLibrary("OpenCL");
    }
};

pub const ClBlast = struct {
    pub const BackendType = enum {
        opencl,
        cuda,
    };
    pub const Backend = union(BackendType) {
        opencl: OpenCL,
        cuda: void, // TODO
    };

    pub const Options = struct {
        target: std.zig.CrossTarget,
        optimize: std.builtin.Mode,
        backend: Backend,

        shared_lib: bool = false,
        netlib: bool = false,

        verbose: bool = false,
        amd_si_empty_kernel_workaround: bool = false, // Enables workaround for bug in AMD Southern Island GPUs
    };

    build: *std.Build,
    options: Options,
    lib: *std.Build.CompileStep,

    pub fn build(b: *std.Build, options: Options) ClBlast {
        const lib_options = .{
            .name = "CLBlast",
            .target = options.target,
            .optimize = options.optimize,
        };
        const lib = if (options.shared_lib) b.addSharedLibrary(lib_options) else b.addStaticLibrary(lib_options);
        const res = .{
            .build = b,
            .options = options,
            .lib = lib,
        };
        const Helper = struct {
            cblast: ClBlast,
            lib: *std.Build.CompileStep,
            pub fn addSource(self: *@This(), path: []const u8) void {
                self.lib.addCSourceFile(.{ .file = .{ .path = self.cblast.build.pathJoin(&.{ thisPath(), path }) }, .flags = &.{} });
            }
        };
        var c = Helper{ .cblast = res, .lib = lib };

        if (options.amd_si_empty_kernel_workaround) lib.defineCMacro("DAMD_SI_EMPTY_KERNEL_WORKAROUND", null);
        switch (options.backend) {
            .opencl => |opencl| {
                lib.defineCMacro("OPENCL_API", null);
                c.addSource("src/clblast.cpp");
                c.addSource("src/clblast_c.cpp");
                c.addSource("src/tuning/tuning_api.cpp");
                // set(HEADERS ${HEADERS} include/clblast.h include/clblast_c.h src/clpp11.hpp)
                if (options.netlib) {
                    c.addSource("src/clblast_netlib_c.cpp");
                    //set(HEADERS ${HEADERS} include/clblast_netlib_c.h)
                }
                lib.addSystemIncludePath(.{ .path = opencl.include_path });
            },
            .cuda => {
                lib.defineCMacro("DCUDA_API", null);
                c.addSource("src/clblast_cuda.cpp");
                //set(HEADERS ${HEADERS} include/clblast_cuda.h src/cupp11.hpp)
            },
        }
        if (options.verbose) lib.defineCMacro("VERBOSE", null);
        if (options.target.getOsTag() == .windows and options.shared_lib) lib.defineCMacro("CLBLAST_DLL", null);
        lib.addIncludePath(.{ .path = thisPath() });
        lib.addIncludePath(.{ .path = b.pathJoin(&.{ thisPath(), "src" }) });
        lib.addIncludePath(.{ .path = b.pathJoin(&.{ thisPath(), "include" }) });

        // ==================================================================================================

        // Sets the supported routines and the used kernels. New routines and kernels should be added here.
        const kernels = [_][]const u8{ "copy_fast", "copy_pad", "transpose_fast", "transpose_pad", "xaxpy", "xdot", "xger", "xgemm", "xgemm_direct", "xgemv", "invert", "xconvgemm" };
        _ = kernels;

        const databases = [_][]const u8{ "copy", "pad", "padtranspose", "transpose", "xaxpy", "xdot", "xgemm", "xgemm_direct", "xgemv", "xgemv_fast", "xgemv_fast_rot", "xger", "invert", "gemm_routine", "trsv_routine", "xconvgemm" };
        const routinge_tuners = [_][]const u8{ "xgemm", "xtrsv" };
        _ = routinge_tuners;
        const level1_routines = [_][]const u8{ "xswap", "xscal", "xcopy", "xaxpy", "xdot", "xdotu", "xdotc", "xnrm2", "xasum", "xamax" };
        const level2_routines = [_][]const u8{ "xgemv", "xgbmv", "xhemv", "xhbmv", "xhpmv", "xsymv", "xsbmv", "xspmv", "xtrmv", "xtbmv", "xtpmv", "xtrsv", "xger", "xgeru", "xgerc", "xher", "xhpr", "xher2", "xhpr2", "xsyr", "xspr", "xsyr2", "xspr2" };
        const level3_routines = [_][]const u8{ "xgemm", "xsymm", "xhemm", "xsyrk", "xherk", "xsyr2k", "xher2k", "xtrmm", "xtrsm" };
        const levelx_routines = [_][]const u8{ "xhad", "xomatcopy", "xim2col", "xcol2im", "xconvgemm", "xaxpybatched", "xgemmbatched", "xgemmstridedbatched" };
        const routines = level1_routines ++ level2_routines ++ level3_routines ++ levelx_routines;
        _ = routines;
        const precisions = &[_]usize{ 32, 64, 3232, 6464, 16 };
        _ = precisions;

        // # Sample programs
        // if(OPENCL)
        //     set(SAMPLE_PROGRAMS_CPP sgemm sgemm_batched dtrsm tuning_api)
        //     set(SAMPLE_PROGRAMS_C sasum samax dgemv sgemm haxpy cache)
        // if(NETLIB)
        //     set(SAMPLE_PROGRAMS_C ${SAMPLE_PROGRAMS_C} sgemm_netlib)
        // endif()
        // elseif(CUDA)
        //     set(SAMPLE_PROGRAMS_CPP daxpy_cuda sgemm_cuda)
        //     set(SAMPLE_PROGRAMS_C )
        // endif()

        // ==================================================================================================

        for (sources) |s| c.addSource(s);
        inline for (level1_routines) |r| {
            c.addSource("src/routines/level1/" ++ r ++ ".cpp");
            //set(HEADERS ${HEADERS} src/routines/level1/${ROUTINE}.hpp)
        }
        inline for (level2_routines) |r| {
            c.addSource("src/routines/level2/" ++ r ++ ".cpp");
            //set(HEADERS ${HEADERS} src/routines/level2/${ROUTINE}.hpp)
        }
        inline for (level3_routines) |r| {
            c.addSource("src/routines/level3/" ++ r ++ ".cpp");
            //set(HEADERS ${HEADERS} src/routines/level3/${ROUTINE}.hpp)
        }
        inline for (levelx_routines) |r| {
            c.addSource("src/routines/levelx/" ++ r ++ ".cpp");
            //set(HEADERS ${HEADERS} src/routines/levelx/${ROUTINE}.hpp)
        }
        inline for (databases) |d| {
            c.addSource("src/database/kernels/" ++ d ++ "/" ++ d ++ ".cpp");
            // set(HEADERS ${HEADERS} src/database/kernels/${DATABASE}/${DATABASE}.hpp)
            // set(HEADERS ${HEADERS} src/database/kernels/${DATABASE}/${DATABASE}_16.hpp)
            // set(HEADERS ${HEADERS} src/database/kernels/${DATABASE}/${DATABASE}_32.hpp)
            // set(HEADERS ${HEADERS} src/database/kernels/${DATABASE}/${DATABASE}_64.hpp)
            // set(HEADERS ${HEADERS} src/database/kernels/${DATABASE}/${DATABASE}_3232.hpp)
            // set(HEADERS ${HEADERS} src/database/kernels/${DATABASE}/${DATABASE}_6464.hpp)
        }
        // foreach(KERNEL ${KERNELS})
        // set(HEADERS ${HEADERS} src/tuning/kernels/${KERNEL}.hpp)
        // endforeach()

        lib.linkLibCpp();
        return res;
    }

    pub fn link(self: @This(), comp: *std.Build.CompileStep) void {
        comp.addIncludePath(.{ .path = self.build.pathJoin(&.{ thisPath(), "include" }) });
        comp.linkLibrary(self.lib);
    }

    const sources = &[_][]const u8{
        "src/database/database.cpp",
        "src/routines/common.cpp",
        "src/utilities/compile.cpp",
        "src/utilities/clblast_exceptions.cpp",
        "src/utilities/timing.cpp",
        "src/utilities/utilities.cpp",
        "src/api_common.cpp",
        "src/cache.cpp",
        "src/kernel_preprocessor.cpp",
        "src/routine.cpp",
        "src/routines/levelx/xinvert.cpp", // only source, don't include it as a test
        "src/tuning/configurations.cpp",
    };

    const headers: [][]const u8 = &.{
        "include/clblast_half.h",
        "src/database/apple_cpu_fallback.hpp",
        "src/database/database.hpp",
        "src/database/database_structure.hpp",
        "src/routines/level1/xamin.hpp",
        "src/routines/level1/xmax.hpp",
        "src/routines/level1/xmin.hpp",
        "src/routines/level1/xsum.hpp",
        "src/routines/common.hpp",
        "src/routines/routines.hpp",
        "src/utilities/buffer_test.hpp",
        "src/utilities/compile.hpp",
        "src/utilities/clblast_exceptions.hpp",
        "src/utilities/device_mapping.hpp",
        "src/utilities/msvc.hpp",
        "src/utilities/timing.hpp",
        "src/utilities/utilities.hpp",
        "src/cache.hpp",
        "src/kernel_preprocessor.hpp",
        "src/cxpp11_common.hpp",
        "src/routine.hpp",
        "src/tuning/configurations.hpp",
        "src/tuning/tuning.hpp",
        "src/tuning/routines/routine_tuner.hpp",
    };
};

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const open_cl = OpenCL.fromOCL(b, target) orelse @panic("Can't find OpenCL. Make sure its installed. But likely build script is not smart enough to find it. Find out where 'CL/cl.h' and stick it in here");
    const clblast = ClBlast.build(b, .{
        .target = target,
        .optimize = optimize,
        .backend = .{ .opencl = open_cl },
    });

    // build sample program
    const exe = b.addExecutable(.{ .name = "sasum.c" });
    exe.addCSourceFiles(&.{"samples/sasum.c"}, &.{});
    exe.linkLibC();
    open_cl.link(exe);
    clblast.link(exe);

    //b.installArtifact(open_cl.lib);
    b.installArtifact(exe);
}

fn thisPath() []const u8 {
    return std.fs.path.dirname(@src().file) orelse ".";
}
