cmake_minimum_required(VERSION 3.21)
project(QGuiApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(Qt_SSL_Backend "openssl")

# ========= Set directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# ========= Include directories
include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})

# ========= Add directories files
file(GLOB_RECURSE SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${INCLUDE_DIR}/*.h"
)

# ========= Include libraries
find_package(Qt6 COMPONENTS Gui Quick Positioning Location Network REQUIRED)

# ========= Add executable
qt_add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

# ========= Set Resources
set(RESOURCE_DIR
    "resource/imgs/Profile.jpg"
)

# ========= Add qml medule
qt_add_qml_module(${CMAKE_PROJECT_NAME}
    URI mainLib
    VERSION 1.0
    QML_FILES
    interfaces/main.qml
    components/myButton.qml
    RESOURCES
    ${RESOURCE_DIR}
)

# ========= Cnfigure Android package
if(ANDROID)
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    set_property(TARGET QGuiApp PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR ${ANDROID_PACKAGE_SOURCE_DIR})
    add_custom_target(cmake_android_package
        SOURCES
        ${ANDROID_PACKAGE_SOURCE_DIR}/AndroidManifest.xml
        ${ANDROID_PACKAGE_SOURCE_DIR}/build.gradle
        ${ANDROID_PACKAGE_SOURCE_DIR}/grable.properties
        ${ANDROID_PACKAGE_SOURCE_DIR}/res/values/libs.xml
    )

    include(D:/Dev/Dev/android_openssl/CMakeLists.txt)
endif()

# ========= Link target subDirectories
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC src)
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC include)

# ========= Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE Qt6::Gui
    Qt6::Quick
    Qt6::Positioning
    Qt6::Location
    Qt6::Network
)