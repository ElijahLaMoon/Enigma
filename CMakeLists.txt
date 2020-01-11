cmake_minimum_required(VERSION 3.5)

project(enigma)

set(SOURCE main.cpp Enigma.cpp Rotor.cpp Reflector.cpp Plugboard.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})