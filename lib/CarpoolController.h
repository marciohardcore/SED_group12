// #ifndef CARPOOLCONTROLLER_H
// #define CARPOOLCONTROLLER_H

// #include <iostream>
// #include <vector>
// #include <string>
// #include "FileManager.h"  // Assuming FileManager is another class used for file operations
// // #include "Logger.h"       // Assuming Logger is another class used for logging
// #include "Member.h"       // Assuming Member is a class that represents a member/user
// #include "CarpoolListing.h" // Assuming CarpoolListing is the class representing the carpool listings
// // #include "Booking.h"      // Assuming Booking is the class representing a booking

#ifndef CARPOOLCONTROLLER_H
#define CARPOOLCONTROLLER_H

#include <iostream>
#include <vector>
#include <string>
#include "FileManager.h"  
#include "Member.h"      
#include "CarpoolListing.h"

using namespace std;

class CarpoolController {
private:
    FileManager filemanager;
    // Logger logger;

public:
    // Creates a new carpool listing and saves it
    void createCarpool();

    // Searches for carpools based on the provided criteria
    // vector<CarpoolListing*> searchCarpools(string location, string date, int minRating, int credits);

    // // Books a carpool for a passenger
    // Booking* bookCarpool(Member* passenger, CarpoolListing* listing);

    // // Manages carpool requests, allowing the user to accept or reject them
    // void manageCarpoolRequests(CarpoolListing* listing);

    // // Cancels a booking
    // void cancelBooking(Booking* booking);
};

#endif // CARPOOLCONTROLLER_H
