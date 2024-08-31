#include <iostream>
#include <fstream>  
#include <string>
#include <vector>
#include "..\lib\User.h"
#include "..\lib\CarpoolListing.h"

#pragma once


const std::string PATH = "../data/";
const std::string USER = "user.dat";
const std::string CARPOOL = "carpool.dat";
const std::string CARINFO = "carinfo.dat";

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
    std::vector<User> loadUser(); // DONE

    std::vector<CarpoolListing> loadCarpoolListing();
    //void saveCarpoolListing(CarpoolListing& carpoolInfo); // DONE
    //void deleteCarpoolListing(CarpoolListing &item);//parameter: CLID    
    

    // void saveData();
    // void reloadData(std::string nameVal, std::string pwdVal);    
};
std::string getFilePath(const std::string &fileName);