cmake_minimum_required(VERSION 3.10)
project(JsonParser)

set(CMAKE_CXX_STANDARD 11)

add_executable(JsonParser main.cpp)

# Add the path to rapidjson
target_include_directories(JsonParser PRIVATE /path/to/rapidjson/include)
