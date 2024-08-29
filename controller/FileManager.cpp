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
    void saveUser(User &user); // DONE

    //save 1 carpoolListing to the file after sign up
    void saveCarpoolListing(CarpoolListing& carpoolInfo); // DONE
    void deleteCarpoolListing(CarpoolListing &item);//parameter: CLID

    //return array of user after being called
    std::vector<User> loadUser(); // DONE
    User FileManager::loadSingleUser(std::string name, std::string password);
    std::vector<CarpoolListing> loadCarpoolListing();

    void saveData();
    void reloadData();    
};
std::string getFilePath(const std::string &fileName){
    return PATH + fileName;
}

//DONE
void FileManager::saveUser(User &user){
    std::ofstream user_file;
    std::string file_path = getFilePath(USER);
    user_file.open(file_path, std::ios::out | std::ios::app);
    if (!user_file.is_open()){
        std::cerr << "File not found\n";
    }
    user_file  /*<< user.id << ","*/ 
                << user.getUserName() << "," 
                << user.getPassword() << "," 
                << user.getFullName() << "," 
                << user.getPhoneNumber() << "," 
                << user.getEmail() << ","  
                //<< user.getIDtype() << ","  
                //<< user.getPassportNumber() << ","  
                << user.getCreditPoint() << "," 
                << user.getRatingScore() << "," 
                << std::endl;
    user_file.close();
    std::cout <<"save successfully\n";
}

// DONE
void FileManager::saveCarpoolListing(CarpoolListing& carpoolInfo){
    std::ofstream carpool_file;
    std::string file_path = getFilePath(CARPOOL);
    carpool_file.open(file_path, std::ios::out | std::ios::app);
    if (!carpool_file.is_open()){
        std::cerr << "File not found\n";
    }

    carpool_file << carpoolInfo.getID() << ","
                 << carpoolInfo.getVehicleModel() << ","
                 << carpoolInfo.getVehicleColor() << ","
                 << carpoolInfo.getPlateNumber() << ","
                 << carpoolInfo.getAvailableSeats() << ","
                 << carpoolInfo.getDepartureLocation() << ","
                 << carpoolInfo.getDestinationLocation() << ","
                 << carpoolInfo.getDepartureTime() << ","
                 << carpoolInfo.getDate() << ","
                 << carpoolInfo.getEstimateDuration() << ","
                 << carpoolInfo.getContributionPerPassenger() << ","
                 << carpoolInfo.getMinimumPassengerRating() << ","
                 << carpoolInfo.getCancelFlag() << std::endl;
    carpool_file.close();
    std::cout <<"save successfully";
}

//load method DONE
std::vector<User> FileManager::loadUser(){
    std::ifstream user_file;
    std::string file_path = getFilePath(USER);
    user_file.open(file_path, std::ios::in);

    if (!user_file.is_open()) {
        std::cerr << "File not found\n";
    }

    std::string id, username, password, fullname, phone_number, email;
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
        user_file >> creditpoint;
        user_file.ignore(1, ',');
        user_file >> rating_score;
        user_file.ignore(1, '\n');

        // User user(id, username, password, phone_number, email, creditpoint, rating_score);
        User user(username, password, fullname, phone_number, email, creditpoint, rating_score);
        loadUser.push_back(user);
    }
    user_file.close();
    return loadUser;

}

User FileManager::loadSingleUser(std::string name, std::string password){
    std::ifstream user_file;
    std::string file_path = getFilePath(USER);
    user_file.open(file_path, std::ios::in);

    if (!user_file.is_open()) {
        std::cerr << "File not found\n";
    }

    std::string id, username, password, fullname, phone_number, email;
    int creditpoint;
    float rating_score;

    while (user_file.peek() != EOF){
        getline(user_file, id, ',');
        getline(user_file, username, ',');
        getline(user_file, password, ',');
        getline(user_file, fullname, ',');
        getline(user_file, phone_number, ',');
        getline(user_file, email, ',');
        user_file >> creditpoint;
        user_file.ignore(1, ',');
        user_file >> rating_score;
        user_file.ignore(1, '\n');

        // User user(id, username, password, phone_number, email, creditpoint, rating_score);
        if (name == username){
            User user(username, password, fullname, phone_number, email, creditpoint, rating_score);
            return user;
        }
    }
    user_file.close();

}


std::vector<CarpoolListing> FileManager::loadCarpoolListing() {
    std::ifstream carpool_file;
    std::string file_path = getFilePath(CARPOOL);
    carpool_file.open(file_path, std::ios::in);

    if (!carpool_file.is_open()) {
        std::cerr << "File not found\n";
        // Return an empty vector if the file cannot be opened
        return std::vector<CarpoolListing>();
    }

    std::vector<CarpoolListing> carpoolListings;
    std::string idCP, vehicleModel, vehicleColor, plateNumber, departureLocation, destinationLocation, departureTime, date, estimateDuration;
    int availableSeats, contributionPerPassenger;
    float minimumPassengerRating;
    bool cancelFlag;

    while (carpool_file.peek() != EOF) {
        // Assuming the file has all these fields separated by commas
        getline(carpool_file, idCP, ',');
        getline(carpool_file, vehicleModel, ',');
        getline(carpool_file, vehicleColor, ',');
        getline(carpool_file, plateNumber, ',');
        carpool_file >> availableSeats;
        carpool_file.ignore(1, ',');
        getline(carpool_file, departureLocation, ',');
        getline(carpool_file, destinationLocation, ',');
        getline(carpool_file, departureTime, ',');
        getline(carpool_file, date, ',');
        getline(carpool_file, estimateDuration, ',');
        carpool_file >> contributionPerPassenger;
        carpool_file.ignore(1, ',');
        carpool_file >> minimumPassengerRating;
        carpool_file.ignore(1, ',');
        carpool_file >> cancelFlag;
        carpool_file.ignore(1, '\n');

        // Create a CarpoolListing object and add it to the vector
        CarpoolListing carpool(idCP, vehicleModel, vehicleColor, plateNumber, availableSeats, 
                               departureLocation, destinationLocation, departureTime, 
                               date, estimateDuration, contributionPerPassenger, 
                               minimumPassengerRating, cancelFlag);

        carpoolListings.push_back(carpool);
    }

    carpool_file.close();
    return carpoolListings;
}

void FileManager::deleteCarpoolListing(CarpoolListing& item){
    std::ifstream carpool_file;
    std::string file_path = getFilePath(CARPOOL);
    carpool_file.open(file_path, std::ios::in | std::ios::app);

    if (!carpool_file.is_open()){
        std::cerr << "File not found";
    }
    check = items.getID();
    vector <CarpoolListing> list;
    //list = .loadCarpoolListing();
    while (std::getline())
}


// //to update the data
// void FileManager::saveData(){}

// //read and write to the file in the real time
// void FileManager::reloadData(){}

int main(){
    FileManager fileManager;

    // Load and display users from the file
    fileManager.loadUser();

    return 0;

}











//carpool_listing.dat
// void FileManager::saveCarInfo(CarInfo* carinfo /*, CPID*/){
//     std::ofstream user_file;
//     std::string file_path = getFilePath(CARINFO);
//     user_file.open(file_path, std::ios::out | std::ios::app);
//     if (!user_file.is_open()){
//         std::cerr << "File not found\n";
//     }
//     user_file  /*<< user.id << ","*/ 
//                 << user.getUserName() << "," 
//                 << user.getPassword() << "," 
//                 << user.getFullName() << "," 
//                 << user.getPhoneNumber() << "," 
//                 << user.getEmail() << ","  
//                 << user.getCreditPoint() << "," 
//                 << user.getRatingScore() << "," 
//                 << std::endl;
//     user_file.close();
//     std::cout <<"save successfully";
// }
//
//}