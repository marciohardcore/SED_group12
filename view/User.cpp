#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "..\lib\User.h"


// Default constructor

// Default constructor
User::User() : creditPoint(10) {}

// Parameterized constructor
User::User(string uID, string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum)
    : uid(uID), userName(uName), password(pwd), fullName(fName), phoneNumber(pNumber), email(mail), idType(idT), idNumber(idNum), creditPoint(10) {}

// Getter methods implementation
string User::getUID() const { return uid; }
string User::getUserName() const { return userName; }
string User::getPassword() const { return password; }
string User::getFullName() const { return fullName; }
string User::getPhoneNumber() const { return phoneNumber; }
string User::getEmail() const { return email; }
string User::getIDtype() const { return idType; }
string User::getIDnum() const { return idNumber; }

// Getter for creditPoint
int User::getCreditPoint() const { return creditPoint; }



// Method to update the user profile
// void User::updateProfile(string newFullName, string newPhoneNumber, string newEmail)
// {

//     fullName = newFullName;
//     phoneNumber = newPhoneNumber;
//     email = newEmail;
//     cout << "Profile updated successfully.\n";
// }

// Method to add credit points
// void User::addCreditPoints(int points)
// {
//     creditPoint += points;
//     cout << points << " credit points added.\n";
// }
