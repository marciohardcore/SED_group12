#include <iostream>
#include <fstream>
#include <vector>
using std::ifstream;

const std::string PATH = "../data/";
const std::string USER = "user.dat";
const std::string CARPOOL = "carpool.dat";


class GuestView{
public:
    void displayCarpoolDetails(){
        std::vector <CarpoolListing> listings;
        FileManager listing;
        listings = listing.loadCarpoolListing();
        int i = 0;
        for (auto list : listing){
            i += 1;
            if (list.getRatingPoint <= 3){
                std::cout   << "Listing "<< i << ":"
                            << "<" << list.getDate() << ">" 
                            << "<" << list.getDepartureTime() << ">"
                            << "<" << list.getDepartureLocation() << ">"
                            << "<" << list.getDestinationLocation() << ">"
                            << "<" << list.getAvailableSeats() << ">";
            }
        }
    }

    void displayBookingDetails(){
        
    }
};