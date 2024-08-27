#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

#include "..\lib\InputValidator.h"
using namespace std;

// Console text formatting
#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

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
}

// Guest view function
void viewCarpoolListings(){
    std::cout << BOLD << "Active Carpool Listings:\n" << RESET;
    std::cout << "----------------------------------\n";
    // GuestView::displayCarpoolDetails(); xong roi ma chua connect file voi nhau
}

// void viewBookings() {
//     std::cout << BOLD << "Active Bookings:\n" << RESET;
//     std::cout << "----------------------------------\n";
//     // GuestView::displayBookingDetails(); chua lam
// }


// Profile management function
void profileManagement() {
    std::cout << YELLOW << "Profile Management\n";
    std::cout << "1. View Profile\n";
    std::cout << "2. Update Profile\n";
    std::cout << "3. Update Password\n";
    std::cout << "4. Add Credit Point\n" << RESET;
}


void passengerUtils(){
    char choice;
    std::cout << BOLD << "\t \t Login as \n" << /*User::getName() <<*/ RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Options:\n1. Account Management\n2. Booking\n3. Add credit point\n4. Log out" << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 4\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    if (choice == '1') {
        profileManagement();
        // UserController::manageProfile();
    } else if (choice == '2') {
        // User::Member::Booking();
    } else if (choice == '3') {
        // Addcreditpoint();
        // UserController::purchaseCredits();
    } else if (choice == '4') {
        // Logout();
        // UserController::logoutUser();
    }
}

void passenger(){
    std::string username, password;
    //log in
    std::cout << BOLD << "\t \t Login\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;
    // switch to login user , if ok then go to options
    // if (UserController::loginUser(username, password) == true){
    //     std::cout << "Login successfully";
    //     system("pause");
    //     passengerUtils();
    // }
    std::cout << "wrong username or password, please try again";
    system("pause");
}

void driverUtils(){
    char choice;
    std::cout << BOLD << "Driver\n" << RESET;
    std::cout << YELLOW << "Options:\n1. List Carpool\n2. Unlist Carpool\n3. View Request\n4. View Rating\n" << RESET;
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3' && choice != '4') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 4\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    system("pause");

    if (choice == '1') {
        //CarpoolController::createCarpool();
    } else if (choice == '2') {
        //CarpoolController::unlistCarpool();
    } else if (choice == '3') {
        //CarpoolController::viewRequest();        
    } else if (choice == '4') {
        //CarpoolController::viewRating();        
    }
}

void driver(){
    std::string username, password;
    //log in
    std::cout << BOLD << "\t \t Login as Driver\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;
    // switch to login user , if ok then go to options
    // if (DriverController::loginDriver(username, password) == true){
    //     std::cout << "Login successfully";
    //     system("pause");
    //     driverUtils();
    // }
    std::cout << "wrong username or password, please try again";
    system("pause");
}


// Member options function
void memberOption() {
    char choice;
    std::cout << BOLD << "Member\n" << RESET;
    std::cout << YELLOW << "Options:\n1. Passenger\n2. Driver\n" << RESET;
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 2\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    system("pause");

    if (choice == '1') {
        passenger();
    } else if (choice == '2') {
        driver();
    }
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

    //UserController::registerUser(username, password, fullName, phoneNumber, email, IDtype, passportNumber);
    std::cout << "Register complete\n";
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
        viewCarpoolListings();
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

    system("pause");

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
