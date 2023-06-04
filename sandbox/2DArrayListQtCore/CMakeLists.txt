cmake_minimum_required(VERSION 3.21)
project(QArrayList VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH $ENV{QTMINGWDIR})


set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(UI_DIR "${CMAKE_SOURCE_DIR}/interfaces")

include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${INTERFACES_DIR})

file(GLOB_RECURSE SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${INCLUDE_DIR}/*.h"
)

find_package(Qt6 COMPONENTS Core Sql REQUIRED)
qt_standard_project_setup()

qt6_add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${SOURCE_DIR})
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${UI_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Core Qt6::Sql)
