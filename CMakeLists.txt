cmake_minimum_required(VERSION 3.16)

project(RubikTeacher VERSION 3.3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Xml Network OpenGLWidgets Multimedia MultimediaWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Xml Network OpenGLWidgets Multimedia MultimediaWidgets)

set(TS_FILES rubik_fr.ts)

file(GLOB_RECURSE PROJECT_SOURCES
     CONFIGURE_DEPENDS
     "*.h" "*.hpp" "*.cpp" "*.ui")

qt_add_executable(RubikTeacher
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    ${TS_FILES}
    ressources.qrc
)

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

target_link_libraries(RubikTeacher PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Xml
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::OpenGLWidgets
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
    opengl32
)

target_include_directories(RubikTeacher PRIVATE
    ${CMAKE_SOURCE_DIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RubikTeacher)
endif()
