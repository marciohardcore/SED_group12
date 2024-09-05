#pragma once
#include <iostream>
#include "..\lib\booking.h"
#include "..\lib\member.h"

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
    
public:
    //cancel booking -> user bi anh huong
    //pull the user trigger

    // void Booking::cancel() {
    void cancel();

    void viewStatus() const;

    string getStatus() const;
};

