# cmake_minimum_required(VERSION 3.5)
# 
# project(enigma)
# 
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# 
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 
# add_executable(enigma main.cpp Enigma.cpp Rotor.cpp)
# ----------------------------------------------------
cmake_minimum_required(VERSION 3.5)

project(enigma)

set(SOURCE main.cpp Enigma.cpp Rotor.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})