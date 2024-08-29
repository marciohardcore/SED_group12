#include <iostream>
#include <vector>
#include <algorithm>
#include "..\lib\UserView.h"


class UserView : public User {
public:
    // Constructor that calls the User constructor
    UserView(string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int credits)
        : User(uName, pwd, fName, pNumber, mail, idT, idNum, credits) {}

    // Method to view the user profile
    void displayUserProfile(User* user) 
    {
        cout << "User Profile:\n";
        cout << "Your Username: " << user->getUserName() << "\n";
        cout << "Your Full Name: " << user->getFullName() << "\n";
        cout << "Your Phone Number: " << user->getPhoneNumber() << "\n";
        cout << "Your Email: " << user->getEmail() << "\n";
        cout << "Your Credit Points: " << user->getCreditPoints() << "\n";
    }
    void displayCarpoolListings(std::vector <CarpoolListing*> listings){

    }
    void displayBookingDetails(std::vector <Booking*> bookings){

    }
    void displayDashboard(Member* member){

    }
}
