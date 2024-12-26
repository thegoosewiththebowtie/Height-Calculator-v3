cmake_minimum_required(VERSION 3.19)
project(Height-Calculator-v3 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Height-Calculator-v3
    WIN32 MACOSX_BUNDLE
    res.qrc
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    heightprocessing.h heightprocessing.cpp heightprocessing.ui
    about.h about.cpp about.ui
)

target_link_libraries(Height-Calculator-v3
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Height-Calculator-v3
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Height-Calculator-v3
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
