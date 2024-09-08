#pragma once
#include <iostream>
#include "..\lib\booking.h"
#include "..\lib\member.h"
#include "..\lib\User.h"


using std::string;
using std::cout;

class Booking: public Member{
private:
    Member *passenger;
    CarpoolListing *carpoolListing;
    string status;
    string date;
    string time;
    string BookingID;
    User user;

    //consider fix
    std::string cpid;
    std::string ownerid;
    std::string uid;
public:
    //cancel booking -> user bi anh huong
    //pull the user trigger
    Booking(std::string cpidVal, std::string owneridVal, std::string uidVal);
    // void Booking::cancel() {
    void cancel();

    void viewStatus() const;

    string getStatus() const;

    std::string getBookingDate() const;
    std::string getBookingTime() const;
    std::string getDriverName() const;
    std::string getDeparture() const;
    std::string getDestination() const;
    std::string getEstimatedDuration() const;
    
    std::string getBookingID() const;
    std::string getOwnerID() const;
    std::string getCPID() const;
    std::string getPassengerID() const;
};

