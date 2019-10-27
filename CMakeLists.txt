cmake_minimum_required(VERSION 3.6)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(BChest CXX)

include(ExternalProject)
find_package(Git REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Werror -fPIC")

ExternalProject_Add(
    catch2
    GIT_REPOSITORY      https://github.com/catchorg/Catch2
    GIT_TAG             v2.10.2
    PREFIX              ${CMAKE_SOURCE_DIR}/external
    CONFIGURE_COMMAND   ""
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
)
set(CATCH2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/src/catch2/single_include)

enable_testing()

add_subdirectory(lib)
