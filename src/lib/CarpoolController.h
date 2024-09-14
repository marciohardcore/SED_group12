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
#include "CarpoolListing.h"

using namespace std;

class CarpoolController {
private:
    FileManager filemanager;

public:
    // Creates a new carpool listing and saves it
    void createCarpool(const User* user);
    void viewCarpool(const User* user);
    void unlistCarpool(const User* user);
    void viewRequest(const User* user);

};

#endif // CARPOOLCONTROLLER_H
