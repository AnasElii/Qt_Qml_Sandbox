cmake_minimum_required(VERSION 3.21.1)

project(qml-cpp-example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(WIN32)
    set(CMAKE_PREFIX_PATH $ENV{QTMSVCDIR})
ENDIF()

find_package(Qt6 COMPONENTS Quick REQUIRED)

qt_add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
)

qt6_add_qml_module(${CMAKE_PROJECT_NAME}
    URI QmlCppExample
    VERSION 1.0

    # QMl Files
    QML_FILES
    main.qml

    # Qml Resources
    RESOURCES
    assets/circular-saw.gif
    assets/built-with-qt-badge.png
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE Qt6::Quick
)

install(TARGETS ${CMAKE_PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
