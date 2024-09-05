#include <iostream>
#include "..\lib\booking.h"
#include "..\lib\member.h"

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

