
// =================================================================================================
// This file is part of the CLBlast project. The project is licensed under Apache Version 2.0. It
// is auto-generated by the 'scripts/database/database.py' Python script.
//
// This file populates the database with best-found tuning parameters for the 'Xgemm_Direct6464' kernels.
//
// =================================================================================================

namespace clblast {
namespace database {

const DatabaseEntry XgemmDirectComplexDouble = {
  "XgemmDirect", Precision::kComplexDouble, {"KWID", "MDIMAD", "MDIMCD", "NDIMBD", "NDIMCD", "PADA", "PADB", "VWMD", "VWND", "WGD"}, {
    { // AMD GPUs
      kDeviceTypeGPU, "AMD", {
        { "Ellesmere", {
          { Name{"AMD Radeon RX 480                                 "}, Params{ 16, 32, 32, 16, 8, 0, 0, 1, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"AMD Radeon RX 580 2048SP                          "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"AMD Radeon RX590 GME                              "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "Fiji", {
          { Name{"AMD Radeon R9 Fury X                              "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"AMD Radeon R9 M370X Compute Engine                "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "Hawaii", {
          { Name{"AMD FirePro W8100                                 "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "Tonga", {
          { Name{"AMD Radeon R9 380                                 "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "default", {
          { Name{"AMD Radeon Pro 450 Compute Engine                 "}, Params{ 2, 8, 16, 16, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"AMD Radeon Pro 580 Compute Engine                 "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1010:xnack-", {
          { Name{"AMD Radeon RX 5700                                "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"AMD Radeon RX 5700 XT                             "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1030", {
          { Name{"AMD Radeon RX 6800 XT                             "}, Params{ 16, 8, 16, 8, 8, 0, 0, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"AMD Radeon RX 6900 XT                             "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1031", {
          { Name{"AMD Radeon RX 6700 XT                             "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1032", {
          { Name{"AMD Radeon RX 6600 XT                             "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1034", {
          { Name{"AMD Radeon RX 6500 XT                             "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1035", {
          { Name{"AMD Radeon Graphics                               "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 2, 2, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1100", {
          { Name{"Radeon RX 7900 XTX                                "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1101", {
          { Name{"AMD Radeon RX 7800 XT                             "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1102", {
          { Name{"AMD Radeon RX 7600                                "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx1103", {
          { Name{"AMD Radeon 780M Graphics                          "}, Params{ 16, 32, 32, 8, 8, 1, 0, 1, 4, 32, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 16, 32, 32, 8, 8, 1, 0, 1, 4, 32, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx902", {
          { Name{"AMD Radeon(TM) Graphics                           "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"AMD Radeon(TM) RX Vega 10 Graphics                "}, Params{ 2, 8, 8, 16, 16, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx906:sramecc+:xnack-", {
          { Name{"AMD Radeon VII                                    "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "gfx90c", {
          { Name{"AMD Radeon(TM) Graphics                           "}, Params{ 2, 16, 16, 16, 16, 0, 0, 2, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
        } },
      }
    },
    { // ARM GPUs
      kDeviceTypeGPU, "ARM", {
        { "default", {
          { Name{"Mali-T760                                         "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
      }
    },
    { // Intel CPUs
      kDeviceTypeCPU, "Intel", {
        { "default", {
          { Name{"Intel(R) Core(TM) i7-2670QM CPU @ 2.20GHz         "}, Params{ 2, 8, 8, 32, 8, 0, 0, 1, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Core(TM) i5-4570 CPU @ 3.20GHz           "}, Params{ 2, 16, 16, 8, 8, 0, 0, 1, 4, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Core(TM) i5-4590S CPU @ 3.00GHz          "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 4, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz          "}, Params{ 2, 8, 8, 8, 8, 0, 0, 2, 2, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Core(TM) i7 CPU         920  @ 2.67GHz   "}, Params{ 8, 16, 16, 8, 8, 0, 0, 2, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Core(TM) i7-4790K CPU @ 4.00GHz          "}, Params{ 8, 16, 8, 8, 8, 0, 0, 2, 2, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Core(TM) i7-6770HQ CPU @ 2.60GHz         "}, Params{ 2, 32, 8, 8, 8, 0, 0, 1, 4, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Core(TM) i9-9980HK CPU @ 2.40GHz         "}, Params{ 2, 8, 32, 32, 8, 0, 0, 1, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Xeon(R) CPU E5-2630 v3 @ 2.40GHz         "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) Xeon(R) CPU E5-2630 v4 @ 2.20GHz         "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
      }
    },
    { // Intel GPUs
      kDeviceTypeGPU, "Intel", {
        { "default", {
          { Name{"Intel(R) HD Graphics 620                          "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Intel(R) UHD Graphics 620                         "}, Params{ 2, 16, 8, 16, 16, 0, 0, 2, 2, 32, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
      }
    },
    { // NVIDIA GPUs
      kDeviceTypeGPU, "NVIDIA", {
        { "SM2.0", {
          { Name{"GeForce GTX 580                                   "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM3.0", {
          { Name{"GeForce GTX 760 Ti OEM                            "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM3.5", {
          { Name{"GeForce 920A                                      "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"GeForce GTX TITAN Black                           "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce GT 730                             "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM5.0", {
          { Name{"GeForce 920MX                                     "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"GeForce GTX 750 Ti                                "}, Params{ 2, 32, 32, 8, 8, 1, 1, 1, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"Quadro M2000M                                     "}, Params{ 2, 32, 32, 8, 8, 1, 1, 1, 4, 32, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM5.2", {
          { Name{"GeForce GTX 970                                   "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM6.0", {
          { Name{"Tesla P100-PCIE-16GB                              "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM6.1", {
          { Name{"GeForce GTX 1070 Ti                               "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"GeForce GTX 1080                                  "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"GeForce GTX 1080 Ti                               "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce GTX 1060 6GB                       "}, Params{ 8, 16, 32, 16, 16, 1, 1, 1, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce MX150                              "}, Params{ 16, 16, 32, 8, 8, 1, 0, 1, 4, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"TITAN X (Pascal)                                  "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"Tesla P4                                          "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM7.0", {
          { Name{"Quadro GV100                                      "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"Tesla V100-PCIE-16GB                              "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 16, 16, 8, 8, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM7.5", {
          { Name{"GeForce GTX 1650                                  "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce GTX 1650 SUPER                     "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce GTX 1650 Ti                        "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 2060                           "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 2070 SUPER                     "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 2070 Super                     "}, Params{ 2, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 2070 with Max-Q Design         "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 2080 Ti                        "}, Params{ 2, 32, 32, 16, 16, 1, 1, 1, 2, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 2080 with Max-Q Design         "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"Quadro T2000                                      "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"TITAN RTX                                         "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"Tesla T4                                          "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM8.0", {
          { Name{"A100-PCIE-40GB                                    "}, Params{ 16, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 16, 16, 16, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM8.6", {
          { Name{"NVIDIA GeForce RTX 3050 Ti Laptop GPU             "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 3060 Laptop GPU                "}, Params{ 2, 16, 16, 8, 8, 1, 1, 1, 2, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 3070                           "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 3070 Ti Laptop GPU             "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 3080                           "}, Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 3080 Laptop GPU                "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 3080 Ti                        "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 3090                           "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA RTX A6000                                  "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "SM8.9", {
          { Name{"NVIDIA GeForce RTX 4060                           "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 4060 Ti                        "}, Params{ 2, 16, 8, 8, 16, 1, 1, 2, 2, 32, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 4070 Laptop GPU                "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 4070 Ti                        "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 4080                           "}, Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
          { Name{"NVIDIA GeForce RTX 4090                           "}, Params{ 2, 8, 8, 16, 16, 1, 1, 1, 1, 16, 0, 0, 0, 0, 0, 0 } },
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
        { "default", {
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 } },
        } },
      }
    },
    { // Default
      kDeviceTypeAll, "default", {
        { "default", {
          { kDeviceNameDefault                                        , Params{ 2, 8, 8, 8, 8, 1, 1, 2, 1, 16, 0, 0, 0, 0, 0, 0 } },
        } },
      }
    },
  }
};

} // namespace database
} // namespace clblast
