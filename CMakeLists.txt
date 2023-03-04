cmake_minimum_required(VERSION 3.5)

project(phase_difference LANGUAGES CXX)



if(UNITTEST)
	add_subdirectory(googletests/)
endif()

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network PrintSupport)
add_subdirectory(TestTask/libs/qcustomplot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    qcustomplot
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Network
    Qt5::PrintSupport
    )

