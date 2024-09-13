#include <iostream>
#include "..\lib\booking.h"
#include "..\lib\member.h"
#include "..\lib\User.h"

using std::string;
using std::cout;

Booking::Booking(std::string cpidVal, std::string owneridVal, std::string uidVal, int statusValue = 1)
    : cpid(cpidVal), ownerid(owneridVal), uid(uidVal), statuss(statusValue){}


void Booking::cancel() {
    if (status == "pending") {
        status = "cancelled";
        cout << "Booking has been cancelled." << std::endl;
    } else {
        cout << "Booking cannot be cancelled. Status: " << status << std::endl;
    }
}

void Booking::viewStatus() const {
    cout << "The current booking status is: " << status << std::endl;
}

string Booking::getStatus() const { return status; }

std::string Booking::getBookingDate() const{return date; };
std::string Booking::getBookingTime() const{return time; };
//duy test
std::string Booking::getDriverName() const{
    //truy từ ID xe ra ID driver
    return "";
    // return user.getFullName(); 
};

std::string Booking::getDeparture() const{
    //lấy data từ file .dat
    return "";
    // return user.getFullName(); 
};

std::string Booking::getDestination() const{
    //lấy data từ file .dat
    return "";
    // return user.getFullName(); 
};

std::string Booking::getEstimatedDuration() const{
    //lấy data từ file .dat
    return "";
    // return user.getFullName(); 
};

std::string Booking::getBookingID() const{return BookingID;};
std::string Booking::getCPID() const{return cpid;};
std::string Booking::getPassengerID() const{return uid;};

std::string Booking::getOwnerID() const{return ownerid;};
int Booking::getStatusInfo()const {return statuss;};
void Booking::setStatusInfor(int statusVal){
    this->statuss = statusVal;
}
