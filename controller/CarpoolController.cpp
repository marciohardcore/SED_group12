#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

class CarpoolController {
private:
    FileManager filemanager;
    Logger logger;

public:
    void createCarpool(Member* driver, CarpoolListing* listing) {
        driver->createCarpoolListing(listing);
        filemanager.saveCarpoolListing(listing);
        logger.logEvent("Carpool listing created by: " + driver->getUsername());
    }

    vector<CarpoolListing*> searchCarpools(string location, string date, int minRating, int credits) {
        vector<CarpoolListing*> matchingListings;
        vector<CarpoolListing*> listings = filemanager.loadCarpoolListing();  // Get all carpool listings

        for (auto listing : listings) 
        {
            // Apply filters
            if (!listing->getfullyBooked() &&
                listing->getDestinationLocation() == location &&
                listing->getDate() == date &&
                listing->getContributionPerPassenger() <= credits &&
                minRating >= listing->getMinimumPassengerRating()) 
            {
                matchingListings.push_back(listing);
            } 
            else 
            {
                // optional - delete this else statement when needed
                logger.logEvent("Carpool listing rejected: " + listing->getDestinationLocation() + " on date: " + listing->getDate());
            }
        }

        logger.logEvent("Carpools searched for location: " + location + " on date: " + date);
        return matchingListings;
    }

    Booking* bookCarpool(Member* passenger, CarpoolListing* listing) {
        // Check if the listing is active
        if (listing->getfullyBooked() || listing->getCancelFlag()) {
            cerr << "Listing is no longer available." << endl;
            return nullptr;
        }

        // Check if the member has enough credits
        int requiredCredits = listing->getContributionPerPassenger();
        if (passenger->getCreditPoints() < requiredCredits) {
            cerr << "Not enough credits to book this carpool." << endl;
            return nullptr;
        }

        // Perform the booking action via the Member class
        passenger->bookCarpool(listing);

        Booking* booking = new Booking(passenger, listing);
        logger.logEvent("Carpool booked by: " + passenger->getUsername());
        return booking;
    }

    void manageCarpoolRequests(CarpoolListing* listing) {
        vector<Booking*> allRequests = listing->getPassengerRequests();
        vector<int> acceptedRequests;
        // view all requests
        listing->viewRequests();
        cout << "NOTICE: Enter '0' when done accepting request to exit !\n";
        // user -> select request(s) to accept
        while (true) {
            int number;
            cout << "Enter request to accept: ";
            cin >> number;
            if (number == 0) break;
            if (find(acceptedRequests.begin(), acceptedRequests.end(), number) == acceptedRequests.end()) {
                acceptedRequests.push_back(number);
            } else {
                cout << "!!! Already selected !!!\n";
            }
        }
        // accept requests and reject the rest
        for (int i : acceptedRequests) {
            listing->acceptRequest(allRequests[i - 1]);
        }
        listing->rejectAllRequests();

        logger.logEvent("Viewed requests for carpool: " + listing->getDriver()->getUsername());
    }

    void cancelBooking(Booking* booking) {
        booking->cancel();
        logger.logEvent("Booking canceled by: " + booking->getPassenger()->getUsername());
    }
};

// int main() {
//     // Create members
//     Member* driver = new Member("John Doe", "password", "John Doe", "123-4567", "john@example.com", "ID", "123456789", 100, 4.8);
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
