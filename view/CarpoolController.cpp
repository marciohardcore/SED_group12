#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "..\lib\CarpoolController.h"
#include "..\lib\IDgenerator.h"
#include <conio.h>
#include "..\lib\InputValidator.h"
#include "..\lib\UserController.h"
using namespace std;

void CarpoolController::createCarpool(const User *user)
{
    std::string vehicleModel;
    std::string vehicleColor;
    std::string plateNumber;
    int availableSeats;
    std::string departureLocation;
    std::string destinationLocation;
    std::string departureTime;
    std::string date;
    std::string estimateDuration;
    int contributionPerPassenger;
    float minimumPassengerRating;
    bool cancelFlag = false; // Initialize boolean variables
    bool fullyBooked = false;
    std::string idCP;
    inputValidator input;

    std::cin.ignore();
    std::cout << YELLOW << "Enter vehicle model: " << RESET;
    std::getline(std::cin, vehicleModel);
    // nay nhap gi cung dc

    std::cout << YELLOW << "Enter vehicle color: " << RESET;
    std::getline(std::cin, vehicleColor);
    input.inputValidator::validateVehicleColor(vehicleColor);
    //no number

    std::cout << YELLOW << "Enter plate number: " << RESET;
    std::getline(std::cin, plateNumber);
    input.inputValidator::validatePlateNumber(plateNumber);
    //no space

    std::cout << YELLOW << "Enter available seat(s): " << RESET;
    std::cin >> availableSeats;
    while (availableSeats <= 0)
    {
        std::cout << RED << "Error: Available seats must be positive.\n"
                  << RESET;
        std::cin >> availableSeats;
    }

    std::cin.ignore();
    std::cout << YELLOW << "Enter departure location: " << RESET;
    std::getline(std::cin, departureLocation);  
    input.validateLocation(departureLocation);

    std::cout << YELLOW << "Enter destination location: " << RESET;
    std::getline(std::cin, destinationLocation);
    input.validateLocation(destinationLocation);

    std::cout << YELLOW << "Enter departure time (hh:mm): " << RESET;
    std::getline(std::cin, departureTime);
    input.inputValidator::validateTime(departureTime);

    std::cout << YELLOW << "Enter date (dd/mm/yyyy): " << RESET;
    std::getline(std::cin, date);
    input.inputValidator::validateDate(date);

    std::cout << YELLOW << "Enter estimated duration (hh:mm): " << RESET;
    std::getline(std::cin, estimateDuration);
    input.inputValidator::validateTime(estimateDuration);

    std::cout << YELLOW << "Enter contribution per passenger: " << RESET;
    std::cin >> contributionPerPassenger;
    while (contributionPerPassenger < 0)
    {
        std::cout << RED << "Error: Contribution per passenger cannot be negative.\n"
                  << RESET;
        return;
    }

    std::cout << YELLOW << "Enter minimum passenger rating: " << RESET;
    std::cin >> minimumPassengerRating;
    while (minimumPassengerRating < 0)
    {
        std::cout << RED << "Error: Minimum passenger rating cannot be negative.\n"
                  << RESET;
        return;
    }

    IDgenerator id_obj;
    FileManager filemanager;
    string IDowner = user->getUID();
    std::string ans = id_obj.generateCarpoolListingID();
    CarpoolListing listing(ans, vehicleModel, vehicleColor, plateNumber,
                           availableSeats, departureLocation, destinationLocation,
                           departureTime, date, estimateDuration,
                           contributionPerPassenger, minimumPassengerRating, cancelFlag, IDowner);

    filemanager.saveCarpoolListing(listing);
    // user.setCarIDToStore(ans);
    std::cout << GREEN << "\n\nCarpool Created! \n"
              << RESET;
    std::cout << "Press any key to continue...";
    _getch();      // Wait for user to press any key
    system("cls"); // Clear the screen

    // Optionally log the event here if needed
}

void CarpoolController::viewRequest(const User* user) {
    FileManager fileManager;
    std::vector<Booking*> requests = fileManager.loadRequest();

    if (requests.empty()) {
        std::cout << "No request available.\n";
        std::cout << YELLOW << "Press any key to return to the menu..." << RESET;
        _getch(); // Wait for user to press any key
        return;
    }

    std::string ownerID = user->getUID();
    bool hasCarpools = false;
    std::vector<int> validOptions; // To store valid options
    std::map<int, int> requestMap; // Map to relate display numbers to actual indices

    int i = 0; // Initialize index for request numbering
    int displayIndex = 1; // Display index for user interface

    // Display requests associated with the current user
    for (const auto& request : requests) {
        if (request->getOwnerID() == ownerID) {
            std::cout << "REQUEST " << displayIndex << "\n";
            std::string passengerID = request->getPassengerID();

            if (ownerID == passengerID) {
                std::cout << RED << "You cannot book your own carpool!\n" << RESET;
            } else if(ownerID != passengerID && request->getStatusInfo() == -1){
                hasCarpools = true;
                std::cout << YELLOW << "Passenger ID: " << passengerID << " has booked your carpool ID: " << request->getCPID() << RESET "\n";
                validOptions.push_back(displayIndex); // Store valid display numbers
                requestMap[displayIndex] = i; // Map display number to request index
            }
            
            if (request->getStatusInfo() == 0){
                std::cout << RED << "Already rejected!\n" << RESET;
            }
            else if (request->getStatusInfo() == 1){
                std::cout << GREEN << "Already accepted!\n" << RESET;
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

    // Let the user choose a valid request option
    int option;
    std::cout << GREEN << "Enter request option you want (1 to " << displayIndex-1 << "): " << RESET << std::endl;

    // Ensure the user inputs a valid request number
    while (true) {
        std::cin >> option;
        if (std::find(validOptions.begin(), validOptions.end(), option) != validOptions.end()) {
            break; // Valid option selected
        } else {
            std::cout << RED << "Invalid option. Please enter a valid request number: " << RESET;
        }
    }

    // Map the selected option to the actual request index
    int index = requestMap[option]; // Get the actual request index from the map
    Booking& selectedRequest = *requests[index]; // Get a reference to allow modification

    // Ask the user to accept or reject the request
    int choice;
    std::cout << YELLOW << "1. Accept request\n" << "2. Reject request\n" << "Enter your choice: " << RESET;

    // Input validation for accepting or rejecting the request
    while (true) {
        std::cin >> choice;
        if (choice == 1 || choice == 2) {
            break; // Valid choice
        } else {
            std::cout << RED << "Invalid input, please enter 1 or 2: " << RESET;
        }
    }

    // Handle accept/reject logic
    if (choice == 1) {
        std::cout << GREEN << "You accepted the request from Passenger ID: " << selectedRequest.getPassengerID() << RESET << std::endl;
        selectedRequest.setStatusInfor(1); // Update status to accepted
        vector<CarpoolListing*> carpools = fileManager.loadCarpoolListing();
        std::string carpoolID = selectedRequest.getCPID();

        if (carpools.empty()) {
        std::cout << "Error!\n";
        std::cout << YELLOW << "Press any key to return to the menu..." << RESET;
        _getch(); // Wait for user to press any key
        return;
    }

        for (auto& cars : carpools)
        {
            if (cars->getID() == carpoolID)
            {
                int seatsLeft = cars->getAvailableSeats() - 1;
                cars->setAvailableSeat(seatsLeft);
                vector<User*> users = fileManager.loadUser();
                // vector<User*> users = fileManager.loadUser();

                for (auto& us : users) // use reference to modify the user directly in the vector
                {
                    if(us->getUID() == selectedRequest.getPassengerID())
                    {
                        int afterCredit = us->getCreditPoint() - cars->getContributionPerPassenger(); // modify the user in the vector
                        us->setCreditPoint(afterCredit); // update the credit points for 'us' directly
                        fileManager.saveAllUsers(users); // save the updated users vector
                        // rating 
                        char rateChoice;
                        std::cout << "Do you want to rate this carpool? Press 'r' to rate, or any other key to skip: ";
                        std::cin >> rateChoice;

                        if (rateChoice == 'r' || rateChoice == 'R') {
                            // Prompt for rating details
                            int point;
                            std::string comment;
                            std::cout << "Enter your rating (1-5): ";
                            std::cin >> point;
                            std::cin.ignore(); // to handle newline character after entering rating
                            std::cout << "Enter your comment: ";
                            std::getline(std::cin, comment);

                            // Create and save the rating
                            RatingSystem rating(selectedRequest.getPassengerID(), point, comment);
                            fileManager.saveRating(rating);
                        }
                        break; // exit loop after finding the user
                    }
                }

                for (User* item : users) {
                    delete item; // Deallocate each User object
                }
            }
        }
        fileManager.saveAllCarpoolListing(carpools);

    } else if (choice == 2) {
        std::cout << RED << "You rejected the request from Passenger ID: " << selectedRequest.getPassengerID() << RESET << std::endl;
        selectedRequest.setStatusInfor(0); // Update status to rejected

    }

    // Save updated requests to the file
    fileManager.saveAllRequest(requests);

    std::cout << YELLOW << "Press any key to continue..." << RESET;
    _getch(); // Wait for user to press any key

}

void CarpoolController::viewCarpool(const User* user)
{
    // Retrieve the user's carpool info map (carpoolID -> plateNumber)
    FileManager fileManager;

    std::vector<CarpoolListing*> carpoolListings = fileManager.loadCarpoolListing();

    if (carpoolListings.empty())
    {
        std::cout << "No carpool listings available.\n";
        std::cout << YELLOW << "Press any key to return to the menu..." << RESET;
        _getch(); // Wait for user to press any key
        return;
    }


    string IDowner = user->getUID();
    bool hasCarpools = false;

    for (int i = 0; i < carpoolListings.size(); ++i)
    {
        if (carpoolListings[i]->getIDowner() == IDowner)
        {
            hasCarpools = true;

            std::cout << GREEN << "\n     Car #" << i + 1 << "\n" << RESET; // Display car number

            std::cout << YELLOW << "Carpool ID: " << carpoolListings[i]->getID() << "\n"
                      << "Vehicle Model: " << carpoolListings[i]->getVehicleModel() << "\n"
                      << "Vehicle Color: " << carpoolListings[i]->getVehicleColor() << "\n"
                      << "Plate Number: " << carpoolListings[i]->getPlateNumber() << "\n"
                      << "Available Seats: " << carpoolListings[i]->getAvailableSeats() << "\n"
                      << "Departure Location: " << carpoolListings[i]->getDepartureLocation() << "\n"
                      << "Destination Location: " << carpoolListings[i]->getDestinationLocation() << "\n"
                      << "Departure Time: " << carpoolListings[i]->getDepartureTime() << "\n"
                      << "Date: " << carpoolListings[i]->getDate() << "\n"
                      << "Estimated Duration: " << carpoolListings[i]->getEstimateDuration() << "\n"
                      << "Contribution per Passenger: " << carpoolListings[i]->getContributionPerPassenger() << "\n"
                      << "Minimum Passenger Rating: " << carpoolListings[i]->getMinimumPassengerRating() << "\n"
                      << "-----------------------------------\n" << RESET;
        }
    }

    if (!hasCarpools)
    {
        std::cout << "No carpool listings found for this user.\n";
    }

    std::cout << "\nPress any key to return to the admin menu...";
    _getch();      // Wait for user to press any key
    system("cls"); // Clear the screen
}


void CarpoolController::unlistCarpool(const User* user)
{
    // Retrieve the user's carpool info map (carpoolID -> plateNumber)
    FileManager fileManager;

    std::vector<CarpoolListing*> unlistCarpool = fileManager.loadCarpoolListing();
    if (unlistCarpool.empty())
    {
        std::cout << "No carpool listings available.\n";
        std::cout << "Press any key to return to the menu...";
        _getch(); // Wait for user to press any key
        return;
    }


    string IDowner = user->getUID();
    std::cout << "Your Carpool Listings:\n";
    bool hasCarpools = false;
    
    for (int i = 0; i < unlistCarpool.size(); ++i)
    {
        if (unlistCarpool[i]->getIDowner() == IDowner)
        {
            hasCarpools = true;

            std::cout << GREEN << "\n     Car #" << i + 1 << "\n" << RESET; // Display car number

            std::cout << YELLOW << "Carpool ID: " << unlistCarpool[i]->getID() << "\n"
                      << "Vehicle Model: " << unlistCarpool[i]->getVehicleModel() << "\n"
                      << "Vehicle Color: " << unlistCarpool[i]->getVehicleColor() << "\n"
                      << "Plate Number: " << unlistCarpool[i]->getPlateNumber() << "\n"
                      << "Available Seats: " << unlistCarpool[i]->getAvailableSeats() << "\n"
                      << "Departure Location: " << unlistCarpool[i]->getDepartureLocation() << "\n"
                      << "Destination Location: " << unlistCarpool[i]->getDestinationLocation() << "\n"
                      << "Departure Time: " << unlistCarpool[i]->getDepartureTime() << "\n"
                      << "Date: " << unlistCarpool[i]->getDate() << "\n"
                      << "Estimated Duration: " << unlistCarpool[i]->getEstimateDuration() << "\n"
                      << "Contribution per Passenger: " << unlistCarpool[i]->getContributionPerPassenger() << "\n"
                      << "Minimum Passenger Rating: " << unlistCarpool[i]->getMinimumPassengerRating() << "\n"
                      << "-----------------------------------\n" << RESET;
        }
    }

    if (!hasCarpools)
    {
        std::cout << "No carpool listings found for this user.\n";
    }

    int option;
    std::cout << GREEN << "Please select the exact car number you want to unlist.\n";
    std::cout << "Enter the carpool listing number you want to unlist (must be an integer): ";
    std::cin >> option;
    
    if (option < 1 || option > unlistCarpool.size()) {
        std::cout << "Invalid car number selected.\n";
        return;
    }

    int index = option - 1;  // Get the correct index
    CarpoolListing* selectedCarpool = unlistCarpool[index];  // The carpool selected by the user
    
    // Load the booking requests
    std::vector<Booking*> req = fileManager.loadRequest();
    
    // Check if the selected carpool has any bookings
    bool isBooked = false;
    for (auto& booking : req)
    {
        if (booking->getCPID() == selectedCarpool->getID())
        {
            std::cout << "This carpool has been booked! You cannot unlist it.\n";
            isBooked = true;
            break;
        }
    }

    // If the carpool is not booked, proceed with unlisting
    if (!isBooked)
    {
        unlistCarpool.erase(unlistCarpool.begin() + index);  // Remove the carpool from the vector
        std::cout << GREEN << "Your carpool has been unlisted successfully!\n";
        fileManager.saveAllCarpoolListing(unlistCarpool);  // Save the updated listings
    }

    std::cout << "\nPress any key to return to the menu...";
    _getch();  // Wait for user to press any key
}

