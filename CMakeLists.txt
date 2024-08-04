cmake_minimum_required(VERSION 3.16)

project(obs-recording-overlay VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Quick Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Quick Widgets)

set(PROJECT_SOURCES
    main.cpp
    src/overlayapp.cpp
    src/overlayapp.h
    assets/images/obs-recording-overlay-logo.png
    assets/images/paused-icon.png
    assets/images/record-icon.png
)

set(QML
    # cmake-format: sort
    qml/Overlay/Overlay.qml
    themes/Theme.qml
    qml/main.qml
)

set(RESOURCES
    # cmake-format: sort
    resources/qml.qrc
    resources/resources.qrc
    themes/qmldir
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(obs-recording-overlay
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        ${QML}
        ${RESOURCES}
    )

    qt_add_qml_module(obs-recording-overlay
        URI
        obs-recording-overlay
        RESOURCE_PREFIX
        /qml
        QML_FILES
        ${QML}
        RESOURCES
        ${RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET obs-recording-overlay APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(obs-recording-overlay SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(obs-recording-overlay
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(obs-recording-overlay PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Quick)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.obs-recording-overlay)
endif()
set_target_properties(obs-recording-overlay PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS obs-recording-overlay
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(obs-recording-overlay)
endif()
