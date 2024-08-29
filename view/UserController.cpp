#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\User.h"
#include "..\lib\UserController.h"
#include "..\lib\FileManager.h"

//registerUser: save data to .dat + 
void UserController::registerUser(string uid, string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum)
{
    User user1(uid, uName, pwd, fName, pNumber, mail, idT, idNum, 10, -1);

    FileManager file_mana;
    file_mana.saveUser(user1);
    cout << "Registered successfully!\n";
}

// // Method to login a user
// User *UserController::loginUser(string username, string password)
// {
//     for (User *users : user)
//     {
//         if (users->getUserName() == username && users->getPassword() == password)
//         {
//             cout << "Login successful.\n";
//             return users;
//         }
//     }
//     cout << "Invalid username or password.\n";
//     return nullptr;
// }

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

// // Method to manage a user's profile
// void UserController::manageProfile(User *user)
// {
//     if (user)
//     {
//         string newFullName, newPhoneNumber, newEmail;

//         cin.ignore(); // Clear the input buffer completely

//         cout << "Enter new full name: ";
//         getline(cin, newFullName); // Use getline to get the full name with spaces

//         cout << "Enter new phone number: ";
//         getline(cin, newPhoneNumber); // Use getline to get the phone number

//         cout << "Enter new email: ";
//         getline(cin, newEmail); // Use getline to get the email

//         user->updateProfile(newFullName, newPhoneNumber, newEmail);
//     }
//     else
//     {
//         cout << "You have not logged in.\n";
//     }
// }

// // Method to purchase credits
// void UserController::purchaseCredits(User *user, int amount)
// {
//     if (user)
//     {
//         user->addCreditPoints(amount);
//         cout << "Credit point: " << user->getCreditPoints() << "\n";
//     }
//     else
//     {
//         cout << "You have not logged in.\n";
//     }
// }

// Destructor to clean up user objects
// ~UserController()
// {
//     for (User *user : users)
//     {
//         delete user;
//     }
// }

