#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef HGUARD2
#define HGUARD2

class UserController
{
    public:
        void registerUser(string uid, string uName, string pwd, string fName, 
                          string pNumber, string mail, string idT, string idNum);
        User *loginUser(string username, string password);
        void logoutUser(User *user);
        void manageProfile(User *user);
        void purchaseCredits(User *user, int amount);
        ~UserController();

}

#endif
