cmake_minimum_required(VERSION 3.5)

project(LibraryManagementSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        loginwindow.cpp
        loginwindow.h
        loginwindow.ui
        resource.qrc
        pin.cpp
        pin.h
        pin.ui
        authoritymainmenu.cpp
        authoritymainmenu.h
        authoritymainmenu.ui
        LibraryIssualRegister.txt
        LibraryAttendanceRegister.txt
        LibraryBooks.txt
        add.cpp
        add.h
        add.ui
        delete.cpp
        delete.h
        delete.ui
        attendance.cpp
        attendance.h
        attendance.ui
        studentmainmenu.cpp
        studentmainmenu.h
        studentmainmenu.ui
        checkinout.cpp
        checkinout.h
        checkinout.ui
        displaybooks.cpp
        displaybooks.h
        displaybooks.ui
        issue.cpp
        issue.h
        issue.ui
        returnback.cpp
        returnback.h
        returnback.ui
        displaylended.cpp
        displaylended.h
        displaylended.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LibraryManagementSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LibraryManagementSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LibraryManagementSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LibraryManagementSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LibraryManagementSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(LibraryManagementSystem PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS LibraryManagementSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LibraryManagementSystem)
endif()
