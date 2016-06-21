# Bazel (http://bazel.io) BUILD file for musicpp (http://github.com/pdbartlett/musicpp).

cc_library(
  name = "musicpp",
  hdrs = glob(["*.h"]),
  srcs = glob(["*.cc"], exclude = ["main.cc"]),
)

cc_binary(
  name = "demoapp",
  srcs = ["main.cc"],
  deps = [":musicpp"],
)
