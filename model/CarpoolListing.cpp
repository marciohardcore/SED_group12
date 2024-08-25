#include <iostream>

class CarpoolListing{
private:
    Member* driver;
    CarInfo* car_info;
    scheduleInfo* schedule_info;
    // ... //
public:
    //constructor
    CarpoolListing(){}
    
    void acceptRequest(Booking* booking){
    
    }

    // true or false
    void rejectRequest(){

    }   
    void unList(){

    } 
    void viewRequest(){

    }
    friend class Member;
    friend class CarInfo;
    friend class scheduleInfo;
};