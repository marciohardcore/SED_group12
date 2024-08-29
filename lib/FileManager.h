#include <iostream>
#include <fstream>  
#include <string>
#include <vector>

const std::string PATH = "../data/";
const std::string USER = "user.dat";
const std::string CARPOOL = "carpool.dat";
const std::string CARINFO = "carinfo.dat";

using namespace std;
class Member;
class Booking;
class CarpoolListing;
class User;

class FileManager{
public:
    //save 1 user to the file after sign up
    void saveUser( User user); // DONE

    //save 1 carpoolListing to the file after sign up
    
    //void saveCarpoolListing(CarpoolListing& carpoolInfo); // DONE
    //void deleteCarpoolListing(CarpoolListing &item);//parameter: CLID

    //return array of user after being called
    //std::vector<User> loadUser(); // DONE
    //User FileManager::loadSingleUser(std::string name, std::string password);
    //std::vector<CarpoolListing> loadCarpoolListing();

    // void saveData();
    // void reloadData();    
};
