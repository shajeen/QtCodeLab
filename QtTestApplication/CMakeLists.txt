
cmake_minimum_required(VERSION 3.1.3)
project(QtTestApplication)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find necessary Qt components
find_package(QT NAMES Qt6 Qt5 REQUIRED CONFIG COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED CONFIG COMPONENTS Core Widgets)

file(GLOB INC ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB UI ${PROJECT_SOURCE_DIR}/src/*.ui)
add_executable(${PROJECT_NAME} ${INC} ${SRC} ${UI})
target_link_libraries(QtTestApplication Qt6::Widgets)


set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
