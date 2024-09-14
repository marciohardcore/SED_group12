#ifndef CARPOOLLISTING_H
#define CARPOOLLISTING_H
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Booking; // Forward declaration

class CarpoolListing {
private:
    // Member* driver;
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
    string IDowner;
public:
    // Constructor
    CarpoolListing();               
    CarpoolListing(string idCPVal, 
                    string vehicleModelVal, string vehicleColorVal,
                    string plateNumberVal, int availableSeatsVal,
                    string departureLocationVal, string destinationLocationVal ,
                    string departureTimeVal , string dateVal ,
                    string estimateDurationVal , int contributionPerPassengerVal ,
                    float minimumPassengerRatingVal , bool cancelFlag,string IDowner );
    
    // Getters
    string getID() const;
    string getVehicleModel() const;
    string getVehicleColor() const;
    string getPlateNumber() const;
    string getEstimateDuration() const;
    bool getfullyBooked() const;
    bool getCancelFlag() const;
    
    int getAvailableSeats() const;
    string getDepartureTime() const;
    string getDepartureLocation() const;
    string getDestinationLocation() const;
    string getDate() const;
    float getMinimumPassengerRating() const;
    int getContributionPerPassenger() const;
    string getIDowner() const;

    // Setters
    void setAvailableSeat(int seats);
    void rejectRequest(Booking* booking);

    
};

#endif // CARPOOLLISTING_H
