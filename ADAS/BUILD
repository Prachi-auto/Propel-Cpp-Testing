load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "adas_core",
    srcs = [
        "RelevantObjectsAcc.cpp",
        "RelevantObjectsAeb.cpp",
        "RelevantObjectsCommon.cpp",
    ],
    hdrs = [
        "LaneId.hpp",
        "Object.hpp",
        "ObjectList.hpp",
        "RelevantObjectsAcc.hpp",
        "RelevantObjectsAeb.hpp",
        "RelevantObjectsCommon.hpp",
    ],
    visibility = ["//visibility:public"],
    copts = ["-std=c++17"]
)
cc_binary(
    name = "dry",
    srcs = ["main.cpp"],
    deps = [":adas_core"],
)
