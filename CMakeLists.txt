project(sdl_test)
cmake_minimum_required(VERSION 2.8.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(SOURCE_FILES main.cpp)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
#find_package(BOOST REQUIRED)

file(COPY ${sdl_test_SOURCE_DIR}/assets DESTINATION ${sdl_test_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} #[[${Boost_INCLUDE_DIRS}]])

add_executable(sdl_test ${SOURCE_FILES})
target_link_libraries(sdl_test ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
