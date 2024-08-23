#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>

class IDgenerator {
public:
    std::string generateUserID() {
        std::random_device random;
        std::mt19937_64 generator(random());  // Use 64-bit generator

        uint64_t id = generator(); 

        std::stringstream ss;
        ss << std::hex << "UID" << std::setw(16) << std::setfill('0') << id;  // 16 characters for 64-bit

        return ss.str();
    }

    std::string generateCarpoolListingID() {
        std::random_device random;
        std::ranlux48_base generator(random());  // Use 48-bit generator

        uint64_t id = generator(); 

        std::stringstream ss;
        ss << std::hex << "CLID" << std::setw(12) << std::setfill('0') << id;  // 12 characters for 48-bit

        return ss.str();
    }

    std::string generateBookingID() {
        std::random_device random;
        std::ranlux48_base generator(random());  // Use 48-bit generator

        uint64_t id = generator(); 

        std::stringstream ss;
        ss << std::hex << "BID" << std::setw(12) << std::setfill('0') << id;  // 12 characters for 48-bit

        return ss.str();
    }
};

int main() {
    IDgenerator generator;
    std::cout << generator.generateUserID() << std::endl;
    std::cout << generator.generateCarpoolListingID() << std::endl;
    std::cout << generator.generateBookingID() << std::endl;
    return 0;
}
