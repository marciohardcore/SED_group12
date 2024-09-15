#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cstdlib>  // For system()

#include "..\lib\InputValidator.h"
#include "..\lib\IDgenerator.h"
#include "..\lib\FileManager.h"

#include "..\lib\User.h"
#include "..\lib\UserView.h"
#include "..\lib\UserController.h"
#include "..\lib\GuestView.h"

#include "..\lib\CarpoolController.h"
#include "..\lib\CarpoolListing.h"

#include "..\lib\RatingSystem.h"
#include "..\lib\AdminView.h"

#include "..\lib\IdentityVerifier.h"

using namespace std;

// Console text formatting
#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"


#ifndef MENU_H
#define MENU_H

class Menu{
public:
    char coordinate();
    void printHeader(const std::string& title);
    void introduction();
    void profileManagement(const std::string& username, const std::string& password);
    void CarpoolManagement(const std::string& username, const std::string& password);
    void showAllCarpoolListings();
    void browseAndBookCarpoolListingsByCriteria(const User* user);
    void rate_driver(std::map <int, string>& rating_map);
    void cancel_request(const User &user);
    void requestState(const User &user);
    void BookingManagement(const std::string& username, const std::string& password);
    void viewMyRating(std::string& username, std::string& password);
    void memberUtils(std::string username, std::string password);
    void member();
    void memberOption();
    void newRegister();
    void guestOption();
    void admin();
    void exitProgram();
    void run_program();
};
#endif
