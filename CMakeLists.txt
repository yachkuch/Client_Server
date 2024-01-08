cmake_minimum_required(VERSION 3.20.1)
project(Client_Server VERSION 0.1.0 LANGUAGES C CXX)

#Функция прерывания 
function(exit_cmake)
  message("Прерывание настройки")
  if(UNIX)
    set(KILL_COMMAND "killall")
    execute_process(COMMAND ${KILL_COMMAND} -9 cmake
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    )
  else()
    set(KILL_COMMAND "taskkill")
    execute_process(COMMAND ${KILL_COMMAND} /IM cmake.exe /F
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    )
  endif()
endfunction(exit_cmake)

#Подключение тестов 
include(CTest)

# find_package(GTest REQUIRED)
# if(GTest_FOUND)
#   message("Тесты найдены")
#   include(GoogleTest)
#   #include_directories(${GTEST_INCLUDE_DIR})
# endif()

enable_testing()

include_directories(include)
include_directories(Serv)

# cmake_policy(SET CMP0074 NEW)
# set(Boost_DEBUG ON)
# find_package(Boost REQUIRED)
# if (Boost_FOUND)
#   include_directories( ${Boost_INCLUDE_DIRS})
    add_executable(Client_Server main.cpp)
    set_target_properties(Client_Server PROPERTIES CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON)
# else()
#     exit_cmake()
# endif()

# if(MSVC)
#     target_compile_options(Test_ci_cd PRIVATE /W4)
# else()
#     target_compile_options(Test_ci_cd PRIVATE
#     -Wall -Wextra -pedantic
#     )
# endif()

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