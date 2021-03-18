cmake_minimum_required(VERSION 3.13)  # CMake version check
project(AES128)                       # Create project "AES128"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp include/aes_128_common.h include/aes_128_decrypt.h include/aes_128_encrypt.h include/aes_128_key_expansion.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(AES128 ${SOURCE_FILES})
add_subdirectory (include)
add_subdirectory (src)
