#include <iostream>
#include <vector>
#include <algorithm>

#include "..\lib\UserView.h"
#include "..\lib\User.h"
#include "..\lib\FileManager.h"


// Constructor that calls the User constructor
// UserView(string uName, string pwd, string fName, string pNumber, string mail, string idT, string idNum, int credits)
//     : User(uName, pwd, fName, pNumber, mail, idT, idNum, credits) {};

UserView(string name, string password){};

// Method to view the user profile
void UserView::displayUserProfile(string name, string password) 
{
    User user;
    FileManager user1;
    user = user1.loadSingleUser(name, password);
    cout << "User Profile:\n";
    cout << "Your Username: " << user.getUserName() << "\n";
    cout << "Your Full Name: " << user.getFullName() << "\n";
    cout << "Your Phone Number: " << user.getPhoneNumber() << "\n";
    cout << "Your Email: " << user.getEmail() << "\n";
    cout << "Your Credit Points: " << user.getCreditPoint() << "\n";
}
// void UserView::displayCarpoolListings(std::vector <CarpoolListing*> listings){

// }
// void UserView::displayBookingDetails(std::vector <Booking*> bookings){

// }
// void UserView::displayDashboard(Member* member){

// }

