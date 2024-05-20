# enet_tests

code snippets for initial enet tests

1. make build scripts for server and client using g++
2. use snippets from [here](http://enet.bespin.org/Tutorial.html#CreateServer) to make client and server


## notes

1. Generating flatbuffer files
- instead of installing binaries of `flatbuffer`, compile the specific version using `cmake` -- it will generate the `flatc` binary. to generate the command
- usually, there is a flatbuffer submodule under `third_party`
- build it using [these](https://github.com/google/flatbuffers?tab=readme-ov-file#quick-start) instructions
- generate code from a schema : `cd schema && ./parse_schema` -- this will generate `*_generated.h` files 
