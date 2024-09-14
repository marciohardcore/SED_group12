#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\User.h"

#ifndef USER_VIEW
#define USER_VIEW

class UserView : public User{
public:
    // Constructor that calls the User constructor
    UserView(string name, string password);
    // Method to view the user profile
    void displayUserProfile( std::string name,  std::string password);
};

#endif