#include <iostream>
#include <fstream>  
#include <string>
#include <user.cpp>
const std::string PATH = "data/";
const std::string USER = "user.dat";
const std::string CARPOOL = "";
const std::string CARINFO = "";

class FileManager{
public:
    void getFilePath(); // DONE
    void saveUser(); // DONE

    void saveCarpoolListing();
    void deleteCarpoolListing();//parameter: CLID

    void loadUser();
    void loadCarpoolListing();

    void saveData();
    void reloadData();    
};
std::string getFilePath(const std::string &fileName){
    return PATH + fileName;
}
//contact with the files
//save method
//user_info.dat

void saveUser(User *user){
    std::ofstream user_file;
    std::string file_path = getFilePath(USER);
    user_file.open(file_path, std::ios::out);
    if (!user_file.is_open()){
        std::cerr << "File not found\n";
    }
    //user.get_id() ,...?
    user_file << user.id << "," << user.username << "," 
                << user.password << "," << user.fullname << "," 
                << user.phone_number << "," << user.email << "," 
                << user.creditpoint << "," << user.rating_score << std::endl;
    user_file.close();
    cout <<"save successfully";
}

//carpool_listing.dat
void saveCarInfo(CarInfo* carinfo /*, CPID*/){
    std::ofstream car;
    std::string file_path = getFilePath(CARINFO);
    car.open(file_path, std::ios::out);
    if (!car.is_open()){
        std::cerr << "File not found\n";
    }
    
    // std::string vehicleModel;
    // std::string vehicleColor;
    // std::string plateNumber;
    // int availableSeat;

    //user.get_id() ,...?
    car << user.id << "," << carinfo.vehicleModel << "," 
        << carinfo.vehicleColor << "," << carinfo.plateNumber << "," << carinfo.availableSeat << ","
        << std::endl;
    car.close();
    cout <<"save successfully";

}
void saveCarpoolListing(CarpoolListing* carpoolInfo){
    std::ofstream user_file;
    std::string file_path = getFilePath(CARPOOL);
    user_file.open(file_path, std::ios::out);
    if (!user_file.is_open()){
        std::cerr << "File not found\n";
    }
    // Member* driver;
    // CarInfo* car_info;
    // scheduleInfo* schedule_info;

    //member
    //car_info
    user_file << cpid << "," <<
    
    user_file.close();
    cout <<"save successfully";
    
}

//load method
void loadUser(){
    std::ifstream user_file;
    std::string file_path = "";

    user_file.open(file_path, std::ios::in);

    if (!user_file.is_open()) {
        std::cerr << "File not found\n";
    }

    while (user_file.peek() != EOF){
        getline(user_file, id, ',');
        getline(user_file, username, ',');
        getline(user_file, password, ',');
        getline(user_file, fullname, ',');
        getline(user_file, phone_number, ',');
        getline(user_file, email, ',');
        getline(user_file, creditpoint, ',');
        getline(user_file, rating_score, '\n');

        User user(id, username, password, phone_number, email, creditpoint, rating_score);
    }

    user_file.close();

}
void loadCarpoolListing(){
    std::ifstream user_file;
    std::string file_path = "";

    user_file.open(file_path, std::ios::in);

    if (!user_file.is_open()) {
        std::cerr << "File not found\n";
    }

    while (user_file.peek() != EOF){
        getline(user_file, id, ',');
        getline(user_file, username, ',');
        getline(user_file, password, ',');
        getline(user_file, fullname, ',');
        getline(user_file, phone_number, ',');
        getline(user_file, email, ',');
        getline(user_file, creditpoint, ',');
        getline(user_file, rating_score, '\n');

        User user(id, username, password, phone_number, email, creditpoint, rating_score);
    }

    user_file.close();

}

//to update the data
void saveData(){}

//read and write to the file in the real time
void reloadData(){}

