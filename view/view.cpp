#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

#include "..\lib\InputValidator.h"
#include "..\lib\IDgenerator.h"
#include "..\lib\FileManager.h"

#include "..\lib\User.h"
#include "..\lib\UserView.h"
#include "..\lib\UserController.h"



using namespace std;

// Console text formatting
#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
char coordinate();
void printHeader(const std::string& title) {
    std::cout << BOLD << "\t \t " << title << "\n" << RESET;
}

// Introduction function
void introduction() {
    std::cout << BOLD << "\t \t SOFTWARE ENGINEERING DESIGN\n" << RESET;
    std::cout << BOLD << "\t \t Carpool Listing Application\n" << RESET;
    std::cout << RED << "Instructor:" << BLUE << " Huo Chong Ling, Dr. Jeff Nijsse\n";
    std::cout << RED << "Group:" << BLUE << " 12\n";
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "s4026694" << GREEN << " Le Nguyen Khuong Duy\n";
    std::cout << YELLOW << "s4040269" << GREEN << " Vu Van Tuan\n";
    std::cout << YELLOW << "s4038329" << GREEN << " Tran Thanh Lam\n";
    std::cout << YELLOW << "s3999159" << GREEN << " Tran Tu Tam\n";
    std::cout << "\n" << RESET;
    system("pause");
    system("cls"); 
}

// Guest view function
// void viewCarpoolListings(){
//     std::cout << BOLD << "Active Carpool Listings:\n" << RESET;
//     std::cout << "----------------------------------\n";
//     // GuestView::displayCarpoolDetails(); // xong roi ma chua connect file voi nhau
// }

// void viewBookings() {
//     std::cout << BOLD << "Active Bookings:\n" << RESET;
//     std::cout << "----------------------------------\n";
//     // GuestView::displayBookingDetails(); chua lam
// }


// Profile management function
void profileManagement(std::string username, std::string password) {
    while (true) {
        system("cls"); // Clear the screen
        printHeader("Carpool Listing Application");
        std::cout << "-----------------------------------\n";
        std::cout << BOLD << "Log in as " << username << "\n" << RESET;
        std::cout << "-----------------------------------\n";
        
        std::cout << YELLOW << "Profile Management\n";
        std::cout << "-----------------------------------\n";
        std::cout << YELLOW << "Enter an option below:\n";
        std::cout << "1. View Profile\n";
        std::cout << "2. Update Profile\n";
        std::cout << "3. Update Password\n";
        std::cout << "4. Back\n";
        std::cout << "-----------------------------------\n";
        std::cout << GREEN << "Enter your choice: " << RESET;
        
        char choice;
        std::cin >> choice;
        // Handle the valid choice
        if (choice == '1') {
            UserView userInfo(username, password);
            std::cout << "Viewing profile...\n";
            std::cout << "-----------------------------------\n";
            userInfo.displayUserProfile(username, password);
            std::cout << "Press any key to continue...";
            _getch(); // Wait for user to press any key
        } else if (choice == '2') {
            std::cout << "Updating profile...\n";
            // updateProfile(username, password);
        } else if (choice == '3') {
            std::cout << "Updating password...\n";
            // updatePassword(username, password);
        } else if (choice == '4') {
            return; // Exit profile management and return to the previous menu
        } else {
            std::cout << RED << "Invalid input, please enter a number from 1 to 4\n" << RESET;
            std::cout << "Press any key to continue...";
            _getch(); // Wait for user to press any key
        }
    }
}


// CarpoolManagement function
void CarpoolManagement(std::string username, std::string password) {
    while (true) {
        system("cls"); // Clear the screen
        printHeader("Carpool Listing Application");
        std::cout << "-----------------------------------\n";
        std::cout << BOLD << "Log in as " << username << "\n" << RESET;
        std::cout << "-----------------------------------\n";
        
        std::cout << YELLOW << "Carpool Management\n";
        std::cout << "-----------------------------------\n";
        std::cout << YELLOW << "Enter an option below:\n";
        std::cout << "1. Create Carpool\n";
        std::cout << "2. Update Carpool\n";
        std::cout << "3. View Requests\n";
        std::cout << "4. View Ratings\n";
        std::cout << "5. Back\n"; // Added option to go back to the previous menu
        std::cout << "-----------------------------------\n";
        std::cout << GREEN << "Enter your choice: " << RESET;
        
        char choice;
        std::cin >> choice;

        // Validate user input and handle the valid choice
        if (choice == '1') {
            std::cout << "Creating a new carpool...\n";
            // UserController::createCarpool();
        } else if (choice == '2') {
            std::cout << "Updating an existing carpool...\n";
            // UserController::updateCarpool();
        } else if (choice == '3') {
            std::cout << "Viewing requests...\n";
            // UserController::viewRequests();
        } else if (choice == '4') {
            std::cout << "Viewing ratings...\n";
            // UserController::viewRatings();
        } else if (choice == '5') {
            // Return to the previous menu
            return; // Exit the function and return to the calling function
        } else {
            std::cout << RED << "Invalid input, please enter a number from 1 to 5\n" << RESET;
            std::cout << "Press any key to continue...";
            _getch(); // Wait for user to press any key
        }
    }
}


// memberUtils function
void memberUtils(std::string username, std::string password) {
    char choice;
    while (true) {
        system("cls"); // Clear the screen before printing the menu
        printHeader("Carpool Listing Application");
        std::cout << "-----------------------------------\n";
        // Display options
        std::cout << BOLD << "Log in as " << username << "\n" << RESET;
        std::cout << "-----------------------------------\n";
        std::cout << YELLOW << "Enter an option below:\n";
        std::cout << "1. Account Management\n";
        std::cout << "2. Carpool Management\n";
        std::cout << "3. Browser\n";
        std::cout << "4. View My Rating\n";
        std::cout << "5. Logout\n";
        std::cout << "-----------------------------------\n";

        // Prompt user for choice
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;

        // Validate user input
        if (choice >= '1' && choice <= '5') {
            switch (choice) {
                case '1':
                    profileManagement(username, password);
                    system("cls"); // Clear the screen after returning from profileManagement
                    break;
                case '2':
                    system("cls");
                    CarpoolManagement(username, password);
                    break;
                case '3':
                    std::cout << "Opening browser...\n";
                    // Example: browseListings();
                    break;
                case '4':
                    std::cout << "Viewing rating...\n";
                    // Example: viewMyRating(username);
                    break;
                case '5':
                    std::cout << "Logging out...\n";
                    return; // Exit the loop and the function
            }
        } else {
            std::cout << RED << "Invalid input, please enter a number from 1 to 5\n" << RESET;
            std::cout << "Press any key to continue...";
            _getch(); // Wait for user to press any key
        }
    }
}


// member function
void member(){
    std::string username, password;
    inputValidator input;
    // //log in
    // // std::cout << BOLD << "\t \t Login as Member\n" << RESET;
    // // std::cout << "-----------------------------------\n";
    std::cout << "Enter username: ";
    getline(cin, username);
    // //input.inputValidator::validateUsername(username);

    std::cout << "Enter password: ";
    getline(cin, password);
    //input.inputValidator::validatePassword(password);

    // switch to login user , if ok then go to options
    // login;
    // while (login.UserController::loginUser(username, password) == false){
    //     std::cout << "wrong username or password, please try again\n";
    // }

    //Assume that log-in sucess
    std::cout << GREEN << "Login successfully!\n";
    system("pause");
    system("cls");
    memberUtils(username, password);
    // //Test
    // system("pause");
}




// Member options function
void memberOption() {
    char choice;
    
    std::cout << BOLD << "\t \t Member\n" << RESET;
    std::cout << "-----------------------------------\n";
    
    // Prompt to press Enter to proceed
    std::cout << "Press Enter to log in as a Member...";
    std::cin.ignore(); // To ignore any leftover newline characters in the buffer
    std::cin.get(); // Waits for the user to press Enter

    member(); // Call the member function to handle the login and subsequent options
}




void newRegister() {
    std::string username, password, fullName, phoneNumber, email, IDtype, passportNumber;
    inputValidator input;

    std::cout << BOLD << "\t \t Register New User \n" << RESET;
    std::cout << "-----------------------------------\n";
    
    std::cin.ignore();
    std::cout << GREEN << "Enter your username: " << RESET;
    std::getline(std::cin, username);
    input.inputValidator::validateUsername(username);

    std::cout << GREEN << "Enter your password: " << RESET;
    std::getline(std::cin, password);
    input.inputValidator::validatePassword(password);

    std::cout << GREEN << "Enter your full name: " << RESET;
    std::getline(std::cin, fullName);
    input.inputValidator::validateFullName(fullName);

    std::cout << GREEN << "Enter your phone number: " << RESET;
    std::getline(std::cin, phoneNumber);  // Use getline to handle spaces in phone number if any
    input.inputValidator::validatePhoneNumber(phoneNumber);

    std::cout << GREEN << "Enter your email: " << RESET;
    std::getline(std::cin, email);  // Use getline to handle spaces in email if any
    input.inputValidator::validateEmail(email);

    std::cout << GREEN << "Enter your ID type (e.g., Passport, National ID): " << RESET;
    std::getline(std::cin, IDtype);
    input.inputValidator::validateIDType(IDtype);

    std::cout << GREEN << "Enter your passport number: " << RESET;
    std::getline(std::cin, passportNumber);
    input.inputValidator::validatePassportNumber(passportNumber);


    UserController regis;
    IDgenerator id_obj;
    std::string ans = id_obj.generateUserID();
    regis.UserController::registerUser(ans, username, password, fullName, phoneNumber, email, IDtype, passportNumber);
    std::cout << GREEN <<"\n\nRegister complete!\n";
    std::cout << "Press any key to continue...";
    _getch(); // Wait for user to press any key
    system("cls"); // Clear the screen
    
    // Return to coordinate screen
    coordinate();
    //Quit
}


// Guest options function
void guestOption() {
    char choice;
    std::cout << BOLD << "\t \t Guest\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Enter an option below:\n";
    std::cout << "1. Register\t2. View Carpool Listings\n";
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 2\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    if (choice == '1') { 
        newRegister();
    } else if (choice == '2') { // DONE
        //viewCarpoolListings();
    }
}

// Coordinate function to select user type
char coordinate() {
    char choice;
    std::cout << BOLD << "\t \t Carpool Listing Application\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Use the app as: 1. Guest\t2. Member\t3. Admin\n";
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 3\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    //system("pause");
    //system("cls"); // Clear the console screen
    if (choice == '1') {
        guestOption();
    } else if (choice == '2') {
        memberOption();
    } else if (choice == '3') {
        //admin();
    }

    return choice;
}


// Main function
int main() {
    system("cls");

    // Welcome scene
    introduction();

    // Guest, user, admin selection
    coordinate();

    return 0;
}
