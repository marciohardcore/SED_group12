#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef USER_H
#define USER_H

#include <string>
using std::string;

class User {
private:
    string uid;
    string userName;
    string password;
    string fullName;
    string phoneNumber;
    string email;
    string idType;
    string idNumber;
    int creditPoint;  // New member variable
public:
    // Default constructor
    User();

    User(string uID, string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum);


    // Parameterized constructor
    User(string uID, string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int creditPoint);

    // Getter methods
    string getUID() const;
    string getUserName() const;
    string getPassword() const;
    string getFullName() const;
    string getPhoneNumber() const;
    string getEmail() const;
    string getIDtype() const;
    string getIDnum() const;
    // Getter for creditPoint
    int getCreditPoint() const;


};

#endif // USER_H
