#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>

#ifndef HGUARD100
#define HGUARD100

class IDgenerator {
public:
    std::string generateUserID();
    std::string generateCarpoolListingID();
    std::string generateBookingID();
    std::string generate_capcha();
};

#endif