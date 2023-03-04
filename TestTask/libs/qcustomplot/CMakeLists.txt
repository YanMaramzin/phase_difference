cmake_minimum_required(VERSION 3.0)
project(qcustomplot)

file(GLOB_RECURSE  SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME})

set_target_properties( qcustomplot PROPERTIES AUTOMOC TRUE )
target_link_libraries( qcustomplot Qt5::Widgets Qt5::Network )

include("unittest.cmake")
