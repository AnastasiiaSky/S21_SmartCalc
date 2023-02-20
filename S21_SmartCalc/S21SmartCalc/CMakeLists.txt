cmake_minimum_required(VERSION 3.5)

project(S21SmartCalc VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#find_package(Qt6 REQUIRED COMPONENTS Charts)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        graf.cpp
        graf.h
        graf.ui

        s21_creditcalc.cpp
        s21_creditcalc.h
        s21_creditcalc.ui

        ../s21_additional_fanctions.c
        ../s21_calculation_proc.c
        ../s21_polish_notation.c
        ../s21_string_parser.c
        ../s21_string_validation.c
        ../s21_credit_calc.c
        ../s21_calc.h

         qcustomplot.h
         qcustomplot.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(S21SmartCalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET S21SmartCalc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(S21SmartCalc SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(S21SmartCalc
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(S21SmartCalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#target_link_libraries(S21SmartCalc PRIVATE Qt${QT_VERSION_MAJOR}::Charts)

set_target_properties(S21SmartCalc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(S21SmartCalc)
endif()
