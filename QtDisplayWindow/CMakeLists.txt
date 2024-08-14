
cmake_minimum_required(VERSION 3.1.3)
project(QtDisplayWindow)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets) 

file(GLOB INC ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB UI ${PROJECT_SOURCE_DIR}/src/*.ui)
add_executable(${PROJECT_NAME} ${INC} ${SRC} ${UI})
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)


set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
