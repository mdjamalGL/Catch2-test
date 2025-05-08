cmake_minimum_required(VERSION 3.15)
project(catch2_test LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/generators")

find_package(Catch2 REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(fakeit REQUIRED)


add_executable(app main.cpp session.cpp)
target_link_libraries(app PRIVATE nlohmann_json::nlohmann_json)

add_executable(tests test.cpp session.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nlohmann_json::nlohmann_json fakeit::fakeit)
target_compile_definitions(tests PRIVATE TESTING)

include(CTest)
include(Catch)
catch_discover_tests(tests)
