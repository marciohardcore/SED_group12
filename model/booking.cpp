#include <iostream>

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
    void Booking::cancel() {
    if (status == "pending") {
        status = "cancelled";
        cout << "Booking has been cancelled." << endl;
    } else {
        cout << "Booking cannot be cancelled. Status: " << status << endl;
    }
}

    void viewStatus() const {
        cout << "The current booking status is: " << status << endl;
    }

    string getStatus() const { return status; }
};

