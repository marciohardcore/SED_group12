#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <..\lib\member.h>
void Member::createCarpoolListing(CarpoolListing* listing) {
    // lưu dô file
    carpoolListings.push_back(listing);
    std::cout << "Carpool listing created.\n";
}

bool Member::unlistCarpoolListing(CarpoolListing* listing) {
    for(int i = 0; i < carpoolListings.size(); i++){
        if(carpoolListings[i] == listing){
            carpoolListings.erase(carpoolListings.begin() + i);
            std::cout << "Carpool listing unlisted.\n";
            return true;
        }
    }
    std::cout << "Carpool listing not found.\n";
    return false;
}

// void Member::searchAndbookCarpool(Booking* booking) {
    
// }

void Member::cancelBooking(Booking* booking) {
    // Cancel the booking (set status to "cancelled")
    booking->cancel();

    // Remove the booking from the Member's bookings vector
    auto it = find(bookings.begin(), bookings.end(), booking);
    if (it != bookings.end()) {
        bookings.erase(it);
        cout << "Booking removed from Member's list.\n";
    } else {
        cout << "Booking not found in Member's list.\n";
    }
}


void Member::rateDriver(CarpoolListing* listing) {
    float score;
    std::string comment;

    // Prompt the user for a rating score
    do {
        std::cout << "Enter the rating score of carpoolListing (1 to 5): ";
        std::cin >> score;

        if (score < 1.0f || score > 5.0f) {
            std::cout << "Invalid score. Please enter a score between 1 and 5.\n";
        }

    } while (score < 1.0f || score > 5.0f); 

    std::cin.ignore();  

    // Prompt the user for a comment
    std::cout << "Enter the rating comment of carpoolListing: ";
    std::getline(std::cin, comment);

    listing.scores.push_back(score);    
    listing.comments.push_back(comment); 

    // Output to confirm the rating and comment have been added
    std::cout << "Rated driver with score: " << score << " and comment: " << comment << "\n";

}

void Member::ratePassenger(Booking* booking) {
    float score;
    std::string comment;

    do {
        std::cout << "Enter the rating score of booking (1 to 5): ";
        std::cin >> score;

        if (score < 1.0f || score > 5.0f) {
            std::cout << "Invalid score. Please enter a score between 1 and 5.\n";
        }

    } while (score < 1.0f || score > 5.0f); // Repeat until a valid score is entered

    std::cin.ignore();  
    // Prompt the user for a comment
    std::cout << "Enter the rating comment of booking: ";
    std::getline(std::cin, comment);

    booking.scores.push_back(score);   
    booking.comments.push_back(comment); 

    // Output to confirm the rating and comment have been added
    std::cout << "Rated booking with score: " << score << " and comment: " << comment << "\n";
}


void Member::viewDashboard() {

    if (carpoolListings.empty() && Bookings.empty()) {
        std::cout << "No active carpool listings or bookings available.\n";
        return;
    }

    if (!carpoolListings.empty()) {
        std::cout << "Active carpool listings\n";
        std::cout << "------------------------\n";

        for (int i = 0; i < carpoolListings.size(); ++i) {
            std::cout << "Listing " << (i + 1) << ": "
                      << "<" << carpoolListings[i]->date << "> "
                      << "<" << carpoolListings[i]->time << "> "
                      << "<" << carpoolListings[i]->departure << "> "
                      << "<" << carpoolListings[i]->destination << "> "
                      << "<" << carpoolListings[i]->seatsAvailable << ">\n";
        }
        
        std::cout << "\n";  // Add a newline for separation
    }

    if (!Bookings.empty()) {
        std::cout << "Active bookings\n";
        std::cout << "---------------\n";

        for (int i = 0; i < bookings.size(); ++i) {
            std::cout << "Booking " << (i + 1) << ": "
                      << "<" << bookings[i]->date << "> "
                      << "<" << bookings[i]->time << "> "
                      << "<" << bookings[i]->departure << "> "
                      << "<" << bookings[i]->destination << "> "
                      << "<" << bookings[i]->estimatedDuration << "> "
                      << "<" << bookings[i]->driverName << "> "
                      << "<" << bookings[i]->status << ">\n";
        }
    }
}


