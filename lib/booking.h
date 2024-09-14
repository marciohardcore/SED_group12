#pragma once
#include <iostream>
#include "..\lib\Booking.h"
#include "..\lib\User.h"
#include "..\lib\CarpoolListing.h"


using std::string;
using std::cout;

class Booking{
private:
    std::string uid;
    std::string cpid;
    std::string ownerid;
    int statuss;
public:
    //cancel booking -> user bi anh huong
    //pull the user trigger
    Booking(std::string cpidVal, std::string owneridVal, std::string uidVal, int statusValue);
    Booking (){};

    std::string getOwnerID() const;
    std::string getCPID() const;
    std::string getPassengerID() const;
    int getStatusInfo()const;
    void setStatusInfor(int statusVal);
};

