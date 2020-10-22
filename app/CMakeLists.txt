add_executable(shell-app main.cpp robot.cpp controller.cpp userinterface.cpp visualization.cpp analysis.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
