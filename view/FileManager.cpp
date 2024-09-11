#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

#include "..\lib\FileManager.h"
#include "..\lib\CarpoolListing.h"
#include "..\lib\booking.h"
#include "..\lib\User.h"
#include "..\lib\RatingSystem.h"

#define GREEN "\033[0;32m"
using namespace std;
class Member;
class Booking;

std::string getFilePath(const std::string &fileName)
{
    return PATH + fileName;
}

// DONE
void FileManager::saveUser(User user)
{
    std::fstream user_file;
    std::string file_path = getFilePath(USER);

    user_file.open("../data/user.dat", std::ios::out | std::ios::app);
    if (!user_file.is_open())
    {
        std::cerr << "File not found\n";
        return;
    }
    user_file << user.getUID() << ","
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
    // std::cout <<GREEN << "Save data to system! \n";
}

// DONE

void FileManager::saveAllUsers(std::vector<User> users)
{
    // Open the file in truncate mode to clear its contents
    std::ofstream outFile(PATH + USER, std::ios::trunc);
    if (!outFile)
    {
        std::cerr << "Failed to open the file for saving users.\n";
        return;
    }
    outFile.close(); // Close the file after clearing

    // Save each user to the file
    for (const auto &user : users)
    {
        saveUser(user); // Reuse the saveUser function to append each user
    }
}
// load method
User FileManager::loadSingleUser(const std::string nameVal, const std::string pwdVal)
{
    std::ifstream user_file;
    std::string file_path = getFilePath(USER); // Ensure this path is correct
    user_file.open(file_path, std::ios::in);   // Open for reading

    if (!user_file.is_open())
    {
        std::cerr << "File not found\n";
        return User(); // Return an empty or default User object
    }

    std::string id, username, password, fullname, phone_number, email, IDtype, IDnum;
    int creditpoint;

    while (getline(user_file, id, ',') &&
           getline(user_file, username, ',') &&
           getline(user_file, password, ',') &&
           getline(user_file, fullname, ',') &&
           getline(user_file, phone_number, ',') &&
           getline(user_file, email, ',') &&
           getline(user_file, IDtype, ',') &&
           getline(user_file, IDnum, ',') &&
           (user_file >> creditpoint))
    {

        user_file.ignore(1, ','); // Skip the comma after the integer

        // Check if the credentials match
        if (nameVal == username && pwdVal == password)
        {
            user_file.close();
            return User(id, username, password, fullname, phone_number, email, IDtype, IDnum, creditpoint);
        }
    }

    // If no matching user was found
    user_file.close();
    return User(); // Return an empty or default User object
}

std::vector<User> FileManager::loadUser()
{
    std::ifstream user_file;
    std::vector<User> loadUser;

    std::string file_path = getFilePath(USER); // Ensure this path is correct
    user_file.open(file_path, std::ios::in);   // Open for reading

    if (!user_file.is_open())
    {
        std::cerr << "File not found\n";
        return loadUser; // Return an empty or default User object
    }

    std::string id, username, password, fullname, phone_number, email, IDtype, IDnum;
    int creditpoint;

    while (getline(user_file, id, ',') &&
           getline(user_file, username, ',') &&
           getline(user_file, password, ',') &&
           getline(user_file, fullname, ',') &&
           getline(user_file, phone_number, ',') &&
           getline(user_file, email, ',') &&
           getline(user_file, IDtype, ',') &&
           getline(user_file, IDnum, ',') &&
           (user_file >> creditpoint))
    {

        user_file.ignore(1, ','); // Skip the comma after the integer

        User user(id, username, password, fullname, phone_number, email, IDtype, IDnum, creditpoint);
        loadUser.push_back(user);
    }

    // If no matching user was found
    user_file.close();
    return loadUser; // Return an empty or default User object
}

// void reloadData(std::string nameVal, std::string pwdVal)

std::vector<CarpoolListing> FileManager::loadCarpoolListing()
{
    std::ifstream carpool_file;
    std::vector<CarpoolListing> carpoolListings;

    std::string file_path = getFilePath(CARPOOL);
    carpool_file.open(file_path, std::ios::in);

    if (!carpool_file.is_open())
    {
        std::cerr << "File not found\n";
        return carpoolListings;
    }

    // 13 element
    std::string idCP, vehicleModel, vehicleColor, plateNumber, departureLocation, destinationLocation, departureTime, date, estimateDuration, IDowner;
    int availableSeats, contributionPerPassenger;
    float minimumPassengerRating;
    bool cancelFlag;

    while (carpool_file.peek() != EOF)
    {
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
        carpool_file.ignore(1, ',');
        carpool_file >> IDowner;
        carpool_file.ignore(1, '\n');
        // Create a CarpoolListing object and add it to the vector // 13
        CarpoolListing carpool(idCP, vehicleModel, vehicleColor, plateNumber, availableSeats,
                               departureLocation, destinationLocation, departureTime,
                               date, estimateDuration, contributionPerPassenger,
                               minimumPassengerRating, cancelFlag, IDowner);

        carpoolListings.push_back(carpool);
    }

    carpool_file.close();
    return carpoolListings;
}

void FileManager::saveCarpoolListing(CarpoolListing carpoolInfo)
{
    std::ofstream carpool_file;
    std::string file_path = getFilePath(CARPOOL);
    carpool_file.open("../data/carpool.dat", std::ios::out | std::ios::app);
    if (!carpool_file.is_open())
    {
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
                 << carpoolInfo.getCancelFlag() << ","
                 << carpoolInfo.getIDowner()
                 << std::endl;
    carpool_file.close();
    // std::cout <<"save successfully";
}

void FileManager::saveAllCarpoolListing(const std::vector<CarpoolListing> &carpoolList)
{
    // Open the file in truncate mode to clear its contents
    std::ofstream outFile(PATH + CARPOOL, std::ios::trunc);
    if (!outFile)
    {
        std::cerr << "Failed to open the file for saving users.\n";
        return;
    }

    // Write each CarpoolListing to the file
    for (const auto &listing : carpoolList)
    {
        saveCarpoolListing(listing);
    }
    outFile.close(); // Close the file after clearing
}

void FileManager::pullRequestCarpool(CarpoolListing carpool, User user){
    std::ofstream request_file;
    std::string file_path = getFilePath(REQUEST);
    request_file.open(file_path, std::ios::out | std::ios::app);
    if (!request_file.is_open())
    {
        std::cerr << "File not found!";
    }

    int a = -1;
    request_file << carpool.getID() << ","
                 << carpool.getIDowner() << ","
                 << user.getUID() << ","
                 << a << std::endl;
    request_file.close();
}

void FileManager::saveRequest(const Booking& request) {
    std::ofstream outFile;
    std::string file_path = getFilePath(REQUEST);
    outFile.open(file_path, std::ios::out | std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    // Write the Booking object to the file
    outFile << request.getCPID() << ','
            << request.getOwnerID() << ','
            << request.getPassengerID() << ','
            << request.getStatusInfo();
            // Add other attributes here

    // Close the file
    outFile.close();

    // Optional: Notify that the request was saved successfully
    //std::cout << "Request saved successfully.\n";
}
void FileManager::saveAllRequest(vector<Booking> &requestList){
      std::ofstream outFile(PATH + REQUEST, std::ios::trunc);
    if (!outFile)
    {
        std::cerr << "Failed to open the file for saving users.\n";
        return;
    }
    outFile.close(); // Close the file after clearing

    // Write each CarpoolListing to the file
    for (const auto &request : requestList)
    {
        saveRequest(request);
    }
}
std::vector<Booking> FileManager::loadRequest() {
    std::ifstream request_file;
    std::string file_path = getFilePath(REQUEST);
    request_file.open(file_path, std::ios::in);

    if (!request_file.is_open()) {
        std::cerr << "File not found: " << file_path << '\n';
        return {}; // Return an empty vector if the file couldn't be opened
    }

    std::vector<Booking> loadRequest;
    std::string cpid, ownerid, uid;
    int stat;

    // Read data line by line
    while (getline(request_file, cpid, ',') &&
           getline(request_file, ownerid, ',') &&
           getline(request_file, uid, ',') &&
           (request_file >> stat)) {
        
        // Ignore the rest of the line after reading stat
        // request_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Create a Booking object and add it to the vector
        Booking request(cpid, ownerid, uid, stat);
        loadRequest.push_back(request);
    }

    request_file.close();
    return loadRequest;
}

std::vector<RatingSystem> FileManager::loadRating() {
    std::ifstream rating_file;
    std::vector<RatingSystem> loadRating;

    std::string file_path = getFilePath(RATING); // Ensure this path is correct
    rating_file.open(file_path, std::ios::in);   // Open for reading

    if (!rating_file.is_open()) {
        std::cerr << "File not found\n";
        return loadRating; // Return an empty vector
    }

    std::string uid, comment;
    double score;

    // Read the file line by line
    while (getline(rating_file, uid, ',') && 
           rating_file >> score &&
           rating_file.ignore(1, ',') &&  // Skip the comma after the score
           getline(rating_file, comment)) 
    {
        // Create a RatingSystem object with the read data and add it to the vector
        RatingSystem rating(uid, score, comment);
        loadRating.push_back(rating);
    }

    rating_file.close();
    return loadRating; // Return the populated vector
}

void FileManager::saveRating(RatingSystem& rating) {
    std::ofstream rating_file;
    std::string file_path = getFilePath(RATING);

    // Open the file in append mode
    rating_file.open(file_path, std::ios::out | std::ios::app);
    if (!rating_file.is_open()) {
        std::cerr << "File not found\n";
        return;
    }

    // Write user ID, score, and comments to the file using getter methods
    rating_file << rating.getUserID() << "," 
                << rating.getScore() << "," 
                << rating.getComments() << "\n";

    rating_file.close();
}


User FileManager::loadSingleUser(const std::string idVal)
{
    std::ifstream user_file;
    std::string file_path = getFilePath(USER); // Ensure this path is correct
    user_file.open(file_path, std::ios::in);   // Open for reading

    if (!user_file.is_open())
    {
        std::cerr << "File not found\n";
        return User(); // Return an empty or default User object
    }

    std::string id, username, password, fullname, phone_number, email, IDtype, IDnum;
    int creditpoint;

    while (getline(user_file, id, ',') &&
           getline(user_file, username, ',') &&
           getline(user_file, password, ',') &&
           getline(user_file, fullname, ',') &&
           getline(user_file, phone_number, ',') &&
           getline(user_file, email, ',') &&
           getline(user_file, IDtype, ',') &&
           getline(user_file, IDnum, ',') &&
           (user_file >> creditpoint))
    {

        user_file.ignore(1, ','); // Skip the comma after the integer

        // Check if the credentials match
        if (id == idVal)
        {
            user_file.close();
            return User(id, username, password, fullname, phone_number, email, IDtype, IDnum, creditpoint);
        }
    }

    // If no matching user was found
    user_file.close();
    return User(); // Return an empty or default User object
}


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

// CarpoolListing loadSingleCarpool(string CarpoolID)
// {

// }
