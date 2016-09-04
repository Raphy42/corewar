cmake_minimum_required(VERSION 3.3)
project(Corewar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES vm/includes/vm.h vm/includes/op.h vm/srcs/ops/add.c vm/srcs/main.c vm/srcs/loop.c vm/srcs/error.c vm/includes/mnemonic.h vm/srcs/parse.c vm/includes/error.h vm/includes/parse.h vm/includes/utils.h vm/srcs/utils.c vm/srcs/init.c vm/srcs/options.c vm/includes/options.h vm/srcs/memory.c vm/srcs/decode.c)
add_executable(Corewar ${SOURCE_FILES})