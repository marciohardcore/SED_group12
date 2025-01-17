#include <iostream>
#include <cctype>
#include <regex>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

#ifndef HGUARD1
#define HGUARD1

class inputValidator {
public:
    void validateUsername(std::string& usernameVal);
    void validatePassword(std::string& passwordVal);
    void validateFullName(std::string& fullnameVal);
    void validatePhoneNumber(std::string& PhoneNumberVal);
    void validateDate(std::string& DateVal);
    void validateEmail(std::string& emailVal);
    void validateIDType(std::string& IDType);
    void validatePassportNumber(std::string& passportNumber);
    void validateTime(std::string& TimeVal);
    void validateVehicleColor(std::string& vehicleColor);
    void validatePlateNumber(std::string& plateNumber);
    void validateLocation(std::string& location);
    void validateCredit(std::string& amountCredit);

};

bool find(const std::string& usernameVal, const std::string& filePath);

#endif
