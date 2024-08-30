#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "User.h"
using namespace std;

#ifndef HGUARD2
#define HGUARD2
class UserController
{
    public:
        void registerUser(string uid, string uName, string pwd, string fName, 
                          string pNumber, string mail, string idT, string idNum);
        bool loginUser(string username, string password);
        // void logoutUser(User *user);
        void updateProfile(User *user);
        void purchaseCredits(User *user, int amount);
        // ~UserController();

};
#endif
