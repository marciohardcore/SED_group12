#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>  
#include <string>
#include <vector>
#include "..\lib\User.h"
#include "..\lib\CarpoolListing.h"
#include "..\lib\booking.h"
#include "..\lib\RatingSystem.h"

#pragma once


const std::string PATH = "../data/";
const std::string USER = "user.dat";
const std::string CARPOOL = "carpool.dat";
const std::string RATING = "rating.dat";
const std::string REQUEST = "request.dat";


using namespace std;
class Member;
class Booking;
class CarpoolListing;
//class User;

class FileManager{
public:
    void saveUser(User user); // DONE
    void saveAllUsers(std::vector<User> users);
    User loadSingleUser(std::string nameVal, std::string pwdVal);
    User loadSingleUser(std::string idVal);

    std::vector<User> loadUser(); // DONE

    std::vector<CarpoolListing> loadCarpoolListing();
    void saveCarpoolListing(CarpoolListing carpoolInfo); // DONE
    // void deleteCarpoolListing(CarpoolListing &item);//parameter: CLID    
    //CarpoolListing loadSingleCarpool(string CarpoolID);
    void saveAllCarpoolListing(const std::vector<CarpoolListing>& carpoolList);
    // vector<CarpoolListing> loadCarpool();
    void saveRating(std::string userID,double score,std::vector <std::string> comments);
    void loadRating();
    // void saveData();
    // void reloadData(std::string nameVal, std::string pwdVal);    
    void pullRequestCarpool(CarpoolListing carpool, User user);
    std::vector<Booking> loadRequest();
    void saveRequest(const Booking& request);
    void saveAllRequest(vector<Booking> &requestList);
};
std::string getFilePath(const std::string &fileName);
#endif
