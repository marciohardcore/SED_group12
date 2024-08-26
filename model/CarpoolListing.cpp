#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CarpoolListing {
private:
    Member* driver;
    string vehicleModel;
    string vehicleColor;
    string plateNumber;
    int availableSeats;
    string departureLocation;
    string destinationLocation;
    string departureTime;
    string date;
    string estimateDuration;
    int contributionPerPassenger;
    float minimumPassengerRating;
    vector<Booking*> passengerRequests;
    vector<Booking*> approvedPassengers;
    bool cancelFlag;
    bool fullyBooked;
    string idCP;

public:
    CarpoolListing(Member* driverVal = nullptr,
                   string vehicleModelVal = "", string vehicleColorVal = "",
                   string plateNumberVal = "", int availableSeatsVal = 0,
                   string departureLocationVal = "", string destinationLocationVal = "",
                   string departureTimeVal = "", string dateVal = "",
                   string estimateDurationVal = "", int contributionPerPassengerVal = 0,
                   float minimumPassengerRatingVal = 0.0f, string idCPVal = "")
        : driver(driverVal), vehicleModel(vehicleModelVal), vehicleColor(vehicleColorVal),
          plateNumber(plateNumberVal), availableSeats(availableSeatsVal),
          departureLocation(departureLocationVal), destinationLocation(destinationLocationVal),
          departureTime(departureTimeVal), date(dateVal), estimateDuration(estimateDurationVal),
          contributionPerPassenger(contributionPerPassengerVal),
          minimumPassengerRating(minimumPassengerRatingVal),
          cancelFlag(false), fullyBooked(false), idCP(idCPVal) {}

    bool getfullyBooked() const { return fullyBooked; }
    bool getCancelFlag() const { return cancelFlag; }
    int getAvailableSeats() const { return availableSeats; }
    string getDestinationLocation() const { return destinationLocation; }
    string getDate() const { return date; }
    float getMinimumPassengerRating() const { return minimumPassengerRating; }
    int getContributionPerPassenger() const { return contributionPerPassenger; }
    vector<Booking*> getPassengerRequests() const { return passengerRequests; }

    void addRequest(Booking* booking) {
        passengerRequests.push_back(booking);
    }

    void rejectAllRequests() {
        passengerRequests.clear();
    }

    void acceptRequest(Booking* booking) {
        auto it = find(passengerRequests.begin(), passengerRequests.end(), booking);
        if (it != passengerRequests.end()) {
            approvedPassengers.push_back(booking);
            passengerRequests.erase(it);
            booking->setStatus("accepted");
            availableSeats--;
        } else {
            cout << "!!! Failed to accept request. Request not found !!!\n";
        }
    }

    void unlist() {
        if (approvedPassengers.empty()) {
            cancelFlag = true;
            cout << "\n! Carpool Listing Unlisted !\n";
        } else {
            cout << "\n!!! Failed to unlist. Seats are booked !!!\n";
        }
    }

    void viewRequests() const {
        cout << "\n* LIST OF REQUESTS *\n";
        for (size_t i = 0; i < passengerRequests.size(); ++i) {
            cout << "> #" << i + 1 << " Passenger Name: " << passengerRequests[i]->getPassenger()->getUsername() << "\n";
        }
    }

    void setCancelFlag() { cancelFlag = true; }
    void setFullyBooked() { fullyBooked = true; }
    Member* getDriver() const { return driver; }  // Added getDriver method
};