#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
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
    std::vector<std::string> CarIDStores;

public:
    User(); // Default constructor
    // User(std::string uID, std::string uName, std::string pwd, std::string fName, std::string pNumber, std::string mail, std::string idT, std::string idNum);
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
    void setPassword(string newPassword);
    void setCreditPoint(int newCredit);
    //function
    void addCreditPoints(int points);
    // Function to get carpool info
    std::vector<std::string> getcarIDstores() const;
    void setCarIDToStore(std::string& carID) ;
};
#endif