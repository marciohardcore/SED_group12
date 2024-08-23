#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Member;
// class Booking;
// class CarpoolListing;

// class Member {
// private:
//     string name;
//     int age;

// public:
//     Member(string nameVal = "", int ageVal = 0) : name(nameVal), age(ageVal) {}

//     string getName() { return name; }
//     int getAge() { return age; }
// };

// class Booking {   
// private:
//     Member* passenger;
//     CarpoolListing* carpoolListing;
//     string status;

// public:
//     Booking(Member* passengerVal = nullptr, CarpoolListing* carpoolListingVal = nullptr, string statusVal = "pending")
//         : passenger(passengerVal), carpoolListing(carpoolListingVal), status(statusVal) {}

//     string getStatus() { return status; }
//     void setStatus(string statusVal) { status = statusVal; }
//     Member* getPassenger() { return passenger; }
// };

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
    string idCP;

public:
    CarpoolListing(Member* driverVal = nullptr,
                   string vehicleModelVal = "",
                   string vehicleColorVal = "",
                   string plateNumberVal = "",
                   int availableSeatsVal = 0,
                   string departureLocationVal = "",
                   string destinationLocationVal = "",
                   string departureTimeVal = "",
                   string dateVal = "",
                   string estimateDurationVal = "",
                   int contributionPerPassengerVal = 0,
                   float minimumPassengerRatingVal = 0.0f,
                   string idCPVal = "")
        : driver(driverVal),
          vehicleModel(vehicleModelVal),
          vehicleColor(vehicleColorVal),
          plateNumber(plateNumberVal),
          availableSeats(availableSeatsVal),
          departureLocation(departureLocationVal),
          destinationLocation(destinationLocationVal),
          departureTime(departureTimeVal),
          date(dateVal),
          estimateDuration(estimateDurationVal),
          contributionPerPassenger(contributionPerPassengerVal),
          minimumPassengerRating(minimumPassengerRatingVal),
          cancelFlag(false),
          idCP(idCPVal) {}

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

    void viewRequests() {
        cout << "\n* LIST OF REQUESTS *\n";
        for (size_t i = 0; i < passengerRequests.size(); ++i) {
            cout << "> #" << i + 1 << " Passenger Name: " << passengerRequests[i]->getPassenger()->getName() << "\n";
        }
    }
};

// int main() {
//     // Create Members
//     Member driver("Alice", 30);
//     Member passenger1("Bob", 25);
//     Member passenger2("Charlie", 28);

//     // Create CarpoolListing
//     CarpoolListing carpool(&driver, "Toyota", "Red", "XYZ123", 3, "Downtown", "Airport", "10:00 AM", "2024-08-22", "45 mins", 20, 4.5f, "CP001");

//     // Create Bookings
//     Booking booking1(&passenger1, &carpool);
//     Booking booking2(&passenger2, &carpool);

//     // Add requests to CarpoolListing
//     carpool.addRequest(&booking1);
//     carpool.addRequest(&booking2);

//     // View all requests
//     carpool.viewRequests();

//     // Accept first request
//     carpool.acceptRequest(&booking1);

//     // View all requests after accepting one
//     carpool.viewRequests();

//     // Try to unlist the carpool (should fail because a seat is booked)
//     carpool.unlist();

//     // Reject all remaining requests
//     carpool.rejectAllRequests();

//     // Try to unlist again (should succeed now)
//     carpool.unlist();

//     return 0;
// }
