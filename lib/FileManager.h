#include <iostream>
#include <fstream>  
#include <string>
#include <vector>
#include "..\lib\User.h"


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
    //save 1 user to the file after sign up
    void saveUser(User user); // DONE
    User loadSingleUser(std::string nameVal, std::string pwdVal);
    //save 1 carpoolListing to the file after sign up
    
    //void saveCarpoolListing(CarpoolListing& carpoolInfo); // DONE
    //void deleteCarpoolListing(CarpoolListing &item);//parameter: CLID

    //return array of user after being called
    
    std::vector<User> loadUser(); // DONE
    
    void saveAllUsers(std::vector<User> users);
    //std::vector<CarpoolListing> loadCarpoolListing();

    // void saveData();
    // void reloadData(std::string nameVal, std::string pwdVal);    
};
std::string getFilePath(const std::string &fileName);