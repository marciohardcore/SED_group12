#include <iostream>
#include <vector>
class CarpoolController{
public:
    void createCarpool(Member* driver, CarpoolListing* listing){

    }
    
    std::vector<CarpoolListing*> searchCarpools(std::string location, std::string date, int minRating, int credits){

    }

    Booking* bookCarpool(Member* passenger, CarpoolListing* listing){

    }

    void manageCarpoolRequests(CarpoolListing* listing){

    }    
    void cancelBooking(Booking* booking){

    }
};