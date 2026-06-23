cmake_minimum_required(VERSION 3.20)
project(DKR_RECOMP C)

file(GLOB_RECURSE SOURCES "recomp_src/*.c")

include_directories(
    include
    recomp_src
)

add_executable(dkr_recomp ${SOURCES})