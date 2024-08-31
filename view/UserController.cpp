#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\User.h"
#include "..\lib\UserController.h"
#include "..\lib\FileManager.h"

// Method to register a user
void UserController::registerUser(string uid, string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum) 
{
    User user1(uid, uName, pwd, fName, pNumber, mail, idT, idNum);
    FileManager file_mana;
    file_mana.saveUser(user1);
}

// Method to login a user
bool UserController::loginUser(string username, string password)
{
    FileManager fileMana;
    vector <User> users;
    users = fileMana.loadUser();
    for (User user : users)
    {
        if (user.getUserName() == username && user.getPassword() == password)
        {
            return true;
        }
    }
    cout << RED << "Invalid username or password!.\n";
    return false;
}

// // Method to logout a user
// void UserController::logoutUser(User *user)
// {
//     if (user)
//     {
//         cout << "User " << user->getUserName() << " logged out successfully.\n";
//     }
//     else
//     {
//         cout << "You have not logged in.\n";
//     }
// }

// Method to manage a user's profile
void UserController::updateProfile(string username, string password)
{
    FileManager fileMana;
    vector<User> users = fileMana.loadUser();
    bool userFound = false;

    for (User& user : users) {
        if (user.getUserName() == username && user.getPassword() == password) {
            userFound = true;
            std::cout << "Updating profile\n";
            std::cout << "-----------------------------------\n";
            std::cout << YELLOW << "Where do you want to apply changes: 1. Full name\t2. Phone number\t3. Email\n" << RESET;
            char choice;
            std::cin >> choice;
            std::cin.ignore(); // Ignore the newline character left in the input buffer

            while (choice != '1' && choice != '2' && choice != '3') {
                std::cout << RED << "Invalid input, please enter a number from 1 to 3\n" << RESET;
                std::cout << GREEN << "Enter your choice: " << RESET;
                std::cin >> choice;
                std::cin.ignore(); // Ignore the newline character left in the input buffer
            }

            string newFullName, newPhoneNumber, newEmail;

            switch (choice) {
                case '1':
                    std::cout << "Enter new full name: ";
                    getline(std::cin, newFullName);
                    user.setFullName(newFullName);
                    break;
                case '2':
                    std::cout << "Enter new phone number: ";
                    getline(std::cin, newPhoneNumber);
                    user.setPhoneNumber(newPhoneNumber);
                    break;
                case '3':
                    std::cout << "Enter new email: ";
                    getline(std::cin, newEmail);
                    user.setEmail(newEmail);
                    break;
            }
            break;
        }
    }

    if (userFound) {
        fileMana.saveAllUsers(users);
        std::cout << "Change information successfully\n";
    } else {
        std::cout << RED << "User not found or incorrect password\n" << RESET;
    }
}

void UserController::updatePassword(string username, string password){
    FileManager fileMana;
    vector<User> users = fileMana.loadUser();
    bool userFound = false;

    std::string oldPassword;
    std::cout << "\tUpdate password\n";
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Enter old password: " << RESET;
 
    std::getline(std::cin, oldPassword);

    for (User& user : users) {
        if (user.getUserName() == username && user.getPassword() == password) {
            userFound = true;
            
            std::string newPassword;
            while (oldPassword != password) {
                std::cout << RED << "Invalid password, please try again: " << RESET;
                std::getline(std::cin, oldPassword);
            }

            //if (oldPassword == '4'){ go back}
            std::cout << GREEN << "Enter new password: \n" << RESET;
            std::getline(std::cin, newPassword);

            //change password
            user.setPassword(newPassword);
        }

        if (userFound) {
            fileMana.saveAllUsers(users);
            std::cout << "Change password successfully\n";
            break;
        }
    }
    if (userFound == false){
        std::cout << "User not found | UserController::updatePassword";
    }

}
// // Method to purchase credits
void UserController::purchaseCredits(User userAmount, int amount)
{
    std::cout<<"Add creditpoint";

    FileManager fileMana;
    vector <User> users;
    users = fileMana.loadUser();

    bool userFound = false;
    for (User& user: users){
        if (user.getUserName() == userAmount.getUserName()){
            user.addCreditPoints(amount);
            cout << "Credit point: " << userAmount.getCreditPoint() << "\n";
            break;
        }
    }
    fileMana.saveAllUsers(users);

}

// Destructor to clean up user objects
// ~UserController()
// {
//     for (User *user : users)
//     {
//         delete user;
//     }
// }

