#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "User.h"
#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
using namespace std;

#ifndef HGUARD2
#define HGUARD2
class UserController
{
    public:
        void registerUser(string uid, string uName, string pwd, string fName, 
                          string pNumber, string mail, string idT, string idNum);
        bool loginUser(string username, string password);
        void updateProfile(string username, string password);
        void updatePassword(string username, string password);
        // void logoutUser(User *user);
        void purchaseCredits(const User &userAmount, int amount);
        // ~UserController();
        
};
#endif
