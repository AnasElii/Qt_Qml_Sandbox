cmake_minimum_required(VERSION 3.21)
project(QmlToSql VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_AUTOMOC ON)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH $ENV{QTMINGWDIR})


set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${INCLUDE_DIR}/*.h"
)

find_package(Qt6 COMPONENTS Gui Quick Sql REQUIRED)

qt6_add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})


qt6_add_qml_module(${CMAKE_PROJECT_NAME}
    URI Main
    VERSION 1.0.0
    QML_FILES
        interface/main.qml
        components/MyButton.qml
)

target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${SOURCE_DIR})
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${UI_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Quick Qt6::Sql)
