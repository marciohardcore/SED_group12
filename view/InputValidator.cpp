#include <iostream>
#include <cctype>
#include <regex>
#include <sstream>
#include <fstream>
#include <string>
#include "..\lib\InputValidator.h"


using namespace std;

bool find(const std::string& usernameVal, const std::string& filePath) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "File not found\n";
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
    while (find(usernameVal, "../data/user.dat")) {
        std::cout << "Username already taken, please try again\n";
        std::cout << "Enter a username: ";
        std::getline(cin, usernameVal);
        //find.isspace()...
    }
    
}

void inputValidator::validatePassword(std::string& passwordVal) {
    // length < 8
    while (passwordVal.size() < 8) {
        std::cout << "Please input at least 8 characters: ";
        std::cin >> passwordVal;
    }

    // special character
    std::regex regx("[@_!#$%^&*()<>?/|}{~:]");
    while (!std::regex_search(passwordVal, regx)) {
        std::cout << "Please add a special character: ";
        std::cin >> passwordVal;
    }

    // capital character
    while (!isupper(passwordVal[0])) {
        std::cout << "Please capitalize the first character: ";
        std::cin >> passwordVal;
    }

    // space
    while (passwordVal.find(' ') != std::string::npos) {
        std::cout << "Do not include spaces in the password! Please try again: ";
        std::cin >> passwordVal;
    }
}

void inputValidator::validatePhoneNumber(std::string& PhoneNumberVal) {
    std::regex regx("^[0-9]+$");
    while (!std::regex_match(PhoneNumberVal, regx)) {
        std::cout << "Enter a valid phone number: ";
        std::cin >> PhoneNumberVal;
    }
}

void inputValidator::validateDate(std::string& DateVal) {
    while (true) {
        // invalid format of dd/mm/yyyy
        if (DateVal.size() != 10 || DateVal[2] != '/' || DateVal[5] != '/') {
            std::cout << "Invalid date format. Please use dd/mm/yyyy: ";
            std::cin >> DateVal;
            continue;
        }

        bool valid = true;
        for (char i : DateVal) {
            if (!std::isdigit(i) && i != '/') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            std::cout << "Invalid date value. Please enter numeric values for day, month, and year: ";
            std::cin >> DateVal;
            continue;
        }

        stringstream ss(DateVal);
        int day, month, year;
        char slash;
        ss >> day >> slash >> month >> slash >> year;

        if (day < 1 || day > 31) {
            std::cout << "Invalid day value. Please enter a day from 1 to 31: ";
            std::cin >> DateVal;
            continue;
        }

        if (month < 1 || month > 12) {
            std::cout << "Invalid month value. Please enter a month from 1 to 12: ";
            std::cin >> DateVal;
            continue;
        }

        break;
    }
}

void inputValidator::validateTime(std::string& TimeVal) {
    while (true) {
        // invalid format of hh:mm
        if (TimeVal.size() != 5 || TimeVal[2] != ':') {
            std::cout << "Invalid time format. Please use hh:mm: ";
            std::cin >> TimeVal;
            continue;
        }

        if (!std::isdigit(TimeVal[0]) || !std::isdigit(TimeVal[1]) || 
            !std::isdigit(TimeVal[3]) || !std::isdigit(TimeVal[4])) {
            std::cout << "Invalid time value. Please enter numeric values for hours and minutes: ";
            std::cin >> TimeVal;
            continue;
        }

        stringstream ss(TimeVal);
        int hour_val, minutes_val;
        char colon;
        ss >> hour_val >> colon >> minutes_val;

        if (hour_val < 0 || hour_val > 23) {
            std::cout << "Invalid hour value. Please enter an hour from 00 to 23: ";
            std::cin >> TimeVal;
            continue;
        }

        if (minutes_val < 0 || minutes_val > 59) {
            std::cout << "Invalid minutes value. Please enter minutes from 00 to 59: ";
            std::cin >> TimeVal;
            continue;
        }

        break;
    }
}

