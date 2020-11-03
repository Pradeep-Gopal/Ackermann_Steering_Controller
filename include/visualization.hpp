// Copyright (c) 2020 Govind Ajith Kumar, Justin Albrecht, Pradeep Gopal

#pragma once
#include <userinterface.hpp>

/**
 * @brief      This class helps visualize if the controller converges
 * 				to the set goal
 */
class Visualization{
 public:
    static void show(double, double, double, UserInterface&);
};
