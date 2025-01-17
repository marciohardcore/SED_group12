#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\CarpoolListing.h"

using namespace std;

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
                float minimumPassengerRatingVal = 0.0f, bool cancelFlagVal = false, string IDowner = "")
    : vehicleModel(vehicleModelVal), vehicleColor(vehicleColorVal),
        plateNumber(plateNumberVal), availableSeats(availableSeatsVal),
        departureLocation(departureLocationVal), destinationLocation(destinationLocationVal),
        departureTime(departureTimeVal), date(dateVal), estimateDuration(estimateDurationVal),
        contributionPerPassenger(contributionPerPassengerVal),
        minimumPassengerRating(minimumPassengerRatingVal),
        cancelFlag(cancelFlagVal), fullyBooked(false), idCP(idCPVal), IDowner(IDowner) {}

               
string CarpoolListing::getID() const { return idCP; }          
string CarpoolListing::getVehicleModel() const { return vehicleModel; }
string CarpoolListing::getVehicleColor() const { return  vehicleColor; }
string CarpoolListing::getPlateNumber() const { return plateNumber; }
string CarpoolListing::getEstimateDuration() const { return estimateDuration; }
bool CarpoolListing::getfullyBooked() const { return fullyBooked; }
bool CarpoolListing::getCancelFlag() const { return cancelFlag; }
 
int CarpoolListing::getAvailableSeats() const { return availableSeats; }
string CarpoolListing::getDepartureTime() const { return departureTime; }
string CarpoolListing::getDepartureLocation() const { return departureLocation; }
string CarpoolListing::getDestinationLocation() const { return destinationLocation; }
string CarpoolListing::getDate() const { return date; }
float CarpoolListing::getMinimumPassengerRating() const { return minimumPassengerRating; }
int CarpoolListing::getContributionPerPassenger() const { return contributionPerPassenger; }
string CarpoolListing::getIDowner() const {return IDowner;}


void CarpoolListing::setAvailableSeat(int seats) { 
    this->availableSeats = seats; 
}

void CarpoolListing::rejectRequest(Booking* booking) {
    auto it = find(passengerRequests.begin(), passengerRequests.end(), booking);
    if (it != passengerRequests.end()) {
        passengerRequests.erase(it);  // Correctly erase the booking from the vector
        cout << "Booking rejected and removed from CarpoolListing.\n";
    } else { 
        cout << "!!! Booking not found in system !!!\n";
    }
}

