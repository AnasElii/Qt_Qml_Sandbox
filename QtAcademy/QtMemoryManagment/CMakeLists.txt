cmake_minimum_required(VERSION 3.16)
project(QtMemoryManagment VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDRD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========= Set Directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# ===== Include Directories
include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})

# ========= Add Files in Directoris
file(GLOB_RECURSE SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${INCLUDE_DIR}/*.h"
)

# ========= Include Libraries
find_package(Qt6 COMPONENTS Core REQUIRED)
qt_standard_project_setup()

# ========= Add Executable
add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

# ========= Add Target Subdir
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)

# ========= Add Libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Core)
