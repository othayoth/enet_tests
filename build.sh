g++ -w -Ofast -ffast-math -std=c++17 -o targets/server src/server.cpp -lenet -I/usr/local/include


g++ -w -Ofast -ffast-math -std=c++17 -o targets/client src/client.cpp -lenet -I/usr/local/include


g++ -w -Ofast -ffast-math -std=c++17 -o targets/fb_test src/flatbuff_test.cpp -lenet -I/usr/local/include  -I./third_party/flatbuffers/include
