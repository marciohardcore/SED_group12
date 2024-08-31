#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h> 
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
void UserController::updateProfile(string username, string password) {
    FileManager fileMana;
    vector<User> users = fileMana.loadUser();
    bool userFound = false;

    while (true) {
        std::cout << YELLOW << "Choose the option you want to apply changes to:\n";
        std::cout << "1. Full name\n";
        std::cout << "2. Phone number\n";
        std::cout << "3. Email\n";
        std::cout << "4. Back\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        
        char choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character left in the input buffer

        // Handle invalid input
        while (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
            std::cout << RED << "Invalid input, please enter a number from 1 to 4\n" << RESET;
            std::cout << GREEN << "Enter your choice: " << RESET;
            std::cin >> choice;
            std::cin.ignore(); // Clear the newline character left in the input buffer
        }

        if (choice == '4') {
            return; // Exit the function to go back to the previous menu
        }

        if (choice == '1' || choice == '2' || choice == '3') {
            for (User& user : users) {
                if (user.getUserName() == username && user.getPassword() == password) {
                    userFound = true;
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

                    std::cout << GREEN << "Profile updated successfully!\n";
                    fileMana.saveAllUsers(users); // Save changes once after making updates
                    std::cout << "Press any key to continue...";
                    _getch(); // Wait for user to press any key
                    return; // Exit the function to go back to the previous menu
                }
            }

            if (!userFound) {
                std::cout << RED << "User not found or incorrect password\n" << RESET;
                std::cout << "Press any key to continue...";
                _getch(); // Wait for user to press any key
            }
        }
    }
}


#include <iostream>
#include <string>
#include <vector>
#include <conio.h>  // Include for _getch()

void UserController::updatePassword(string username, string password) {
    FileManager fileMana;
    vector<User> users = fileMana.loadUser();
    bool userFound = false;

    std::string oldPassword;
    std::string newPassword;

    std::cout << "\tUpdate Password\n";
    std::cout << "-----------------------------------\n";

    // Ask for the old password
    std::cout << YELLOW << "Enter old password: " << RESET;
    cin.ignore();
    std::getline(std::cin, oldPassword);

    for (User& user : users) {
        if (user.getUserName() == username && user.getPassword() == password) {
            userFound = true;

            // Validate the old password
            while (oldPassword != password) {
                std::cout << RED << "Invalid password, please try again: " << RESET;
                std::getline(std::cin, oldPassword);

                // Option to go back (e.g., if the user enters "4")
                if (oldPassword == "4") {
                    std::cout << "Returning to the previous menu...\n";
                    return;
                }
            }

            // Ask for the new password
            std::cout << GREEN << "Enter new password: " << RESET;
            std::getline(std::cin, newPassword);

            // Update the password
            user.setPassword(newPassword);
            std::cout << GREEN << "Password updated successfully!\n";
            
            // Save the updated user information
            fileMana.saveAllUsers(users);
            break;
        }
    }

    // if (!userFound) {
    //     std::cout << RED << "User not found or incorrect old password\n" << RESET;
    // }

    // Prompt to press any key to continue
    std::cout << "Press any key to continue...";
    _getch(); // Wait for the user to press any key
}

// // Method to purchase credits
void UserController::purchaseCredits(User userAmount, int amount) {
    std::cout << "Adding credit points...\n";

    FileManager fileMana;
    vector<User> users = fileMana.loadUser();

    bool userFound = false;
    for (User& user : users) {
        if (user.getUserName() == userAmount.getUserName()) {
            user.addCreditPoints(amount);
            userFound = true;
            break;
        }
    }

    if (userFound) {
        std::cout << GREEN << "Credits added successfully!\n" << RESET;
        fileMana.saveAllUsers(users); // Save updated user data to the file
    } else {
        std::cout << RED << "User not found!\n" << RESET;
    }

    // Prompt to press any key to continue
    std::cout << "Press any key to continue...";
    _getch(); // Wait for user to press any key
}
// Destructor to clean up user objects
// ~UserController()
// {
//     for (User *user : users)
//     {
//         delete user;
//     }
// }

