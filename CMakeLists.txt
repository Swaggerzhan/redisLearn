cmake_minimum_required(VERSION 3.19)
project(redisLearn)

set(CMAKE_CXX_STANDARD 14)

add_executable(redisLearn main.cpp include/sds.h src/sds.cpp include/dict.h src/dict.cpp include/murmur2.h src/murmur2.cpp)