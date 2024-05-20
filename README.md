# enet_tests

code snippets for initial enet tests

1. make build scripts for server and client using g++
2. use snippets from [here](http://enet.bespin.org/Tutorial.html#CreateServer) to make client and server


## notes

#### Generating flatbuffer files
- instead of installing binaries of `flatbuffer`, compile the specific version using `cmake` -- it will generate the `flatc` binary. to generate the command
- usually, there is a flatbuffer submodule under `third_party`
- build it using [these](https://github.com/google/flatbuffers?tab=readme-ov-file#quick-start) instructions
- generate code from a schema : `cd schema && ./parse_schema` -- this will generate `*_generated.h` files 
- if you need a mutating flatbuffer, use the `--gen-mutable` flag after calling the executable


#### how are fb sent to and forth between two programs using enet?
- 1. robot_signal_builder (struct) : has flatbufferbuilder, enet_server, and an enet_peer
- 2. send_signal (method): to either build a new buffer or mutate an existing buffer and sennd a packet over enet
- the pointer to the robot_signal_build can be passed to other threads that can then then call the send_signal methods when needed to send the buffer to enet peers. 
- these, along with enet operations, can be packaged into a `network_base.h` header file