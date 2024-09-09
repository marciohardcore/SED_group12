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
#include "..\lib\GuestView.h"

#include "..\lib\CarpoolController.h"
#include "..\lib\CarpoolListing.h"

#include "..\lib\member.h"

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

// Profile management function
void profileManagement(const std::string& username, const std::string& password) {
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
        std::cout << "4. Purchase credit\n";
        std::cout << "5. Back\n";
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
            std::cout << "-----------------------------------\n";
            UserController userControl;
            userControl.updateProfile(username, password);
            // CAN NOT CLEAR ALL CONTENT IN THE DATA FILE
        } else if (choice == '3') {
            UserController userControl;
            userControl.updatePassword(username, password);
        } else if (choice == '4'){
            int amount = 0;
            std::cout << "Purchase Credit...\n";
            std::cout << "-----------------------------------\n";
            std::cout << "Add the amount you want to deposit: \n";
            std::cin >> amount;
            User newCredit;
            FileManager userCredits;
            newCredit = userCredits.loadSingleUser(username, password);
            UserController userControl;
            userControl.purchaseCredits(newCredit, amount);
        } else if (choice == '5') {
            return; // Exit profile management and return to the previous menu
        } else {
            std::cout << RED << "Invalid input, please enter a number from 1 to 4\n" << RESET;
            std::cout << "Press any key to continue...";
            _getch(); // Wait for user to press any key
        }
    }
}


// CarpoolManagement function
void CarpoolManagement(const std::string& username, const std::string& password) {
    FileManager filemanager;
    User user = filemanager.loadSingleUser(username, password);
    CarpoolController call;
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
        std::cout << "2. View Carpool\n";
        std::cout << "3. Unlist Carpool\n";
        std::cout << "4. View Requests\n";
        std::cout << "5. View Ratings\n";
        std::cout << "6. Back\n"; // Added option to go back to the previous menu
        std::cout << "-----------------------------------\n";
        std::cout << GREEN << "Enter your choice: " << RESET;
        
        char choice;
        std::cin >> choice;

        // Validate user input and handle the valid choice
        if (choice == '1') {
            std::cout << "Creating a new carpool\n";
            call.createCarpool(user);
        } else if (choice == '2') {
            std::cout << "View carpool\n";
            // Call the method to view carpool listings
            call.viewCarpool(user); // Pass the user or necessary parameters
        } else if (choice == '3') {
            std::cout << "Unlist carpool\n";
            //CarpoolController::unlistCarpool();
            call.unlistCarpool(user);
        } else if (choice == '4') {
            std::cout << "Viewing requests\n";
            call.viewRequest(user);
            // CarpoolController::viewRequests();
        } else if (choice == '5') {
            std::cout << "Viewing ratings...\n";
            // CarpoolController::viewRatings();
        } else if (choice == '6') {
            // Return to the previous menu
            return; // Exit the function and return to the calling function
        } else {
            std::cout << RED << "Invalid input, please enter a number from 1 to 5\n" << RESET;
            std::cout << "Press any key to continue...";
            _getch(); // Wait for user to press any key
        }
    }
}
void showAllCarpoolListings(){
    // Load all carpool listings from the file
     FileManager fileManager;
        std::vector<CarpoolListing> carpools = fileManager.loadCarpoolListing();
    // Iterate through each carpool and display its details
        std::cout << "Information of all Carpools: \n";
        std::cout << "-----------------------------------\n";
        for (size_t i = 0; i < carpools.size(); ++i) {
            const auto& carpool = carpools[i];
            std::cout << GREEN << "INFORMATION OF CARPOOL " << (i + 1) << "\n"
                    << "Available Seats: " << carpool.getAvailableSeats() << "\n"
                    << "Departure Time: " << carpool.getDepartureTime() << "\n"
                    << "Departure Location: " << carpool.getDepartureLocation() << "\n"
                    << "Destination Location: " << carpool.getDestinationLocation() << "\n"
                    << "Vehicle Color: " << carpool.getVehicleColor() << "\n"
                    << "Vehicle Model: " << carpool.getVehicleModel() << "\n"
                    << "Vehicle PlateNumber: " << carpool.getPlateNumber() << "\n" 
                    << "Date: " << carpool.getDate() << "\n"
                    << "Minimum Passenger Rating: " << carpool.getMinimumPassengerRating() << "\n"
                    << "Contribution Per Passenger: " << carpool.getContributionPerPassenger() << "\n"
                    << "-----------------------------------\n";
        }
}
void browseAndBookCarpoolListingsByCriteria(User user) {
    // Input search criteria
    std::string departureLocation, destinationLocation, date;

    std::cout << "Enter Departure Location: ";
    std::cin.ignore(); // Ignore any leftover newline characters in the input buffer
    std::getline(std::cin, departureLocation);

    std::cout << "Enter Destination Location: ";
    std::getline(std::cin, destinationLocation);

    std::cout << "Enter Date (dd/mm/yyyy): ";
    std::getline(std::cin, date);
    //validateDate()
    std::cout << "-----------------------------------\n";

    // Load all carpool listings
    FileManager fileManager;
    std::vector<CarpoolListing> carpoolListings = fileManager.loadCarpoolListing();

    // Filter and display carpool listings based on user criteria
    bool found = false;
    std::cout << "Filtered Carpool Listings:\n";
    int index = 0;
    std::map <int, CarpoolListing> mp;
    for (const auto& carpool : carpoolListings) {
        bool matches = true;

        if (!departureLocation.empty() && carpool.getDepartureLocation() != departureLocation) {
            matches = false;
        }
        if (!destinationLocation.empty() && carpool.getDestinationLocation() != destinationLocation) {
            matches = false;
        }
        if (!date.empty() && carpool.getDate() != date) {
            matches = false;
        }

        if (matches) {
            cout << "The carpool that meet the criteria: \n";
            ++index;
            mp[index] = carpool;
            std::cout << "Index: " << index << "\n"
                      << "Carpool ID: " << carpool.getID() << "\n"
                      << "Vehicle Model: " << carpool.getVehicleModel() << "\n"
                      << "Vehicle Color: " << carpool.getVehicleColor() << "\n"
                      << "Plate Number: " << carpool.getPlateNumber() << "\n"
                      << "Available Seats: " << carpool.getAvailableSeats() << "\n"
                      << "Departure Location: " << carpool.getDepartureLocation() << "\n"
                      << "Destination Location: " << carpool.getDestinationLocation() << "\n"
                      << "Departure Time: " << carpool.getDepartureTime() << "\n"
                      << "Date: " << carpool.getDate() << "\n"
                      << "Estimated Duration: " << carpool.getEstimateDuration() << "\n"
                      << "Contribution per Passenger: " << carpool.getContributionPerPassenger() << "\n"
                      << "Minimum Passenger Rating: " << carpool.getMinimumPassengerRating() << "\n"
                      << "-----------------------------------\n";
            found = true;
        }
    }
    
    //booking
    if (found){
        int choice;
        std::cout << "Choose a carpool you want to book: " << std::endl;
        cin >> choice;
        //map find choice
        if (mp.find(choice) != mp.end()) {
            CarpoolListing selectedCarpool = mp[choice];
            std::cout << "You have requested carpool with ID: " << selectedCarpool.getID() << "\n";
            // Proceed with booking logic
            if (selectedCarpool.getID() == user.getUID()){
                std::cout<< "You cannot book your own car" << std::endl;
            }
            else{
                fileManager.pullRequestCarpool(selectedCarpool, user);
                std::cout<< GREEN <<"Book successfully, waiting for approval!" << std::endl << RESET;                
                //get booking date
                //get booking time
                //get cancel
                //get drivername
                //get view status
                //CarpoolListing::rejectRequest
                // void CarpoolListing::setCancelFlag() { cancelFlag = true; } //-1 available slot}
                // void CarpoolListing::setFullyBooked() { fullyBooked = true; }
            }

            // if confirmed: - credit point, - 
        } else {
            std::cout << "Invalid selection. Please try again.\n";
        }
    }
    else if (!found) {
        std::cout << "No carpool listings found matching the criteria.\n";
    }
}

void requestState(User &user)
{
    FileManager fileManager;
    std::vector<Booking> requests = fileManager.loadRequest();

    if (requests.empty()) {
        std::cout << "No request available.\n";
        std::cout << YELLOW << "Press any key to return to the menu..." << RESET;
        _getch(); // Wait for user to press any key
        return;
    }

    std::string ownerID = user.getUID();
    bool hasCarpools = false;
    std::vector<int> validOptions; // To store valid options
    std::map<int, int> requestMap; // Map to relate display numbers to actual indices

    int i = 0; // Initialize index for request numbering
    int displayIndex = 1; // Display index for user interface

    // Display requests associated with the current user
    for (const auto& request : requests) {
        if (request.getPassengerID() == ownerID) {
            std::cout << "REQUEST " << displayIndex << "\n";
            std::string passengerID = request.getPassengerID();
            hasCarpools = true;
            if (request.getStatusInfo() == 0){
                std::cout << RED << "ALREADY REJECTED!\n" << RESET;
            }
            else if (request.getStatusInfo() == 1){
                std::cout << GREEN << "ALREADY ACCEPTED!\n" << RESET;
            }
            else if (request.getStatusInfo() == -1){
                std::cout << "REQUEST APPROVED!\n";
            }
            displayIndex++; // Increment display index for next request
        }
        i++; // Increment index for next request
    }

    if (!hasCarpools) {
        std::cout << "No carpools associated with your ID.\n";
        std::cout << "Press any key to continue...";
        _getch(); // Wait for user to press any key
        return;
    }


}
// Main function for booking management
void BookingManagement(const std::string& username, const std::string& password) {
    while (true) {
        system("cls"); // Clear the screen
        printHeader("Carpool Listing Application");
        std::cout << "-----------------------------------\n";
        std::cout << BOLD << "Log in as " << username << "\n" << RESET;
        std::cout << "-----------------------------------\n";
        
        std::cout << YELLOW << "Booking Management\n";
        std::cout << "-----------------------------------\n";
        std::cout << YELLOW << "Enter an option below:\n";
        std::cout << "1. View all carpool listings\n";
        std::cout << "2. Browse and book carpool listings by departure location, destination location, and date\n";
        std::cout << "3. View all request sent\n";
        std::cout << "4. Back\n"; // Option to go back to the previous menu
        std::cout << "-----------------------------------\n";
        std::cout << GREEN << "Enter your choice: " << RESET;
        
        char choice;
        std::cin >> choice;
        // Validate user input and handle the valid choice
        if (choice == '1') {
            showAllCarpoolListings();
        } else if (choice == '2') {
            FileManager file;
            User user;
            user = file.loadSingleUser(username, password);

            browseAndBookCarpoolListingsByCriteria(user); // Assuming this function doesn't need username and password
        } else if (choice == '3') {
            FileManager file;
            User user;
            user = file.loadSingleUser(username, password);
            requestState(user);
        } else if (choice == '4') {
            std::cout << "Returning to previous menu...\n";
            return; // Exit the function and return to the calling function
        } else {
            std::cout << RED << "Invalid input, please enter a number from 1 to 3\n" << RESET;
        }

        std::cout << "\nPress any key to continue...";
        _getch(); // Wait for user to press any key
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
        std::cout << "3. Booking\n"; // search and book
        std::cout << "4. View My Rating\n"; //coi rating, feeback
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
                    BookingManagement(username, password);
                    break;
                case '4':
                    std::cout << "Viewing rating...\n";
                    // Example: viewMyRating(username);
                    break;
                case '5':
                    std::cout << "Logging out...\n";
                    system("cls");
                    coordinate();
                    return; // Exit the function to log out
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
    std::cout << BOLD << "\t \t Login as Member\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Enter username: " << RESET;
    getline(cin, username);


    std::cout<< YELLOW << "Enter password: " << RESET;
    getline(cin, password);


    // switch to login user , if ok then go to options
    UserController login;
    while (login.UserController::loginUser(username, password) == false){
        std::cout << "Wrong username or password, please try again!\n";
        std::cout << GREEN << "Enter username: ";
        getline(cin, username);
        std::cout << GREEN << "Enter password: ";
        getline(cin, password);
        // đổ màu và thêm tính năng back về coordinate
    }
    //Assume that log-in sucess
    std::cout << GREEN << "Login successfully!\n";
    system("pause");
    system("cls");
    FileManager filemanagement;
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
    std::cout << YELLOW << "Press 'enter' to log in as a Member...";
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
    while (true) {
        system("cls"); // Clear the screen
        std::cout << BOLD << "\t \t Guest\n" << RESET;
        std::cout << "-----------------------------------\n";
        std::cout << YELLOW << "Enter an option below:\n";
        std::cout << "1. Register\n";
        std::cout << "2. View Carpool Listings\n";
        std::cout << "3. Return to Previous Menu\n";
        std::cout << GREEN << "Enter your choice: " << RESET;
        std::cin >> choice;

        // Input validation
        while (choice != '1' && choice != '2' && choice != '3') {
            std::cout << RED << "Invalid input, please enter a number from 1 to 3\n" << RESET;
            std::cout << GREEN << "Enter your choice: " << RESET;
            std::cin >> choice;
        }

        // Execute choice
        if (choice == '1') {
            newRegister();  // Handle registration
        } else if (choice == '2') {
            GuestView guest;
            guest.displayCarpoolDetails();  // Show carpool listings
        } else if (choice == '3') {
            system("cls");
            coordinate();
        }

        // Prompt to return to menu or exit
        if (choice != '3') {
            std::cout << "\nPress any key to continue...";
            _getch(); // Wait for user to press any key
        }
    }
}
void admin(){
    char choice;
    FileManager fileManager;

    while (true) {
        system("cls"); // Clear the screen
        std::cout << "Admin Dashboard\n";
        std::cout << "-----------------------------------\n";
        std::cout << YELLOW<< "1. View All Users\n";
        std::cout << YELLOW << "2. View All Carpools\n";
        std::cout << YELLOW << "3. Return to Main Menu\n";
        std::cout << "-----------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Validate input using a while loop
        while (choice != '1' && choice != '2' && choice != '3') {
            std::cout << RED << "Invalid input!, please enter a number from 1 to 3\n";
            std::cout << GREEN << "Enter your choice: ";
            std::cin >> choice;
        }

        if (choice == '1') {
            std::vector<User> users = fileManager.loadUser();
            std::cout << "Information of all Users:\n";
            std::cout << "-----------------------------------\n";
            int userIndex = 1;
            for (const auto& user : users) {
                std::cout << "INFORMATION OF USER " << userIndex++ << "\n";
                std::cout << "User ID: " << user.getUID() << "\n"
                    << "Username: " << user.getUserName() << "\n"
                    << "Password: " << user.getPassword() << "\n"
                    << "Full Name: " << user.getFullName() << "\n"
                    << "Phone Number: " << user.getPhoneNumber() << "\n"
                    << "Email: " << user.getEmail() << "\n"
                    << "ID type: " << user.getIDtype() << "\n"
                    << "ID num: " << user.getIDnum() << "\n"
                    << "Credit Points: " << user.getCreditPoint() << "\n"
                    << "-----------------------------------\n";
            }
            std::cout << GREEN << "\nPress any key to continue..." << RESET;
            _getch(); // Wait for user to press any key before returning to the menu
        }
        else if (choice == '2') {
            // Load all carpool listings from the file
            std::vector<CarpoolListing> carpools = fileManager.loadCarpoolListing();
        // Iterate through each carpool and display its details
            std::cout << "Information of all Carpools: \n";
            std::cout << "-----------------------------------\n";
            for (size_t i = 0; i < carpools.size(); ++i) {
                const auto& carpool = carpools[i];
                std::cout << "INFORMATION OF CARPOOL " << (i + 1) << "\n"
                        << "Available Seats: " << carpool.getAvailableSeats() << "\n"
                        << "Departure Time: " << carpool.getDepartureTime() << "\n"
                        << "Departure Location: " << carpool.getDepartureLocation() << "\n"
                        << "Destination Location: " << carpool.getDestinationLocation() << "\n"
                        << "Vehicle Color: " << carpool.getVehicleColor() << "\n"
                        << "Vehicle Model: " << carpool.getVehicleModel() << "\n"
                        << "Vehicle PlateNumber: " << carpool.getPlateNumber() << "\n" 
                        << "Date: " << carpool.getDate() << "\n"
                        << "Minimum Passenger Rating: " << carpool.getMinimumPassengerRating() << "\n"
                        << "Contribution Per Passenger: " << carpool.getContributionPerPassenger() << "\n"
                        << "-----------------------------------\n";
            }
            std::cout << "\nPress any key to continue...";
            _getch(); // Wait for user input before returning to the menu
        }
        else if (choice == '3') {
            std::cout << GREEN << "\nPress any key to continue...";
            _getch();
            system("cls");
            coordinate();
            return; // Return to main menu or previous function
        }
    }
}

void exitProgram() {
    std::cout << "\n\nExiting the program. Goodbye!" << std::endl;
    exit(0); // Terminates the program
}

// Coordinate function to select user type
char coordinate() {
    char choice;
    std::cout << BOLD << "\t \t Carpool Listing Application\n" << RESET;
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "Use the app as: \t1. Guest\t2. Member\t3. Admin\t0. Exit Program\n";
    std::cout << GREEN << "Enter your choice: " << RESET;
    std::cin >> choice;

    while (choice != '1' && choice != '2' && choice != '3' && choice != '0') {
        std::cout << RED << "Invalid input, please enter a number from 0 to 3\n" << RESET;
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
        admin();
    } else if (choice == '0') {
        exitProgram();
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
