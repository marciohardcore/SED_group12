#include <iostream>
#include "..\lib\Booking.h"
#include "..\lib\User.h"

using std::string;
using std::cout;

Booking::Booking(std::string cpidVal, std::string owneridVal, std::string uidVal, int statusValue = 1)
    : cpid(cpidVal), ownerid(owneridVal), uid(uidVal), statuss(statusValue){}

std::string Booking::getCPID() const{return cpid;};
std::string Booking::getPassengerID() const{return uid;};

std::string Booking::getOwnerID() const{return ownerid;};
int Booking::getStatusInfo()const {return statuss;};
void Booking::setStatusInfor(int statusVal){
    this->statuss = statusVal;
}
