#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\UserView.h"
#include "..\lib\User.h"
#include "..\lib\FileManager.h"


// Constructor that calls the User constructor

UserView::UserView(std::string name, std::string password)
    : User("",name, password, "", "", "", "", "", 0) {

}

// Method to view the user profile

void UserView::displayUserProfile( std::string name,  std::string password) {
    FileManager userManager;
    User* user = userManager.loadSingleUser(name, password);

    std::cout << "User Profile:\n";
    std::cout << "Username: " << user->getUserName() << "\n";
    std::cout << "Status: " << GREEN <<"Verified" << "\n" << RESET;    
    std::cout << "Full Name: " << user->getFullName() << "\n";
    std::cout << "Phone Number: " << user->getPhoneNumber() << "\n";
    std::cout << "Email: " << user->getEmail() << "\n";
    std::cout << "Credit Points: " << user->getCreditPoint() << "\n";
    std::cout << "-----------------------------------\n";
    delete user;
}
