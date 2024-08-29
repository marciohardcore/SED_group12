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
    void User::updateProfile(string newFullName, string newPhoneNumber, string newEmail)
    {

        fullName = newFullName;
        phoneNumber = newPhoneNumber;
        email = newEmail;
        cout << "Profile updated successfully.\n";
    }

    // Method to add credit points
    void User::addCreditPoints(int points)
    {
        creditPoint += points;
        cout << points << " credit points added.\n";
    }

    // Getters
    string User::getUID()
    {
        return uid;
    }
    string User::getUserName()
    {
        return userName;
    }
    string User::getPassword()
    {
        return password;
    }
    string User::getFullName()
    {
        return fullName;
    }
    string User::getPhoneNumber()
    {
        return phoneNumber;
    }
    string User::getEmail()
    {
        return email;
    }
    string User::getIDtype()
    {
        return idType;
    }
    string User::getIDnum()
    {
        return idNumber;
    }
    int User::getCreditPoints()
    {
        return creditPoint;
    }
    int User::getRatingScore()
    {
        return ratingScore;
    }
};
