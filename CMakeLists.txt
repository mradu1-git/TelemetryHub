cmake_minimum_required(VERSION 3.16)

project(TelemetryHub VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appTelemetryHub
    main.cpp
)

qt_add_qml_module(appTelemetryHub
    URI com.company.telemetry
    QML_FILES
        Main.qml
        SOURCES devicecontroller.h devicecontroller.cpp
        SOURCES dataencryptor.h dataencryptor.cpp
        SOURCES statuspiechart.h statuspiechart.cpp
        SOURCES telemetrylogmodel.h telemetrylogmodel.cpp
        SOURCES logfilterproxymodel.h logfilterproxymodel.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTelemetryHub PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTelemetryHub
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTelemetryHub
    PRIVATE Qt6::Quick
)

install(TARGETS appTelemetryHub
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
