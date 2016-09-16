cmake_minimum_required(VERSION 3.3)
project(Corewar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES vm/includes/vm.h vm/includes/op.h vm/srcs/ops/add.c
        vm/srcs/ops/aff.c
        vm/srcs/ops/and.c
        vm/srcs/ops/fork.c
        vm/srcs/ops/ld.c
        vm/srcs/ops/ldi.c
        vm/srcs/ops/lfork.c
        vm/srcs/ops/live.c
        vm/srcs/ops/lld.c
        vm/srcs/ops/lldi.c
        vm/srcs/ops/or.c
        vm/srcs/ops/st.c
        vm/srcs/ops/sti.c
        vm/srcs/ops/sub.c
        vm/srcs/ops/xor.c
        vm/srcs/ops/zjmp.c
        vm/srcs/main.c vm/srcs/loop.c vm/srcs/error.c vm/includes/mnemonic.h vm/srcs/parse.c vm/includes/error.h vm/includes/parse.h vm/includes/utils.h vm/srcs/utils.c vm/srcs/init.c vm/srcs/options.c vm/includes/options.h vm/srcs/memory.c vm/srcs/decode.c vm/includes/loop.h vm/includes/decode.h vm/srcs/fetch.c)
add_executable(Corewar ${SOURCE_FILES})

include_directories(libft/includes)
include_directories(vm/includes)