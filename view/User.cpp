#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "..\lib\User.h"



// Default constructor
User::User() : uid(""), userName(""), password(""), fullName(""), phoneNumber(""), email(""), idType(""), idNumber(""), creditPoint(10) {}

// Parameterized constructor
User::User(std::string uID, std::string uName, std::string pwd, std::string fName, std::string pNumber, std::string mail, std::string idT, std::string idNum)
    : uid(uID), userName(uName), password(pwd), fullName(fName), phoneNumber(pNumber), email(mail), idType(idT), idNumber(idNum), creditPoint(10) {}

// Parameterized constructor with credit point
User::User(std::string uID, std::string uName, std::string pwd, std::string fName, std::string pNumber, std::string mail, std::string idT, std::string idNum, int creditPointVal)
    : uid(uID), userName(uName), password(pwd), fullName(fName), phoneNumber(pNumber), email(mail), idType(idT), idNumber(idNum), creditPoint(creditPointVal) {}

// Getter methods implementation
std::string User::getUID() const { return uid; }
std::string User::getUserName() const { return userName; }
std::string User::getPassword() const { return password; }
std::string User::getFullName() const { return fullName; }
std::string User::getPhoneNumber() const { return phoneNumber; }
std::string User::getEmail() const { return email; }
std::string User::getIDtype() const { return idType; }
std::string User::getIDnum() const { return idNumber; }
int User::getCreditPoint() const { return creditPoint; }

void User::setFullName(string newFullName){this->fullName = newFullName; }
void User::setPhoneNumber(string newPhoneNumber){this->phoneNumber = newPhoneNumber; }
void User::setEmail(string newEmail){this->email = newEmail; }
void User::setPassword(string newPassword){this->password = newPassword;}
// Method to update the user profile
// Method to add credit points
void User::addCreditPoints(int points)
{
    this->creditPoint += points;
}

// Function implementations
void User::addCarpoolInfo(const std::string& carpoolID, const std::string& plateNumber) {
    carpoolInfo[carpoolID] = plateNumber;
}

string User::getCarpoolInfo(const std::string& carpoolID) const {
    auto it = carpoolInfo.find(carpoolID);
    if (it != carpoolInfo.end()) {
        return it->second;
    } else {
        return "Carpool not found";
    }
}

void User::removeCarpoolInfo(const std::string& carpoolID) {
    carpoolInfo.erase(carpoolID);
}
