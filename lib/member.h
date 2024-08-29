#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class CarpoolListing;  // Forward declaration
class Booking;         // Forward declaration

class Member {
private:
    // Attributes
    bool isVerified;
    std::vector<CarpoolListing*> carpoolListings;
    std::vector<Booking*> bookings;
public:
    // Methods
    void createCarpoolListing(CarpoolListing* listing); //done
    bool unlistCarpoolListing(CarpoolListing* listing); // done
    //carpool controller void searchAndbookCarpool(CarpoolListing* listing); /*  phải lấy data của tất cả listing trong hệ thống để show ra và search
                                                            //based on departure location,destination location, and date */
    bool cancelBooking(Booking* booking); // done
    void rateDriver(CarpoolListing* listing); // done
    void ratePassenger(Booking* booking); // done
    void viewDashboard();  // done
};
