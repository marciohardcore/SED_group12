#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

class User {
protected:
    std::string userName, password, fullName, phoneNumber, email, idType, idNumber;
    int creditPoint = 10;

public:
    // Constructor
    User(string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int credits)
        : userName(uName), password(pwd), fullName(fName), phoneNumber(pNumber), email(mail), idType(idT), idNumber(idNum), creditPoint(credits) {}

    //generate them cho no du theo cai format
    //
    save
    // Getters
    string getUserName() 
    { 
        return userName; 
    }
    string getPassword() 
    { 
        return password; 
    }
    string getFullName()
    {
        return fullName;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    string getEmail()
    {
        return email;
    }

    // Method to update the user profile
    void updateProfile(string newFullName, string newPhoneNumber, string newEmail) 
    {   
        fullName = newFullName;
        phoneNumber = newPhoneNumber;
        email = newEmail;
        cout << "Profile updated successfully.\n";
    }

    // Method to add credit points
    void addCreditPoints(int points) 
    {
        creditPoint += points;
        cout << points << " credit points added.\n";
    }

    // Getter for credit points
    int getCreditPoints() 
    {
        return creditPoint;
    }
};
