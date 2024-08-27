#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <InputValidator.h>
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
    std::cout << YELLOW << "s4026694" << GREEN << " Vu Van Tuan\n";
    std::cout << YELLOW << "s4026694" << GREEN << " Tran Thanh Lam\n";
    std::cout << YELLOW << "s4026694" << GREEN << " Tran Tu Tam\n";
    std::cout << "\n" << RESET;
    system("pause");
}

// Guest view function
void viewCarpoolListings(){
    std::cout << BOLD << "Active Carpool Listings:\n" << RESET;
    std::cout << "----------------------------------\n";
    // GuestView::displayCarpoolDetails(); briefly, can check parameter

}

void viewBookings() {

    std::cout << BOLD << "Active Bookings:\n" << RESET;
    std::cout << "----------------------------------\n";
    // GuestView::displayBookingDetails(); chua lam
}


// Profile management function
void profileManagement() {
    std::cout << YELLOW << "Profile Management\n";
    std::cout << "1. View Profile\n";
    std::cout << "2. Update Profile\n";
    std::cout << "3. Update Password\n";
    std::cout << "4. Add Credit Point\n" << RESET;
}


void userUtils(){
    char choice;
    std::cout << BOLD << "\t \t Login as \n" << /*User::getName() <<*/ RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Options:\n1. Profile Management\n2. Booking\n3. Add credit point\n4. Log out" << RESET;
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
    // if (UserController::loginUser(username, password) == true){
    //     userUtils();
    // }
    std::cout << "wrong username or password, please try again";
    system("pause");
}

void driver(){
    char choice;
    std::cout << BOLD << "Driver\n" << RESET;
    std::cout << YELLOW << "Options:\n1. List Carpool\n2. Unlist Carpool\n3. Quit\n" << RESET;
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 3\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    system("pause");

    if (choice == '1') {
        //CarpoolController::createCarpool();
    } else if (choice == '2') {
        driver();
    } else if (choice == '3') {
        // Admin();
    }

}
// Member options function
void memberOption() {
    char choice;
    std::cout << BOLD << "Member\n" << RESET;
    std::cout << YELLOW << "Options:\n1. Passenger\n2. Driver\n3. Admin\n" << RESET;
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 3\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    system("pause");

    if (choice == '1') {
        passenger();
    } else if (choice == '2') {
        driver();
    } else if (choice == '3') {
        // Admin();
    }
}



void newRegister(){
    std::string username, password, fullName, phoneNumber, email, IDtype, passportNumber;

    std::cout << BOLD << "\t \t Register New User \n" << RESET;
    std::cout << "-----------------------------------\n";

    std::cout << GREEN << "Enter your username: " << RESET;
    std::cin >> username;
    //inputValidator::validateUsername(username);

    std::cout << GREEN << "Enter your password: " << RESET;
    std::cin >> password;
    //inputValidator::validatePassword(password);

    std::cout << GREEN << "Enter your full name: " << RESET;
    std::cin.ignore(); 
    std::getline(std::cin, fullName);
    //inputValidator::validateFullName;  chua lam


    std::cout << GREEN << "Enter your phone number: " << RESET;
    std::cin >> phoneNumber;
    //inputValidator::validatePhoneNumber(phoneNumber);

    std::cout << GREEN << "Enter your email: " << RESET;
    std::cin >> email;
    //inputValidator::validatePhoneNumber;  chua lam

    std::cout << GREEN << "Enter your ID type (e.g., Passport, National ID): " << RESET;
    std::cin.ignore();
    std::getline(std::cin, IDtype);

    std::cout << GREEN << "Enter your passport number: " << RESET;
    std::cin >> passportNumber;

    //UserController::registerUser(username, password, fullName, phoneNumber, email, IDtype, passportNumber);
}
// Guest options function
void guestOption() {
    char choice;
    std::cout << BOLD << "\t \t Guest\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Enter an option below:\n";
    std::cout << "1. Register\t2. View Carpool Listings\t3. View Bookings\n";
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3') {
        std::cout << RED << "Invalid input, please enter a number from 1 to 3\n" << RESET;
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;
    }

    if (choice == '1') { 
        newRegister();
    } else if (choice == '2') { // DONE
        viewCarpoolListings();
    } else if (choice == '3') { // DONE
        viewBookings();
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
