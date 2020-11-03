set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    controller_test.cpp
    robot_test.cpp
    userinterface_test.cpp
    ../app/controller.cpp
    ../app/robot.cpp
    ../app/userinterface.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest)
