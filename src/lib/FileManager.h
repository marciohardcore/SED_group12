#ifndef FILE_H
#define FILE_H

#pragma once
#include <iostream>
#include <fstream>  
#include <string>
#include <vector>
#include "..\lib\User.h"
#include "..\lib\CarpoolListing.h"
#include "..\lib\Booking.h"
#include "..\lib\RatingSystem.h"



const std::string PATH = "./data/";
const std::string USER = "user.dat";
const std::string CARPOOL = "carpool.dat";
const std::string RATING = "rating.dat";
const std::string REQUEST = "request.dat";


using namespace std;
class Booking;
class CarpoolListing;
//class User;

class FileManager{
public:
    void saveUser(const User &user); // DONE
    void saveAllUsers(std::vector<User*> &users);
    User* loadSingleUser(const std::string &nameVal,const std::string &pwdVal);
    User* loadSingleUser(const std::string &idVal);
    std::vector<User*> loadUser(); // DONE

    std::vector<CarpoolListing *> loadCarpoolListing(); // DONE
    void saveCarpoolListing(const CarpoolListing& carpoolInfo); // DONE
    void saveAllCarpoolListing(const std::vector<CarpoolListing*>& carpoolList);


    void saveRating(const RatingSystem& rating);            // Save a single rating to a file
    std::vector<RatingSystem*> loadRating(); 
    
     
    void pullRequestCarpool(const CarpoolListing* carpool, const User* user);
    std::vector<Booking*> loadRequest(); // DONE
    void saveRequest(const Booking* request);
    void saveAllRequest(const vector<Booking*> &requestList);
};
std::string getFilePath(const std::string &fileName);
#endif
