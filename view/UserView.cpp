#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\UserView.h"
#include "..\lib\User.h"
#include "..\lib\FileManager.h"


// Constructor that calls the User constructor
// UserView(string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int credits)
//     : User(uName, pwd, fName, pNumber, mail, idT, idNum, credits) {};

UserView::UserView(std::string name, std::string password)
    : User("",name, password, "", "", "", "", "", 0) {

}

// Method to view the user profile
void UserView::displayUserProfile( std::string name,  std::string password) {
    FileManager userManager;
    User user = userManager.loadSingleUser(name, password);

    std::cout << "User Profile:\n";
    std::cout << "Username: " << user.getUserName() << "\n";
    std::cout << "Full Name: " << user.getFullName() << "\n";
    std::cout << "Phone Number: " << user.getPhoneNumber() << "\n";
    std::cout << "Email: " << user.getEmail() << "\n";
    std::cout << "Credit Points: " << user.getCreditPoint() << "\n";
    std::cout << "-----------------------------------\n";
}


