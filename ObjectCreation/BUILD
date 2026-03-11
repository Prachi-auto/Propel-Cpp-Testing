load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_google_protobuf//bazel:cc_proto_library.bzl", "cc_proto_library")
load("@rules_cc//cc:defs.bzl", "cc_binary")

# Proto library for object_type
proto_library(
    name = "object_type_proto",
    srcs = ["object_type.proto"],
)

# C++ proto library for object_type
cc_proto_library(
    name = "object_type_cc_proto",
)

# Proto library for radar_object
proto_library(
    name = "radar_object_proto",
    srcs = ["radar_object.proto"],
    deps = [":object_type_proto"],
)

# C++ proto library for radar_object
cc_proto_library(
    name = "radar_object_cc_proto",
    deps = [":radar_object_proto"],
)

# Binary target for radar_object_creator
cc_binary(
    name = "radar_object_creator",
    srcs = ["radar_object_creator.cpp"],
)
