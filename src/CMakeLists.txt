cmake_minimum_required(VERSION 3.13)  # CMake version check
project(AES128)                       # Create project "AES128"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable targets
add_executable(aes_128_decrypt aes_128_decrypt.cpp)
add_executable(aes_128_common aes_128_common.cpp)
add_executable(aes_128_key_expansion aes_128_key_expansion.cpp)
add_executable(aes_128_encrypt aes_128_encrypt.cpp)