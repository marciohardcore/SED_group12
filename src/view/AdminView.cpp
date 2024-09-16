#include <iostream>
#include <vector>
#include <conio.h> // For Windows _getch()
#include "..\lib\AdminView.h"
#include "..\lib\FileManager.h"
#include "..\lib\User.h"
#include "..\lib\CarpoolListing.h"

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

// Method to display all users' information
void AdminView::displayAllUsers() {
    FileManager fileManager;
    std::vector<User*> users = fileManager.loadUser();
    std::vector<RatingSystem*> ratings = fileManager.loadRating();
    std::cout << "Information of all Users:\n";
    std::cout << "-----------------------------------\n";
    int userIndex = 1;
    
    for (const auto& user : users) {
        double totalScore = 0;
        int count = 0;
        std::string allComments;
        std::string Uid = user->getUID();

        for (const auto& rating : ratings) {
            if (rating->getUserID() == Uid) {
                totalScore += rating->getScore(); // Add score to total
                count++; // Increment the count of ratings
                if (!allComments.empty()) {
                    allComments += ", "; // Add a comma before adding the next comment
                }
                allComments += rating->getComments(); // Append the comment
            }
        }
        std::cout << GREEN << "INFORMATION OF USER " << userIndex++ << RESET <<"\n";
        std::cout << YELLOW << "User ID: " << user->getUID() << "\n"
                  << "Username: " << user->getUserName() << "\n"
                  << "Password: " << user->getPassword() << "\n"   
                  << "Full Name: " << user->getFullName() << "\n"
                  << "Phone Number: " << user->getPhoneNumber() << "\n"
                  << "Email: " << user->getEmail() << "\n"
                  << "ID type: " << user->getIDtype() << "\n"
                  << "ID num: " << user->getIDnum() << "\n"
                  << "Credit Points: " << user->getCreditPoint() << "\n";
        if (count > 0) {
            double averageScore = totalScore / count;
            std::cout << "Average Score: " << averageScore << "\n";
            std::cout << "Comments: " << allComments << "\n";
        } else {
            std::cout << "No ratings available for this user.\n";
        }
        std::cout << "-----------------------------------\n";
    }
    std::cout << GREEN << "\nPress any key to continue..." << RESET;
    _getch(); // Wait for user to press any key before returning to the menu
    for (auto& user : users) {
        delete user; // Deallocate each User object
    }
}

// Method to display all carpool listings' information
void AdminView::displayAllCarpools() {
    // Load all carpool listings from the file
    FileManager fileManager;
    std::vector<CarpoolListing*> carpools = fileManager.loadCarpoolListing();
    std::cout << "Information of all Carpools: \n";
    std::cout << "-----------------------------------\n";
    
    for (size_t i = 0; i < carpools.size(); ++i) {
        const auto& carpool = carpools[i];
        std::cout << GREEN << "INFORMATION OF CARPOOL " << (i + 1) << RESET << "\n"
                  << YELLOW << "Available Seats: " << carpool->getAvailableSeats() << "\n"
                  << "Departure Time: " << carpool->getDepartureTime() << "\n"
                  << "Departure Location: " << carpool->getDepartureLocation() << "\n"
                  << "Destination Location: " << carpool->getDestinationLocation() << "\n"
                  << "Vehicle Color: " << carpool->getVehicleColor() << "\n"
                  << "Vehicle Model: " << carpool->getVehicleModel() << "\n"
                  << "Vehicle Plate Number: " << carpool->getPlateNumber() << "\n" 
                  << "Date: " << carpool->getDate() << "\n"
                  << "Minimum Passenger Rating: " << carpool->getMinimumPassengerRating() << "\n"
                  << "Contribution Per Passenger: " << carpool->getContributionPerPassenger() << "\n"
                  << "-----------------------------------\n";
    }

    std::cout << GREEN << "\nPress any key to continue..." << RESET;
    _getch(); // Wait for user input before returning to the menu
}
