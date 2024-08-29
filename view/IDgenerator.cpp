#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>
#include "..\lib\IDgenerator.h"

std::string IDgenerator::generateUserID() {
    std::random_device random;
    std::mt19937_64 generator(random());  // Use 64-bit generator

    uint64_t id = generator(); 

    std::stringstream ss;
    ss << std::hex << "UID" << std::setw(16) << std::setfill('0') << id;  // 16 characters for 64-bit

    return ss.str();
}

std::string IDgenerator::generateCarpoolListingID() {
    std::random_device random;
    std::ranlux48_base generator(random());  // Use 48-bit generator

    uint64_t id = generator(); 

    std::stringstream ss;
    ss << std::hex << "CLID" << std::setw(12) << std::setfill('0') << id;  // 12 characters for 48-bit

    return ss.str();
}

std::string IDgenerator::generateBookingID() {
    std::random_device random;
    std::ranlux48_base generator(random());  // Use 48-bit generator

    uint64_t id = generator(); 

    std::stringstream ss;
    ss << std::hex << "BID" << std::setw(12) << std::setfill('0') << id;  // 12 characters for 48-bit

    return ss.str();
}


