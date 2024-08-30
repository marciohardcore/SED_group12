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
            cout << "Login successful.\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
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


// // Method to purchase credits
// void UserController::purchaseCredits(User *userAmount, int amount)
// {
//     std::cout<<"Add creditpoint";

//     FileManager fileMana;
//     vector <User> users;
//     users = fileMana.loadUser();

//     bool userFound = false;
//     for (User user: users){
//         if (user.getUserName() == userAmount->getUserName()){
//             userAmount->addCreditPoints(amount);
//             break;
//         }
//     }
//     fileMana.saveAllUsers(users);

//     cout << "Credit point: " << user->getCreditPoints() << "\n";
//     fileMana.saveAllUsers(users);
// }

// Destructor to clean up user objects
// ~UserController()
// {
//     for (User *user : users)
//     {
//         delete user;
//     }
// }

