load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "adas_core",
    srcs = [
        "RelevantObjectsAcc.cpp",
        "RelevantObjectsAeb.cpp",
    ],
    hdrs = [
        "LaneId.hpp",
        "Object.hpp",
        "ObjectList.hpp",
        "RelevantObjectsAcc.hpp",
        "RelevantObjectsAeb.hpp",
    ],
    visibility = ["//visibility:public"],
)
cc_binary(
    name = "dry",
    srcs = ["main.cpp"],
    deps = [":adas_core"],
)