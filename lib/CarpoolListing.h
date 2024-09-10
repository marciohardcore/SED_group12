#ifndef CARPOOLLISTING_H
#define CARPOOLLISTING_H
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#include "..\lib\member.h"

class Member; // Forward declaration
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
    // CarpoolListing(Member* driverVal = nullptr,
    //                string vehicleModelVal = "", string vehicleColorVal = "",
    //                string plateNumberVal = "", int availableSeatsVal = 0,
    //                string departureLocationVal = "", string destinationLocationVal = "",
    //                string departureTimeVal = "", string dateVal = "",
    //                string estimateDurationVal = "", int contributionPerPassengerVal = 0,
    //                float minimumPassengerRatingVal = 0.0f, string idCPVal = "");
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
    // vector<Booking*> getPassengerRequests() const;
    // Member* getDriver() const;

    // Setters
    void setCancelFlag();
    void setFullyBooked();
    void setAvailableSeat(int seats);
    void rejectRequest(Booking* booking);

    
    // Member functions
    // void addRequest(Booking* booking);
    // void rejectAllRequests();
    // // void acceptRequest(Booking* booking);
    // void unlist();
    // void viewRequests() const;
};

#endif // CARPOOLLISTING_H
