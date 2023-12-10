cmake_minimum_required(VERSION 3.0.1)
project(Client_Server VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
enable_testing()
include_directories(include)
include_directories(Serv)

add_executable(Client_Server main.cpp)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
 


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)

message(STATUS ${PROJECT_VERSION})


project ("server")
project("client")

# Включите подпроекты.
add_subdirectory ("server")
add_subdirectory("client")