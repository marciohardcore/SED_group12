#include <iostream>
#include <vector>
#include <algorithm>

#include "../lib/CarpoolListing.h"

using namespace std;


// CarpoolListing(Member* driverVal = nullptr,
//                 string vehicleModelVal = "", string vehicleColorVal = "",
//                 string plateNumberVal = "", int availableSeatsVal = 0,
//                 string departureLocationVal = "", string destinationLocationVal = "",
//                 string departureTimeVal = "", string dateVal = "",
//                 string estimateDurationVal = "", int contributionPerPassengerVal = 0,
//                 float minimumPassengerRatingVal = 0.0f, string idCPVal = "")
//     : driver(driverVal), vehicleModel(vehicleModelVal), vehicleColor(vehicleColorVal),
//         plateNumber(plateNumberVal), availableSeats(availableSeatsVal),
//         departureLocation(departureLocationVal), destinationLocation(destinationLocationVal),
//         departureTime(departureTimeVal), date(dateVal), estimateDuration(estimateDurationVal),
//         contributionPerPassenger(contributionPerPassengerVal),
//         minimumPassengerRating(minimumPassengerRatingVal),
//         cancelFlag(false), fullyBooked(false), idCP(idCPVal) {};
CarpoolListing::CarpoolListing()
    : vehicleModel(""), vehicleColor(""), plateNumber(""), availableSeats(0),
      departureLocation(""), destinationLocation(""), departureTime(""),
      date(""), estimateDuration(""), contributionPerPassenger(0),
      minimumPassengerRating(0.0f), cancelFlag(false), fullyBooked(false), idCP("") {}
CarpoolListing::CarpoolListing(string idCPVal = "", 
                string vehicleModelVal = "", string vehicleColorVal = "",
                string plateNumberVal = "", int availableSeatsVal = 0,
                string departureLocationVal = "", string destinationLocationVal = "",
                string departureTimeVal = "", string dateVal = "",
                string estimateDurationVal = "", int contributionPerPassengerVal = 0,
                float minimumPassengerRatingVal = 0.0f, bool cancelFlagVal = false)
    : vehicleModel(vehicleModelVal), vehicleColor(vehicleColorVal),
        plateNumber(plateNumberVal), availableSeats(availableSeatsVal),
        departureLocation(departureLocationVal), destinationLocation(destinationLocationVal),
        departureTime(departureTimeVal), date(dateVal), estimateDuration(estimateDurationVal),
        contributionPerPassenger(contributionPerPassengerVal),
        minimumPassengerRating(minimumPassengerRatingVal),
        cancelFlag(cancelFlagVal), fullyBooked(false), idCP(idCPVal) {}

               
string CarpoolListing::getID() const { return idCP; }          
string CarpoolListing::getVehicleModel() const { return vehicleModel; }
string CarpoolListing::getVehicleColor() const { return  vehicleColor; }
string CarpoolListing::getPlateNumber() const { return plateNumber; }
string CarpoolListing::getEstimateDuration() const { return estimateDuration; }
bool CarpoolListing::getfullyBooked() const { return fullyBooked; }
bool CarpoolListing::getCancelFlag() const { return cancelFlag; }
string CarpoolListing::getVehicleModel() const {return vehicleModel;}
string CarpoolListing::getVehicleColor() const {return vehicleColor;} 
string CarpoolListing::getPlateNumber() const {return plateNumber;}  
int CarpoolListing::getAvailableSeats() const { return availableSeats; }
string CarpoolListing::getDepartureTime() const { return departureTime; }
string CarpoolListing::getDepartureLocation() const { return departureLocation; }
string CarpoolListing::getDestinationLocation() const { return destinationLocation; }
string CarpoolListing::getDate() const { return date; }
float CarpoolListing::getMinimumPassengerRating() const { return minimumPassengerRating; }
int CarpoolListing::getContributionPerPassenger() const { return contributionPerPassenger; }
// vector<Booking*> CarpoolListing::getPassengerRequests() const { return passengerRequests; }

// void CarpoolListing::addRequest(Booking* booking) {
//     passengerRequests.push_back(booking);
// }

// void CarpoolListing::rejectAllRequests() {
//     passengerRequests.clear();
// }

// void CarpoolListing::acceptRequest(Booking* booking) {
//     auto it = find(passengerRequests.begin(), passengerRequests.end(), booking);
//     if (it != passengerRequests.end()) {
//         approvedPassengers.push_back(booking);
//         passengerRequests.erase(it);
//         booking->setStatus("accepted");
//         availableSeats--;
//     } else {
//         cout << "!!! Failed to accept request. Request not found !!!\n";
//     }
// }

// void CarpoolListing::unlist() {
//     if (approvedPassengers.empty()) {
//         cancelFlag = true;
//         cout << "\n! Carpool Listing Unlisted !\n";
//     } else {
//         cout << "\n!!! Failed to unlist. Seats are booked !!!\n";
//     }
// }

// void CarpoolListing::viewRequests() const {
//     cout << "\n* LIST OF REQUESTS *\n";
//     for (size_t i = 0; i < passengerRequests.size(); ++i) {
//         cout << "> #" << i + 1 << " Passenger Name: " << passengerRequests[i]->getPassenger()->getUsername() << "\n";
//     }
// }

void CarpoolListing::setCancelFlag() { cancelFlag = true; }
void CarpoolListing::setFullyBooked() { fullyBooked = true; }
// Member* CarpoolListing::getDriver() const { return driver; }  // Added getDriver method