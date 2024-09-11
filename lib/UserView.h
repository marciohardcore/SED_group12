#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\User.h"

#ifndef USER_VIEW
#define USER_VIEW

class UserView : public User{
public:
    // Constructor that calls the User constructor
    // UserView(string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int credits);
    UserView(string name, string password);
    // Method to view the user profile
    void displayUserProfile( std::string name,  std::string password);
    // void displayCarpoolListings(std::vector <CarpoolListing*> listings);
    // void displayBookingDetails(std::vector <Booking*> bookings);
    // void displayDashboard(Member* member);
};

#endif