#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string uid;
    std::string userName;
    std::string password;
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string idType;
    std::string idNumber;
    int creditPoint;
public:
    User(); // Default constructor
    User(std::string uID, std::string uName, std::string pwd, std::string fName, std::string pNumber, std::string mail, std::string idT, std::string idNum);
    User(std::string uID, std::string uName, std::string pwd, std::string fName, std::string pNumber, std::string mail, std::string idT, std::string idNum, int creditPointVal);
    
    // Getter methods
    std::string getUID() const;
    std::string getUserName() const;
    std::string getPassword() const;
    std::string getFullName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getIDtype() const;
    std::string getIDnum() const;
    int getCreditPoint() const;

    //Setter methods
    void setFullName (string newFullName);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
};
#endif