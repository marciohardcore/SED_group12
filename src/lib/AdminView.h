#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <string>
#include <vector>
#include "FileManager.h" // Ensure that FileManager, User, and CarpoolListing headers are included.
#include "User.h"
#include "CarpoolListing.h"

class AdminView {
public:
    // Displays information of all users
    void displayAllUsers();

    // Displays information of all carpools
    void displayAllCarpools();
};

#endif // ADMINVIEW_H
