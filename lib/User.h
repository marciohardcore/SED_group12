#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class User
{
protected:
    string uid, userName, password, fullName, phoneNumber, email, idType, idNumber;
    int creditPoint = 10;
    int ratingScore = -1;

public:
    // Constructor
    User(){};
    User(string uID, string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int credits, int rScore)
        : uid(uID), userName(uName), password(pwd), fullName(fName), phoneNumber(pNumber), email(mail), idType(idT), idNumber(idNum), creditPoint(credits), ratingScore(rScore) {}

    // Method to update the user profile
    void updateProfile(string newFullName, string newPhoneNumber, string newEmail)
    // Method to add credit points
    void addCreditPoints(int points)
    // Getters
    string getUID()
    string getUserName()
    string getPassword()
    string getFullName()
    string getPhoneNumber()
    string getEmail()
    string getIDtype()
    string getIDnum()
    int getCreditPoints()
    int getRatingScore()
    
};
