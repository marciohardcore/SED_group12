#include <iostream>
#include "..\lib\booking.h"
#include "..\lib\member.h"
#include "..\lib\User.h"

using std::string;
using std::cout;


// class Booking: public Member{
// private:
//     Member *passenger;
//     CarpoolListing *carpoolListing;
//     string status;
//     string date;
//     string time;
//     string BookingID;
    
// public:
//     //cancel booking -> user bi anh huong
//     //pull the user trigger

//     // void Booking::cancel() {
//     void cancel() {
//         if (status == "pending") {
//             status = "cancelled";
//             cout << "Booking has been cancelled." << std::endl;
//         } else {
//             cout << "Booking cannot be cancelled. Status: " << status << std::endl;
//         }
//     }

//     void viewStatus() const {
//         cout << "The current booking status is: " << status << std::endl;
//     }

//     string getStatus() const { return status; }
// };

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