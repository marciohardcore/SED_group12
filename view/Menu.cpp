#pragma once

#include "..\lib\Menu.h"

using namespace std;

void Menu::introduction() {
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

void Menu::printHeader(const std::string& title) {
    std::cout << BOLD << "\t \t " << title << "\n" << RESET;
}


// Profile management function
void Menu::profileManagement(const std::string& username, const std::string& password) {
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
        } else if (choice == '3') {
            UserController userControl;
            userControl.updatePassword(username, password);
        } else if (choice == '4'){
            cin.ignore();
            int amount = 0;
            std::cout << "Credit Top - Up \n";
            std::cout << "-----------------------------------\n";
            std::string check;
            std::cout << "Enter your password: ";
            std::getline(std::cin, check);

            // Assuming 'password' is defined and initialized somewhere in the code
            if(check == password){
                std::cout << "Add the amount you want to deposit: \n";
                
                // Input validation
                while(!(std::cin >> amount) || amount <= 0) {
                    std::cout << "Invalid amount. Please enter a positive number: ";
                    std::cin.clear(); // clear error flag
                    cin.ignore();
                }
                
                User* newCredit = nullptr;
                FileManager userCredits;
                
                // Attempt to load user
                newCredit = userCredits.loadSingleUser(username, password);
                if(newCredit != nullptr) {
                    UserController userControl;
                    userControl.purchaseCredits(*newCredit, amount);
                    std::cout << "Credits successfully added!\n";
                } else {
                    std::cout << "Error: Unable to load user data. Please try again.\n";
                }
                
            } else {
                std::cout <<RED << "Incorrect password. Press any key to continue..." << RESET;
                _getch(); // Wait for user to press any key
            }
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
void Menu::CarpoolManagement(const std::string& username, const std::string& password) {
    FileManager filemanager;
    User* user = filemanager.loadSingleUser(username, password);
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
        std::cout << "5. Back\n"; // Added option to go back to the previous menu
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
            call.viewCarpool(user); // Pass the user or necessary parameters
        } else if (choice == '3') {
            std::cout << "Unlist carpool\n";
            call.unlistCarpool(user);
        } else if (choice == '4') {
            std::cout << "Viewing requests\n";
            call.viewRequest(user);
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
void Menu::showAllCarpoolListings(){
    // Load all carpool listings from the file
    FileManager fileManager;
    std::vector<CarpoolListing*> carpools = fileManager.loadCarpoolListing();
    // Iterate through each carpool and display its details
        std::cout << "Information of all Carpools: \n";
        std::cout << "-----------------------------------\n";
        for (size_t i = 0; i < carpools.size(); ++i) {
            const auto& carpool = carpools[i];
            std::cout << YELLOW << "INFORMATION OF CARPOOL " << (i + 1) << "\n"
                    << GREEN << "Available Seats: " << carpool->getAvailableSeats() << "\n"
                    << "Departure Time: " << carpool->getDepartureTime() << "\n"
                    << "Departure Location: " << carpool->getDepartureLocation() << "\n"
                    << "Destination Location: " << carpool->getDestinationLocation() << "\n"
                    << "Vehicle Color: " << carpool->getVehicleColor() << "\n"
                    << "Vehicle Model: " << carpool->getVehicleModel() << "\n"
                    << "Vehicle PlateNumber: " << carpool->getPlateNumber() << "\n" 
                    << "Date: " << carpool->getDate() << "\n"
                    << "Minimum Passenger Rating: " << carpool->getMinimumPassengerRating() << "\n"
                    << "Contribution Per Passenger: " << carpool->getContributionPerPassenger() << "\n"
                    << "-----------------------------------\n";
        }
    for (CarpoolListing* item : carpools) { delete item; }

}
void Menu::browseAndBookCarpoolListingsByCriteria(const User* user) {
    // Input search criteria
    std::string departureLocation, destinationLocation, date;
    inputValidator input;

    std::cout << "Enter Departure Location: ";
    std::cin.ignore(); // Ignore any leftover newline characters in the input buffer
    std::getline(std::cin, departureLocation);

    std::cout << "Enter Destination Location: ";
    std::getline(std::cin, destinationLocation);

    std::cout << "Enter Date (dd/mm/yyyy): ";
    std::getline(std::cin, date);
    input.validateDate(date);    
    std::cout << "-----------------------------------\n";

    // Load all carpool listings
    FileManager fileManager;
    std::vector<CarpoolListing*> carpoolListings = fileManager.loadCarpoolListing();
    std::vector<RatingSystem*> ratings = fileManager.loadRating();
    std::string Uid = user->getUID();

    double totalScore = 0;
    int count = 0;
     

    for (auto &rat : ratings) {
        if (rat->getUserID() == Uid) {
            totalScore += rat->getScore(); // Add score to total
            count++; // Increment the count of ratings
        }
    }
    
    double averageScore = totalScore / count;
        
    // Filter and display carpool listings based on user criteria
    bool found = false;
    std::cout << "Filtered Carpool Listings:\n";
    int index = 0;
    std::map <int, CarpoolListing*> mp;
    for (const auto& carpool : carpoolListings) {
        bool matches = true;

        if (!departureLocation.empty() && carpool->getDepartureLocation() != departureLocation) {
            matches = false;
        }
        if (!destinationLocation.empty() && carpool->getDestinationLocation() != destinationLocation) {
            matches = false;
        }
        if (!date.empty() && carpool->getDate() != date) {
            matches = false;
        }
        if (user->getCreditPoint() < carpool->getContributionPerPassenger()) {
            matches = false;
        }
        if (averageScore < carpool->getMinimumPassengerRating() && averageScore != 0) {
            matches = false;
        }

        if (carpool->getAvailableSeats() == 0){
            //cout << "Your chosen carpool no longer have available seat. \n";
            matches = false;
        }
        if (matches) {
            cout << "The carpool that meet the criteria: \n";
            ++index;
            mp[index] = carpool;
            std::cout << GREEN << "Index: " << index << RESET << "\n"
                      << "Carpool ID: " << carpool->getID() << "\n"
                      << "Vehicle Model: " << carpool->getVehicleModel() << "\n"
                      << "Vehicle Color: " << carpool->getVehicleColor() << "\n"
                      << "Plate Number: " << carpool->getPlateNumber() << "\n"
                      << "Available Seats: " << carpool->getAvailableSeats() << "\n"
                      << "Departure Location: " << carpool->getDepartureLocation() << "\n"
                      << "Destination Location: " << carpool->getDestinationLocation() << "\n"
                      << "Departure Time: " << carpool->getDepartureTime() << "\n"
                      << "Date: " << carpool->getDate() << "\n"
                      << "Estimated Duration: " << carpool->getEstimateDuration() << "\n"
                      << "Contribution per Passenger: " << carpool->getContributionPerPassenger() << "\n"
                      << "Minimum Passenger Rating: " << carpool->getMinimumPassengerRating() << "\n"
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
            CarpoolListing* selectedCarpool = mp[choice];
            std::cout << "You have requested carpool with ID: " << selectedCarpool->getID() << "\n";
            // Proceed with booking logic
            if (selectedCarpool->getID() == user->getUID()){
                std::cout<< "You cannot book your own car" << std::endl;
            }
            else{
                fileManager.pullRequestCarpool(selectedCarpool, user);
                std::cout<< GREEN <<"Book successfully, waiting for approval!" << std::endl << RESET;                
            }
        } else {
            std::cout << "Invalid selection. Please try again.\n";
        }
    }
    else if (!found) {
        std::cout << "No carpool listings found matching the criteria.\n";
    }
    for (CarpoolListing* item : carpoolListings) { delete item; }
    for (RatingSystem* item : ratings) { delete item; }
}

void Menu::rate_driver(std::map <int, string>& rating_map){
    system("cls"); // Clear the screen
    printHeader("Carpool Rating");
    std::cout << "-----------------------------------\n";
    std::cout << YELLOW << "List of carpool you have experienced: \n" << RESET;
    for (auto& item : rating_map){
        std::cout << item.first << ": " << item.second << "\n";
    }
    int option;
    std::cout << YELLOW << "Enter a carpool that you want to rate below: \n";
    std::cin >> option;

    std::map<int, string>::iterator it;
    it = rating_map.find(option);
    if (it == rating_map.end()){
        std::cout << "Not included in the carpool list\n";
    }
    else{
        double rate;
        std::string comment;

        FileManager file;

        User * driver = file.loadSingleUser(it->second);
        std::cout << YELLOW << "You are rating driver: " << driver->getFullName() << "\n";


        std::cout << "Enter your rating (1 - 5): \n";
        std::cin >> rate;

        std::cin.ignore();
        std::cout << "Leave your comment: \n";
        std::getline(std::cin, comment);

        RatingSystem rating(driver->getUID(), rate, comment);
        file.saveRating(rating);

        delete driver;
    }
}

void Menu::cancel_request(const User &user) {
    FileManager file;
    vector<Booking*> books = file.loadRequest();

    vector<int> cancelableRequests; // To store indices of requests eligible for cancellation

    // Display cancelable requests
    std::cout << "Pending requests for cancellation:\n";
    int index = 0;
    for (size_t i = 0; i < books.size(); ++i) {
        // Booking& book = books[i];
        Booking* book = books[i];
        if (book->getStatusInfo() == -1 && user.getUID() == book->getPassengerID()) {
            index++;
            std::cout << index
                      << ". Owner ID: " << book->getOwnerID() << "\n";
            cancelableRequests.push_back(i); // Store the index of the cancelable request
        }
    }

    if (cancelableRequests.empty()) {
        std::cout << "You have no pending requests to cancel.\n";
        std::cout << "Press any key to return to the menu...";
        _getch(); // Wait for user to press any key
        return;
    }

    // Prompt user to choose a request to cancel
    int choice;
    std::cout << "Enter the number of the request you want to cancel: ";
    std::cin >> choice;

    if (choice < 1 || choice > cancelableRequests.size()) {
        std::cout << "Invalid choice. No request was cancelled.\n";
        return;
    }

    // Confirm cancellation
    int selectedIndex = cancelableRequests[choice - 1];
    std::cout << "Are you sure you want to cancel this request? (y/n): ";
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        // Cancel the request
        books[selectedIndex]->setStatusInfor(0); // Set status to 'rejected' (0)
        file.saveAllRequest(books); // Save the updated requests
        std::cout << "Request cancelled successfully.\n";
    } else {
        std::cout << "Cancellation aborted.\n";
    }

    for (Booking* item : books) { delete item; }

}

void Menu::requestState(const User &user)
{
    FileManager fileManager;
    std::vector<Booking*> requests = fileManager.loadRequest();

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
   
    std::map <int, string> rating_map;
    int rating_index = 0;

    // Display requests associated with the current user
    for (const auto& request : requests) {
        if (request->getPassengerID() == ownerID) {
            std::cout << "REQUEST " << displayIndex << "\n";
            std::string passengerID = request->getPassengerID();
            hasCarpools = true;
            if (request->getStatusInfo() == 0){
                std::cout << RED << "Already rejected/cancelled!\n" << RESET;
            }
            else if (request->getStatusInfo() == 1){
                std::cout << GREEN << "Already accepted!\n" << RESET;
                ++rating_index;
                rating_map[rating_index] = request->getOwnerID();
            
            }
            else if (request->getStatusInfo() == -1){
                std::cout << "Request waiting...!\n";
                //MAYBE code cancel here
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
    char inp;
    std::cout << "Press 'r' to rate your previous carpool or 'c' to cancel a pending request or any key to return to the previous menu: ";
    std::cin >> inp;

    if (inp == 'r'){
        rate_driver(rating_map);
    }
    else if (inp == 'c') {
        cancel_request(user);
    } 
    else {
        std::cout << "Back to the previous menu...\n";
    }
    for (Booking* item : requests) { delete item; }
}
// Main function for booking management
void Menu::BookingManagement(const std::string& username, const std::string& password) {
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
            User* user;
            user = file.loadSingleUser(username, password);
            browseAndBookCarpoolListingsByCriteria(user); // Assuming this function doesn't need username and password
        } else if (choice == '3') {
            FileManager file;
            User* user;
            user = file.loadSingleUser(username, password);
            requestState(*user);
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
void Menu::viewMyRating(std::string& username, std::string& password) {
    FileManager file;
    User* user = file.loadSingleUser(username, password);
    std::vector<RatingSystem*> myRating = file.loadRating();
    std::string Uid = user->getUID();
    double totalScore = 0;
    int count = 0;
    std::string allComments;

    for (auto &rat : myRating) {
        if (rat->getUserID() == Uid) {
            totalScore += rat->getScore(); // Add score to total
            count++; // Increment the count of ratings
            if (!allComments.empty()) {
                allComments += ", "; // Add a comma before adding the next comment
            }
            allComments += rat->getComments(); // Append the comment
        }
    }
    if (count > 0) {
        double averageScore = totalScore / count;
        std::cout << "Average Score: " << averageScore << std::endl;
    } else {
        std::cout << "No ratings available for this user." << std::endl;
    }
    if (!allComments.empty()) {
        std::cout << "Comments: " << allComments << std::endl;
    }
     std::cout << "\nPress any key to continue...";
        _getch(); // Wait for user to press any key

    for (RatingSystem* item : myRating) { delete item; }
    delete user;
}

void Menu::memberUtils(std::string username, std::string password) {
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
                    viewMyRating(username, password);
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
void Menu::member(){
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
    }
    //Assume that log-in sucess
    std::cout << GREEN << "Login successfully!\n";
    system("pause");
    system("cls");
    FileManager filemanagement;
    memberUtils(username, password);
}


// Member options function
void Menu::memberOption() {
    char choice;
    
    std::cout << BOLD << "\t \t Member\n" << RESET;
    std::cout << "-----------------------------------\n";
    
    // Prompt to press Enter to proceed
    std::cout << YELLOW << "Press 'enter' to log in as a Member...";
    std::cin.ignore(); // To ignore any leftover newline characters in the buffer
    std::cin.get(); // Waits for the user to press Enter

    member(); // Call the member function to handle the login and subsequent options
}




void Menu::newRegister() {
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

    std::cout << GREEN << "Enter your ID number: " << RESET;
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
void Menu::guestOption() {
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
void Menu::admin(){
    char choice;
    FileManager fileManager;
    AdminView admin;
    inputValidator input;

    std::cout << BOLD << "\t \t ADMIN \n" << RESET;
    std::cout << "-----------------------------------\n";
    
    std::string username, password;

    std::cin.ignore();
    std::cout << GREEN << "Enter your admin account: " << RESET;
    std::getline(std::cin, username);

    std::cout << GREEN << "Enter your password: " << RESET;
    std::getline(std::cin, password);

    if (username == "admin" && password == "Admin123@"){
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
                admin.displayAllUsers();
                
            }
            else if (choice == '2') {
                admin.displayAllCarpools();
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
    else{
        std::cout << RED << "You are not admin" << RESET;
        std::cout << GREEN << "\nPress any key to continue...";
        _getch();
        system("cls");
        coordinate();
        return; // Return to main menu or previous function
    }
}

void Menu::exitProgram() {
    std::cout << "\n\nExiting the program. Goodbye!" << std::endl;
    exit(0); // Terminates the program
}

// Coordinate function to select user type
char Menu::coordinate() {
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

void Menu::run_program(){
    system("cls");

    // Welcome scene
    introduction();

    // Guest, user, admin selection
    coordinate();
}
