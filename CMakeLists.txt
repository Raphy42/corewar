cmake_minimum_required(VERSION 3.3)
project(Corewar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES vm/includes/vm.h vm/includes/op.h vm/srcs/ops/add.c vm/srcs/main.c vm/srcs/loop.c vm/srcs/error.c)
add_executable(Corewar ${SOURCE_FILES})