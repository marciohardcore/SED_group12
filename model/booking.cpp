#include <iostream>

using std::string;
using std::cout;

class Booking: public Member{
private:
    //Member *passenger;
    //CarpoolListing *carpoolListing;
    string status;
    string date;
    string time;
    string BookingID;
public:
    //cancel booking -> user bi anh huong
    //pull the user trigger
    void cancel(){
        cout << "cancelled by driver";
    }
    void viewStatus(){
        
    }
};
int main(){

}
    // bool cancel(){
    //     //check is in the filemanager or system
    //     if (check(BookingID) == true){ // already booked
    //         cout << "Already confirmed, cannot cancel";
    //         return false;
    //     }
    //     else{
    //         //unlist from booking
    //     }
    // }
