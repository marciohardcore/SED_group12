#include <iostream>
#include <fstream>  
#include <string>
#include <vector>

#include "..\lib\FileManager.h"
#include "..\lib\User.h"
#define GREEN "\033[0;32m"
using namespace std;
class Member;
class Booking;
class CarpoolListing;

std::string getFilePath(const std::string &fileName){
    return PATH + fileName;
}


//DONE
void FileManager::saveUser( User user){
    std::fstream user_file;
    std::string file_path = getFilePath(USER);
    // std::string file_path = "../data/user.dat";

    user_file.open("../data/user.dat", std::ios::out | std::ios::app);
    if (!user_file.is_open()){
        std::cerr << "File not found\n";
        return;
    }
    user_file   << user.getUID() << ","
                << user.getUserName() << "," 
                << user.getPassword() << "," 
                << user.getFullName() << "," 
                << user.getPhoneNumber() << "," 
                << user.getEmail() << ","  
                << user.getIDtype() << ","  
                << user.getIDnum() << ","  
                << user.getCreditPoint()
                << std::endl;
    user_file.close();
    std::cout <<GREEN << "Save data to system! \n";
}

// DONE
// void FileManager::saveCarpoolListing(CarpoolListing& carpoolInfo){
//     std::ofstream carpool_file;
//     std::string file_path = getFilePath(CARPOOL);
//     carpool_file.open(file_path, std::ios::out | std::ios::app);
//     if (!carpool_file.is_open()){
//         std::cerr << "File not found\n";
//     }

//     carpool_file << carpoolInfo.getID() << ","
//                  << carpoolInfo.getVehicleModel() << ","
//                  << carpoolInfo.getVehicleColor() << ","
//                  << carpoolInfo.getPlateNumber() << ","
//                  << carpoolInfo.getAvailableSeats() << ","
//                  << carpoolInfo.getDepartureLocation() << ","
//                  << carpoolInfo.getDestinationLocation() << ","
//                  << carpoolInfo.getDepartureTime() << ","
//                  << carpoolInfo.getDate() << ","
//                  << carpoolInfo.getEstimateDuration() << ","
//                  << carpoolInfo.getContributionPerPassenger() << ","
//                  << carpoolInfo.getMinimumPassengerRating() << ","
//                  << carpoolInfo.getCancelFlag() << std::endl;
//     carpool_file.close();
//     std::cout <<"save successfully";
// }

//load method DONE
std::vector<User> FileManager::loadUser(){
    std::ifstream user_file;
    std::string file_path = getFilePath(USER);
    user_file.open(file_path, std::ios::in);

    if (!user_file.is_open()) {
        std::cerr << "File not found\n";
    }

    std::string id, username, password, fullname, phone_number, email, IDtype, IDnum;
    int creditpoint;
    float rating_score;
    std::vector<User> loadUser;


    while (user_file.peek() != EOF){
        getline(user_file, id, ',');
        getline(user_file, username, ',');
        getline(user_file, password, ',');
        getline(user_file, fullname, ',');
        getline(user_file, phone_number, ',');
        getline(user_file, email, ',');
        getline(user_file, IDtype, ',');
        getline(user_file, IDnum, ',');

        user_file >> creditpoint;
        user_file.ignore(1, ',');
        // user_file >> rating_score;
        // user_file.ignore(1, '\n');

        // User user(id, username, password, phone_number, email, creditpoint, rating_score);
        User user(id, username, password, fullname, phone_number, email, IDtype, IDnum, creditpoint);
        loadUser.push_back(user);
    }
    user_file.close();
    return loadUser;
}

User FileManager::loadSingleUser(std::string nameVal, std::string pwdVal){
    std::ifstream user_file;
    std::string file_path = getFilePath(USER);
    user_file.open(file_path, std::ios::in);

    if (!user_file.is_open()) {
        std::cerr << "File not found\n";
    }

    std::string id, username, password, fullname, phone_number, email, IDtype, IDnum;
    int creditpoint;
    float rating_score;
        
    int flag = 0;
    while (user_file.peek() != EOF){
        getline(user_file, id, ',');
        getline(user_file, username, ',');
        getline(user_file, password, ',');
        getline(user_file, fullname, ',');
        getline(user_file, phone_number, ',');
        getline(user_file, email, ',');
        getline(user_file, IDtype, ',');
        getline(user_file, IDnum, ',');

        user_file >> creditpoint;
        user_file.ignore(1, ',');
        // user_file >> rating_score;
        // user_file.ignore(1, '\n');

        // User user(id, username, password, phone_number, email, creditpoint, rating_score);
        if (nameVal == username && pwdVal == password){
            User user(id, username, password, fullname, phone_number, email, IDtype, IDnum, creditpoint);
            flag = 1;
            return user;
        }
    }
    if (flag == 0){
        User user("","","","","","","", 0);
        return user;
    }

    user_file.close();
}


// std::vector<CarpoolListing> FileManager::loadCarpoolListing() {
//     std::ifstream carpool_file;
//     std::string file_path = getFilePath(CARPOOL);
//     carpool_file.open(file_path, std::ios::in);

//     if (!carpool_file.is_open()) {
//         std::cerr << "File not found\n";
//         // Return an empty vector if the file cannot be opened
//         return std::vector<CarpoolListing>();
//     }

//     std::vector<CarpoolListing> carpoolListings;
//     std::string idCP, vehicleModel, vehicleColor, plateNumber, departureLocation, destinationLocation, departureTime, date, estimateDuration;
//     int availableSeats, contributionPerPassenger;
//     float minimumPassengerRating;
//     bool cancelFlag;

//     while (carpool_file.peek() != EOF) {
//         // Assuming the file has all these fields separated by commas
//         getline(carpool_file, idCP, ',');
//         getline(carpool_file, vehicleModel, ',');
//         getline(carpool_file, vehicleColor, ',');
//         getline(carpool_file, plateNumber, ',');
//         carpool_file >> availableSeats;
//         carpool_file.ignore(1, ',');
//         getline(carpool_file, departureLocation, ',');
//         getline(carpool_file, destinationLocation, ',');
//         getline(carpool_file, departureTime, ',');
//         getline(carpool_file, date, ',');
//         getline(carpool_file, estimateDuration, ',');
//         carpool_file >> contributionPerPassenger;
//         carpool_file.ignore(1, ',');
//         carpool_file >> minimumPassengerRating;
//         carpool_file.ignore(1, ',');
//         carpool_file >> cancelFlag;
//         carpool_file.ignore(1, '\n');

//         // Create a CarpoolListing object and add it to the vector
//         CarpoolListing carpool(idCP, vehicleModel, vehicleColor, plateNumber, availableSeats, 
//                                departureLocation, destinationLocation, departureTime, 
//                                date, estimateDuration, contributionPerPassenger, 
//                                minimumPassengerRating, cancelFlag);

//         carpoolListings.push_back(carpool);
//     }

//     carpool_file.close();
//     return carpoolListings;
// }

// void FileManager::deleteCarpoolListing(CarpoolListing& item){
//     std::ifstream carpool_file;
//     std::string file_path = getFilePath(CARPOOL);
//     carpool_file.open(file_path, std::ios::in | std::ios::app);

//     if (!carpool_file.is_open()){
//         std::cerr << "File not found";
//     }
//     check = items.getID();
//     vector <CarpoolListing> list;
//     //list = .loadCarpoolListing();
//     while (std::getline())
// }





