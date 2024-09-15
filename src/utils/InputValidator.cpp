#include <iostream>
#include <cctype>
#include <regex>
#include <sstream>
#include <fstream>
#include <string>
#include "..\lib\InputValidator.h"


// Console text formatting
#define BOLD "\033[1m"
#define RESET "\033[0m"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"

using namespace std;

bool find(const std::string& usernameVal, const std::string& filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "File not found 1234\n";
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string id, username;
        int creditpoint;
        float rating_score;

        getline(ss, id, ',');
        getline(ss, username, ',');  // Extract the username

        if (usernameVal == username) {
            return true;
        }
    }

    return false;
}

void inputValidator::validateUsername(std::string& usernameVal) {
    while (find(usernameVal, "./data/user.dat")) {
        std::cout << RED << "Username already taken, please try again\n" << RESET;
        std::cout << "Enter a username: ";
        std::getline(cin, usernameVal);
    }
    while (usernameVal.find(' ') != std::string::npos) {
        std::cout << "Do not include spaces in the username! Please try again: ";
        std::getline(cin, usernameVal);
    }
}

void inputValidator::validatePassword(std::string& passwordVal) {
    while (passwordVal.size() < 8) {
        std::cout << RED << "Please input at least 8 characters: " << RESET;
        std::getline(cin, passwordVal);
    }

    std::regex regx("[@_!#$%^&*()<>?/|}{~:]");
    while (!std::regex_search(passwordVal, regx)) {
        std::cout << RED << "Please add a special character: " << RESET;
        std::getline(cin, passwordVal);
    }

    while (!isupper(passwordVal[0])) {
        std::cout << RED << "Please capitalize the first character: " << RESET;
        std::getline(cin, passwordVal);
    }

    while (passwordVal.find(' ') != std::string::npos) {
        std::cout << RED << "Do not include spaces in the password! Please try again: " << RESET;
        std::getline(cin, passwordVal);
    }
}

void inputValidator::validateFullName(std::string& fullnameVal) {
    std::regex regx("\\d");
    while (std::regex_search(fullnameVal, regx)) {
        std::cout << RED <<"No digit in the full name, please try again: " << RESET;
        std::getline(cin, fullnameVal);
    }
}

void inputValidator::validateEmail(std::string& emailVal) {
    std::regex emailPattern(R"((\w+)(\.?)(\w*)@(\w+)(\.(\w+))+)");
    while (!std::regex_match(emailVal, emailPattern)) {
        std::cout << RED << "Invalid email, please try again: " << RESET;
        std::getline(cin, emailVal);
    }
}

void inputValidator::validatePhoneNumber(std::string& phoneNumberVal) {
    std::regex regx("^[0-9]+$");
    while (!std::regex_match(phoneNumberVal, regx)) {
        std::cout << RED <<"Enter a valid phone number: " << RESET;
        std::getline(cin, phoneNumberVal);
        if (std::regex_match(phoneNumberVal, regx)){
            break;
        }
    }
}
void inputValidator::validatePassportNumber(std::string& passportNumber){
    while (passportNumber.find(' ') != std::string::npos) {
        std::cout << RED << "Do not include spaces, please try again: " << RESET;
        std::getline(cin, passportNumber);
    }
    
}
void inputValidator::validateIDType(std::string& IDType) {
    while (IDType != "Passport" && IDType != "National ID") {
        std::cout << RED <<"Enter a valid IDType, must be 'Passport' or 'National ID' only: " << RESET;
        std::getline(cin, IDType);
    }
}


void inputValidator::validateDate(std::string& dateVal) {
    while (true) {
        if (dateVal.size() != 10 || dateVal[2] != '/' || dateVal[5] != '/') {
            std::cout << RED << "Invalid date format. Please use dd/mm/yyyy: " << RESET;
            std::getline(cin, dateVal);
            continue;
        }

        bool valid = true;
        for (char i : dateVal) {
            if (!std::isdigit(i) && i != '/') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            std::cout << RED << "Invalid date value. Please enter numeric values for day, month, and year: " << RESET;
            std::getline(cin, dateVal);
            continue;
        }

        stringstream ss(dateVal);
        int day, month, year;
        char slash;
        ss >> day >> slash >> month >> slash >> year;

        if (day < 1 || day > 31) {
            std::cout << RED <<"Invalid day value. Please enter a day from 1 to 31: " << RESET;
            std::getline(cin, dateVal);
            continue;
        }

        if (month < 1 || month > 12) {
            std::cout << RED << "Invalid month value. Please enter a month from 1 to 12: " << RESET;
            std::getline(cin, dateVal);
            continue;
        }

        break;
    }
}
void inputValidator::validateVehicleColor(std::string& vehicleColor){
    std::regex regx("\\d");
    while (std::regex_search(vehicleColor, regx)) {
        std::cout << RED <<"No digit in the color, please try again: " << RESET;
        std::getline(cin, vehicleColor);
    }
}
void inputValidator::validatePlateNumber(std::string& plateNumber){
    while (plateNumber.find(' ') != std::string::npos) {
        std::cout << RED << "Do not include spaces, please try again: " << RESET;
        std::getline(cin, plateNumber);
    }
}

void inputValidator::validateTime(std::string& timeVal) {
    while (true) {
        if (timeVal.size() != 5 || timeVal[2] != ':') {
            std::cout << RED << "Invalid time format. Please use hh:mm: " << RESET;
            std::getline(cin, timeVal);
            continue;
        }

        if (!std::isdigit(timeVal[0]) || !std::isdigit(timeVal[1]) ||
            !std::isdigit(timeVal[3]) || !std::isdigit(timeVal[4])) {
            std::cout << RED << "Invalid time value. Please enter numeric values for hours and minutes: " << RESET;
            std::getline(cin, timeVal);
            continue;
        }

        stringstream ss(timeVal);
        int hour_val, minutes_val;
        char colon;
        ss >> hour_val >> colon >> minutes_val;

        if (hour_val < 0 || hour_val > 23) {
            std::cout << RED <<"Invalid hour value. Please enter an hour from 00 to 23: " << RESET;
            std::getline(cin, timeVal);
            continue;
        }

        if (minutes_val < 0 || minutes_val > 59) {
            std::cout << RED << "Invalid minutes value. Please enter minutes from 00 to 59: " << RESET;
            std::getline(cin, timeVal);
            continue;
        }

        break;
    }
}
void inputValidator::validateLocation(std::string& location) {
    while (location != "Saigon" && location != "Hanoi") {
        std::cout << "\033[31mError: Location must be 'Saigon' or 'Hanoi'.\n\033[0m";  // Red color for error
        std::cout << "\033[33mEnter location again: \033[0m";  // Yellow color for prompt
        std::getline(std::cin, location);
    }
}

void inputValidator::validateCredit(std::string& amountCredit) {
    std::regex regx("^[0-9]+$");

    while (true) {
        std::cout << RED << "Enter a valid amount (at least 10): " << RESET;
        std::getline(std::cin, amountCredit);

        // Validate if the input matches the regex
        if (std::regex_match(amountCredit, regx)) {
            int creditAmount = std::stoi(amountCredit);
            if (creditAmount >= 10) {
                break; // Valid amount, exit loop
            }
        }

        // Prompt again if validation fails
        std::cout << RED << "Invalid amount. Please enter a number greater than or equal to 10." << RESET << std::endl;
    }
}