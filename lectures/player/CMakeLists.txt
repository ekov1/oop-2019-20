cmake_minimum_required(VERSION 3.0.0)
project(player VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

add_executable(player main.cpp player.cpp hero.cpp
                      superhero.cpp ai.cpp bot.cpp
                      boss.cpp ../common/named.cpp)

include_directories(../common)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
