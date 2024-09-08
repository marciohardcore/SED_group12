#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "..\lib\CarpoolController.h"
#include "..\lib\IDgenerator.h"
#include <conio.h>

using namespace std;

// // Forward declaration of CarpoolListing
// class CarpoolListing;

// class Booking {
// private:
//     class Member* passenger;
//     CarpoolListing* carpoolListing;
//     string status;

// public:
//     Booking(Member* passengerVal = nullptr, CarpoolListing* carpoolListingVal = nullptr, string statusVal = "pending")
//         : passenger(passengerVal), carpoolListing(carpoolListingVal), status(statusVal) {}

//     string getStatus() const { return status; }
//     void setStatus(string statusVal) { status = statusVal; }
//     Member* getPassenger() const { return passenger; }
//     void cancel() { status = "cancelled"; }
// };

// class User {
// protected:
//     string username;
//     string password;
//     string fullName;
//     string phoneNumber;
//     string email;
//     string idType;
//     string idNumber;
//     int creditPoints;
//     float ratingScore;

// public:
//     User(string usernameVal = "", string passwordVal = "", string fullNameVal = "",
//          string phoneNumberVal = "", string emailVal = "", string idTypeVal = "",
//          string idNumberVal = "", int creditPointsVal = 0, float ratingScoreVal = 0.0f)
//         : username(usernameVal), password(passwordVal), fullName(fullNameVal),
//           phoneNumber(phoneNumberVal), email(emailVal), idType(idTypeVal),
//           idNumber(idNumberVal), creditPoints(creditPointsVal), ratingScore(ratingScoreVal) {}

//     string getUsername() const { return username; }
//     int getCreditPoints() const { return creditPoints; }
//     float getRatingScore() const { return ratingScore; }

//     void addCreditPoints(int amount) { creditPoints += amount; }
// };

// class Member : public User {
// private:
//     bool isVerified;
//     vector<CarpoolListing*> carpoolListings;
//     vector<Booking*> bookings;

// public:
//     Member(string usernameVal = "", string passwordVal = "", string fullNameVal = "",
//            string phoneNumberVal = "", string emailVal = "", string idTypeVal = "",
//            string idNumberVal = "", int creditPointsVal = 10, float ratingScoreVal = 0.0f)
//         : User(usernameVal, passwordVal, fullNameVal, phoneNumberVal, emailVal, idTypeVal, idNumberVal, creditPointsVal, ratingScoreVal),
//           isVerified(false) {}

//     void createCarpoolListing(CarpoolListing* listing) {
//         carpoolListings.push_back(listing);
//         cout << "Carpool listing created by: " << getUsername() << endl;
//     }

//     void bookCarpool(CarpoolListing* listing) {
//         bookings.push_back(new Booking(this, listing));
//         cout << "Booking made by: " << getUsername() << endl;
//     }

//     int getCreditPoints() const { return creditPoints; }
// };

// class FileManager {
// public:
//     void saveCarpoolListing(CarpoolListing* listing) {
//         // Code to save listing to a file
//     }

//     CarpoolListing* loadCarpoolListing(string id) {
//         // Code to load a specific listing from a file
//         return nullptr;  // Placeholder return
//     }

//     vector<string> getAllListingIds() {
//         // Code to get all listing IDs from the file
//         return vector<string>();  // Return an empty vector
//     }
// };

// class Logger {
// public:
//     void logEvent(string eventDescription) {
//         cout << "[LOG] " << eventDescription << endl;
//     }

//     void logError(string errorDescription) {
//         cerr << "[ERROR] " << errorDescription << endl;
//     }
// };

// class CarpoolListing {
// private:
//     Member* driver;
//     string vehicleModel;
//     string vehicleColor;
//     string plateNumber;
//     int availableSeats;
//     string departureLocation;
//     string destinationLocation;
//     string departureTime;
//     string date;
//     string estimateDuration;
//     int contributionPerPassenger;
//     float minimumPassengerRating;
//     vector<Booking*> passengerRequests;
//     vector<Booking*> approvedPassengers;
//     bool cancelFlag;
//     bool fullyBooked;
//     string idCP;

// public:
//     CarpoolListing(Member* driverVal = nullptr,
//                    string vehicleModelVal = "", string vehicleColorVal = "",
//                    string plateNumberVal = "", int availableSeatsVal = 0,
//                    string departureLocationVal = "", string destinationLocationVal = "",
//                    string departureTimeVal = "", string dateVal = "",
//                    string estimateDurationVal = "", int contributionPerPassengerVal = 0,
//                    float minimumPassengerRatingVal = 0.0f, string idCPVal = "")
//         : driver(driverVal), vehicleModel(vehicleModelVal), vehicleColor(vehicleColorVal),
//           plateNumber(plateNumberVal), availableSeats(availableSeatsVal),
//           departureLocation(departureLocationVal), destinationLocation(destinationLocationVal),
//           departureTime(departureTimeVal), date(dateVal), estimateDuration(estimateDurationVal),
//           contributionPerPassenger(contributionPerPassengerVal),
//           minimumPassengerRating(minimumPassengerRatingVal),
//           cancelFlag(false), fullyBooked(false), idCP(idCPVal) {}

//     bool getfullyBooked() const { return fullyBooked; }
//     bool getCancelFlag() const { return cancelFlag; }
//     int getAvailableSeats() const { return availableSeats; }
//     string getDestinationLocation() const { return destinationLocation; }
//     string getDate() const { return date; }
//     float getMinimumPassengerRating() const { return minimumPassengerRating; }
//     int getContributionPerPassenger() const { return contributionPerPassenger; }
//     vector<Booking*> getPassengerRequests() const { return passengerRequests; }

//     void addRequest(Booking* booking) {
//         passengerRequests.push_back(booking);
//     }

//     void rejectAllRequests() {
//         passengerRequests.clear();
//     }

//     void acceptRequest(Booking* booking) {
//         auto it = find(passengerRequests.begin(), passengerRequests.end(), booking);
//         if (it != passengerRequests.end()) {
//             approvedPassengers.push_back(booking);
//             passengerRequests.erase(it);
//             booking->setStatus("accepted");
//             availableSeats--;
//         } else {
//             cout << "!!! Failed to accept request. Request not found !!!\n";
//         }
//     }

//     void unlist() {
//         if (approvedPassengers.empty()) {
//             cancelFlag = true;
//             cout << "\n! Carpool Listing Unlisted !\n";
//         } else {
//             cout << "\n!!! Failed to unlist. Seats are booked !!!\n";
//         }
//     }

//     void viewRequests() const {
//         cout << "\n* LIST OF REQUESTS *\n";
//         for (size_t i = 0; i < passengerRequests.size(); ++i) {
//             cout << "> #" << i + 1 << " Passenger Name: " << passengerRequests[i]->getPassenger()->getUsername() << "\n";
//         }
//     }

//     void setCancelFlag() { cancelFlag = true; }
//     void setFullyBooked() { fullyBooked = true; }
//     Member* getDriver() const { return driver; }  // Added getDriver method
// };

// class CarpoolController
// {
// private:
//     FileManager filemanager;
//     // Logger logger;

// public:

void CarpoolController::createCarpool(User &user)
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

    std::cin.ignore();
    std::cout << YELLOW << "Enter vehicle model: " << RESET;
    std::getline(std::cin, vehicleModel);

    std::cout << YELLOW << "Enter vehicle color: " << RESET;
    std::getline(std::cin, vehicleColor);

    std::cout << YELLOW << "Enter plate number: " << RESET;
    std::getline(std::cin, plateNumber);

    std::cout << YELLOW << "Enter available seat(s): " << RESET;
    std::cin >> availableSeats;
    if (availableSeats <= 0)
    {
        std::cout << RED << "Error: Available seats must be positive.\n"
                  << RESET;
        return;
    }

    std::cin.ignore();
    std::cout << YELLOW << "Enter departure location: " << RESET;
    std::getline(std::cin, departureLocation);

    std::cout << YELLOW << "Enter destination location: " << RESET;
    std::getline(std::cin, destinationLocation);

    std::cout << YELLOW << "Enter departure time (hh:mm): " << RESET;
    std::getline(std::cin, departureTime);

    std::cout << YELLOW << "Enter date (dd/mm/yyyy): " << RESET;
    std::getline(std::cin, date);

    std::cout << YELLOW << "Enter estimated duration (hh:mm): " << RESET;
    std::getline(std::cin, estimateDuration);

    std::cout << YELLOW << "Enter contribution per passenger: " << RESET;
    std::cin >> contributionPerPassenger;
    if (contributionPerPassenger < 0)
    {
        std::cout << RED << "Error: Contribution per passenger cannot be negative.\n"
                  << RESET;
        return;
    }

    std::cout << YELLOW << "Enter minimum passenger rating: " << RESET;
    std::cin >> minimumPassengerRating;
    if (minimumPassengerRating < 0)
    {
        std::cout << RED << "Error: Minimum passenger rating cannot be negative.\n"
                  << RESET;
        return;
    }

    IDgenerator id_obj;
    FileManager filemanager;
    string IDowner = user.getUID();
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

void CarpoolController::viewRequest(User &user){
    FileManager fileManager;
    std::vector<Booking> requests = fileManager.loadRequest();
    if (requests.empty())
    {
        std::cout << "No request available.\n";
        std::cout << YELLOW << "Press any key to return to the menu..." << RESET;
        _getch(); // Wait for user to press any key
        return;
    }

    std::string IDOwner = user.getUID();
    bool hasCarpools = false;

    for (int i = 0; i < requests.size(); ++i)
    {
        if (requests[i].getOwnerID() == IDOwner)
        {
            std::string tempGetOwnerID = requests[i].getOwnerID();
            std::string tempGetPassengerID = requests[i].getPassengerID();

            if (tempGetOwnerID == tempGetPassengerID){           
                std::cout << RED << "YOU CANNOT BOOK YOUR OWN CARPOOL!"<< "\n";    
            }
            else{
                hasCarpools = true;
                std::cout << YELLOW << "Carpool ID: " << requests[i].getCPID() << "\n";
                std::cout << YELLOW << "Car Owner ID: " << requests[i].getOwnerID() << "\n";
                std::cout << YELLOW << "Passenger ID: " << requests[i].getPassengerID() << "\n";
            }
            // std::cout << GREEN << "\n     Car #" << i + 1 << "\n" << RESET; // Display car number

            // std::cout << YELLOW << "Carpool ID: " << carpoolListings[i].getID() << "\n"
            //           << "Vehicle Model: " << carpoolListings[i].getVehicleModel() << "\n"
            //           << "Vehicle Color: " << carpoolListings[i].getVehicleColor() << "\n"
            //           << "Plate Number: " << carpoolListings[i].getPlateNumber() << "\n"
            //           << "Available Seats: " << carpoolListings[i].getAvailableSeats() << "\n"
            //           << "Departure Location: " << carpoolListings[i].getDepartureLocation() << "\n"
            //           << "Destination Location: " << carpoolListings[i].getDestinationLocation() << "\n"
            //           << "Departure Time: " << carpoolListings[i].getDepartureTime() << "\n"
            //           << "Date: " << carpoolListings[i].getDate() << "\n"
            //           << "Estimated Duration: " << carpoolListings[i].getEstimateDuration() << "\n"
            //           << "Contribution per Passenger: " << carpoolListings[i].getContributionPerPassenger() << "\n"
            //           << "Minimum Passenger Rating: " << carpoolListings[i].getMinimumPassengerRating() << "\n"
            //           << "-----------------------------------\n" << RESET;
        }
    }
    std::cout << "Press any key to continue...";
    _getch(); // Wait for user to press any key

}

void CarpoolController::viewCarpool(User &user)
{
    // Retrieve the user's carpool info map (carpoolID -> plateNumber)
    FileManager fileManager;

    std::vector<CarpoolListing> carpoolListings = fileManager.loadCarpoolListing();

    if (carpoolListings.empty())
    {
        std::cout << "No carpool listings available.\n";
        std::cout << YELLOW << "Press any key to return to the menu..." << RESET;
        _getch(); // Wait for user to press any key
        return;
    }

    // std::vector<std::string> carIDstores = user.getcarIDstores();

    string IDowner = user.getUID();
    bool hasCarpools = false;

    for (int i = 0; i < carpoolListings.size(); ++i)
    {
        if (carpoolListings[i].getIDowner() == IDowner)
        {
            hasCarpools = true;

            std::cout << GREEN << "\n     Car #" << i + 1 << "\n" << RESET; // Display car number

            std::cout << YELLOW << "Carpool ID: " << carpoolListings[i].getID() << "\n"
                      << "Vehicle Model: " << carpoolListings[i].getVehicleModel() << "\n"
                      << "Vehicle Color: " << carpoolListings[i].getVehicleColor() << "\n"
                      << "Plate Number: " << carpoolListings[i].getPlateNumber() << "\n"
                      << "Available Seats: " << carpoolListings[i].getAvailableSeats() << "\n"
                      << "Departure Location: " << carpoolListings[i].getDepartureLocation() << "\n"
                      << "Destination Location: " << carpoolListings[i].getDestinationLocation() << "\n"
                      << "Departure Time: " << carpoolListings[i].getDepartureTime() << "\n"
                      << "Date: " << carpoolListings[i].getDate() << "\n"
                      << "Estimated Duration: " << carpoolListings[i].getEstimateDuration() << "\n"
                      << "Contribution per Passenger: " << carpoolListings[i].getContributionPerPassenger() << "\n"
                      << "Minimum Passenger Rating: " << carpoolListings[i].getMinimumPassengerRating() << "\n"
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


void CarpoolController::unlistCarpool(User &user)
{
    // Retrieve the user's carpool info map (carpoolID -> plateNumber)
    FileManager fileManager;

    std::vector<CarpoolListing> unlistCarpool = fileManager.loadCarpoolListing();
    if (unlistCarpool.empty())
    {
        std::cout << "No carpool listings available.\n";
        std::cout << "Press any key to return to the menu...";
        _getch(); // Wait for user to press any key
        return;
    }

    // std::vector<std::string> carIDstores = user.getcarIDstores();

    string IDowner = user.getUID();
    std::cout << "Your Carpool Listings:\n";
    bool hasCarpools = false;

    for (int i = 0; i < unlistCarpool.size(); ++i)
    {
        if (unlistCarpool[i].getIDowner() == IDowner)
        {
            hasCarpools = true;

            std::cout << GREEN << "\n     Car #" << i + 1 << "\n" << RESET; // Display car number

            std::cout << YELLOW << "Carpool ID: " << unlistCarpool[i].getID() << "\n"
                      << "Vehicle Model: " << unlistCarpool[i].getVehicleModel() << "\n"
                      << "Vehicle Color: " << unlistCarpool[i].getVehicleColor() << "\n"
                      << "Plate Number: " << unlistCarpool[i].getPlateNumber() << "\n"
                      << "Available Seats: " << unlistCarpool[i].getAvailableSeats() << "\n"
                      << "Departure Location: " << unlistCarpool[i].getDepartureLocation() << "\n"
                      << "Destination Location: " << unlistCarpool[i].getDestinationLocation() << "\n"
                      << "Departure Time: " << unlistCarpool[i].getDepartureTime() << "\n"
                      << "Date: " << unlistCarpool[i].getDate() << "\n"
                      << "Estimated Duration: " << unlistCarpool[i].getEstimateDuration() << "\n"
                      << "Contribution per Passenger: " << unlistCarpool[i].getContributionPerPassenger() << "\n"
                      << "Minimum Passenger Rating: " << unlistCarpool[i].getMinimumPassengerRating() << "\n"
                      << "-----------------------------------\n" << RESET;
        }
    }

    if (!hasCarpools)
    {
        std::cout << "No carpool listings found for this user.\n";
    }

    int option;
    cout << GREEN << "Please select the exactly car number you want to unlist.\n";
    cout << "Enter the carpool listing you want to unlist( must be an integer): ";
    cin >> option;
    int index = option - 1;

    for (int i = 0; i <= unlistCarpool.size(); ++i)
    {
        if (option == i)
        {
            unlistCarpool.erase(unlistCarpool.begin() + index);
        }
    }

    cout << GREEN << "Your carpool has been deleted!\n";
    std::cout << "\nPress any key to return to the admin menu...";
    _getch(); // Wait for user to press any key
    fileManager.saveAllCarpoolListing(unlistCarpool);
}

// vector<CarpoolListing*> searchCarpools(string location, string date, int minRating, int credits) {
//     vector<CarpoolListing*> matchingListings;
//     vector<CarpoolListing*> listings = filemanager.loadCarpoolListing();  // Get all carpool listings

//     for (auto listing : listings)
//     {
//         // Apply filters
//         if (!listing->getfullyBooked() &&
//             listing->getDestinationLocation() == location &&
//             listing->getDate() == date &&
//             listing->getContributionPerPassenger() <= credits &&
//             minRating >= listing->getMinimumPassengerRating())
//         {
//             matchingListings.push_back(listing);
//         }
//         else
//         {
//             // optional - delete this else statement when needed
//             logger.logEvent("Carpool listing rejected: " + listing->getDestinationLocation() + " on date: " + listing->getDate());
//         }
//     }

//     logger.logEvent("Carpools searched for location: " + location + " on date: " + date);
//     return matchingListings;
// }

// Booking* bookCarpool(Member* passenger, CarpoolListing* listing) {
//     // Check if the listing is active
//     if (listing->getfullyBooked() || listing->getCancelFlag()) {
//         cerr << "Listing is no longer available." << endl;
//         return nullptr;
//     }

//     // Check if the member has enough credits
//     int requiredCredits = listing->getContributionPerPassenger();
//     if (passenger->getCreditPoints() < requiredCredits) {
//         cerr << "Not enough credits to book this carpool." << endl;
//         return nullptr;
//     }

//     // Perform the booking action via the Member class
//     passenger->bookCarpool(listing);

//     Booking* booking = new Booking(passenger, listing);
//     logger.logEvent("Carpool booked by: " + passenger->getUsername());
//     return booking;
// }

// void viewRequests(CarpoolListing* listing) {
//     vector<Booking*> allRequests = listing->getPassengerRequests();
//     vector<int> acceptedRequests;
//     // view all requests
//     listing->viewRequests();
//     cout << "NOTICE: Enter '0' when done accepting request to exit !\n";
//     // user -> select request(s) to accept
//     while (true) {
//         int number;
//         cout << "Enter request to accept: ";
//         cin >> number;
//         if (number == 0) break;
//         if (find(acceptedRequests.begin(), acceptedRequests.end(), number) == acceptedRequests.end()) {
//             acceptedRequests.push_back(number);
//         } else {
//             cout << "!!! Already selected !!!\n";
//         }
//     }
//     // accept requests and reject the rest
//     for (int i : acceptedRequests) {
//         listing->acceptRequest(allRequests[i - 1]);
//     }
//     listing->rejectAllRequests();

//     logger.logEvent("Viewed requests for carpool: " + listing->getDriver()->getUsername());
// }

// void CarpoolController::cancelBooking(Booking* booking) {
//     // Cancel the booking and remove it from the passenger's bookings list
//     booking->getPassenger()->cancelBooking(booking);

//     // Remove the booking from the carpool's passengerRequests list
//     booking->getCarpoolListing()->rejectRequest(booking);

//     //logger.logEvent("Booking canceled by: " + booking->getPassenger()->getUsername());
// }

// int main() {
//     // Create members
// Member* driver = new Member("John Doe", "password", "John Doe", "123-4567", "john@example.com", "ID", "123456789", 100, 4.8);
//     Member* passenger = new Member("Jane Smith", "password", "Jane Smith", "987-6543", "jane@example.com", "ID", "987654321", 50, 4.5);

//     // Create a carpool listing
//     CarpoolListing* listing = new CarpoolListing(driver, "Toyota Prius", "Blue", "XYZ 1234", 3, "Hanoi", "Saigon", "09:00 AM", "2024-08-15", "6 hours", 15, 4.5, "CP001");

//     // Create CarpoolController
//     CarpoolController controller;

//     // Save the carpool listing using the FileManager (in CarpoolController)
//     controller.createCarpool(driver, listing);

//     // Simulate a passenger making a booking
//     Booking* booking = controller.bookCarpool(passenger, listing);

//     if (booking != nullptr) {
//         cout << "Booking successful for " << passenger->getUsername() << endl;
//     } else {
//         cout << "Booking failed for " << passenger->getUsername() << endl;
//     }

//     // Manage requests for the carpool listing
//     controller.manageCarpoolRequests(listing);

//     // Simulate searching for carpools
//     vector<CarpoolListing*> results = controller.searchCarpools("Saigon", "2024-08-15", 4, 20);
//     cout << "Found " << results.size() << " matching carpools." << endl;

//     // Clean up
//     delete driver;
//     delete passenger;
//     delete listing;
//     for (auto& r : results) {
//         delete r;
//     }

//     return 0;
// }
