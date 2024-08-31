#include <iostream>
#include <fstream>
#include <vector>

#include "..\lib\GuestView.h"
#include "..\lib\FileManager.h"
#include "..\lib\CarpoolListing.h"

using std::ifstream;

void GuestView::displayCarpoolDetails(){
    std::vector <CarpoolListing> listings;
    FileManager listing;
    listings = listing.loadCarpoolListing();
    int i = 0;
    std::cout << "Available carpool listing: \n";
    for (auto list : listings){
        i += 1;
        if (list.getMinimumPassengerRating() <= 3){
            std::cout   << "Listing "<< i << ":"
                        << "<" << list.getDate() << ">" 
                        << "<" << list.getDepartureTime() << ">"
                        << "<" << list.getDepartureLocation() << ">"
                        << "<" << list.getDestinationLocation() << ">"
                        << "<" << list.getAvailableSeats() << ">"
                        << std::endl;
        }
    }
    return;
}