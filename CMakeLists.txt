# 设置cmake最低版本要求为3.5
cmake_minimum_required(VERSION 3.5)

# 定义项目名称为keyboard_test
# 版本0.1，语言为C++
project(
    keyboard_test
    VERSION 0.1
    LANGUAGES CXX
)

# Qt的项目需要有这三行，来确保Qt相关的功能正常
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置Qt大版本为6，导入Widgets模块
find_package(
    QT NAMES Qt6
    REQUIRED COMPONENTS
    Widgets
)
find_package(
    Qt${QT_VERSION_MAJOR}
    REQUIRED COMPONENTS
    Widgets
)

# 设置项目所有源文件
set(
    PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    注释模板.cpp
)

# 设置输出可执行文件的文件名为keyboard_test
qt_add_executable(
    keyboard_test
    ${PROJECT_SOURCES}
    lineedit.h lineedit.cpp
)

# 设置可执行文件的链接库
target_link_libraries(
    keyboard_test
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)

