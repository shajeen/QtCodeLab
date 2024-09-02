cmake_minimum_required(VERSION 3.15)
project(QtDisplayWindow)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Qt's automated tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find necessary Qt components
find_package(QT NAMES Qt6 Qt5 REQUIRED CONFIG COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED CONFIG COMPONENTS Core Widgets)

# Gather source files
file(GLOB INC ${PROJECT_SOURCE_DIR}/src/*.h)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB UI ${PROJECT_SOURCE_DIR}/src/*.ui)

# Create the executable
add_executable(${PROJECT_NAME} ${INC} ${SRC} ${UI})

# Link Qt libraries to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core)


