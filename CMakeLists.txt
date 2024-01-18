cmake_minimum_required(VERSION 3.28)
project(hello_qml VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

execute_process(
    COMMAND conan install ${CMAKE_SOURCE_DIR} --build=missing --output-folder=${CMAKE_BINARY_DIR} -s build_type=Debug
)

find_package(Qt6 COMPONENTS Core Gui Widgets  REQUIRED)
qt_standard_project_setup()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
    COMMAND "${WINDEPLOYQT_EXECUTABLE}" "$<TARGET_FILE:${PROJECT_NAME}>"
    COMMENT "Running windeployqt..."
)
