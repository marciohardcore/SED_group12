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
    }
    while (usernameVal.find(' ') != std::string::npos) {
        std::cout << "Do not include spaces in the username! Please try again: ";
        std::getline(cin, usernameVal);
    }
}

void inputValidator::validatePassword(std::string& passwordVal) {
    while (passwordVal.size() < 8) {
        std::cout << "Please input at least 8 characters: ";
        std::getline(cin, passwordVal);
    }

    std::regex regx("[@_!#$%^&*()<>?/|}{~:]");
    while (!std::regex_search(passwordVal, regx)) {
        std::cout << "Please add a special character: ";
        std::getline(cin, passwordVal);
    }

    while (!isupper(passwordVal[0])) {
        std::cout << "Please capitalize the first character: ";
        std::getline(cin, passwordVal);
    }

    while (passwordVal.find(' ') != std::string::npos) {
        std::cout << "Do not include spaces in the password! Please try again: ";
        std::getline(cin, passwordVal);
    }
}

void inputValidator::validateFullName(std::string& fullnameVal) {
    std::regex regx("\\d");
    while (std::regex_search(fullnameVal, regx)) {
        std::cout << "No digit in the full name, please try again: ";
        std::getline(cin, fullnameVal);
    }
}

void inputValidator::validateEmail(std::string& emailVal) {
    std::regex emailPattern(R"((\w+)(\.?)(\w*)@(\w+)(\.(\w+))+)");
    while (!std::regex_match(emailVal, emailPattern)) {
        std::cout << "Invalid email, please try again: ";
        std::getline(cin, emailVal);
    }
}

void inputValidator::validatePhoneNumber(std::string& phoneNumberVal) {
    std::regex regx("^[0-9]+$");
    while (!std::regex_match(phoneNumberVal, regx)) {
        std::cout << "Enter a valid phone number: ";
        std::getline(cin, phoneNumberVal);
        if (std::regex_match(phoneNumberVal, regx)){
            break;
        }
    }
}
void inputValidator::validatePassportNumber(std::string& passportNumber){
    while (passportNumber.find(' ') != std::string::npos) {
        std::cout << "Do not include spaces, please try again: ";
        std::getline(cin, passportNumber);
    }
    
}
void inputValidator::validateIDType(std::string& IDType) {
    while (IDType != "Passport" && IDType != "National ID") {
        std::cout << "Enter a valid IDType: ";
        std::getline(cin, IDType);
    }
}


void inputValidator::validateDate(std::string& dateVal) {
    while (true) {
        if (dateVal.size() != 10 || dateVal[2] != '/' || dateVal[5] != '/') {
            std::cout << "Invalid date format. Please use dd/mm/yyyy: ";
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
            std::cout << "Invalid date value. Please enter numeric values for day, month, and year: ";
            std::getline(cin, dateVal);
            continue;
        }

        stringstream ss(dateVal);
        int day, month, year;
        char slash;
        ss >> day >> slash >> month >> slash >> year;

        if (day < 1 || day > 31) {
            std::cout << "Invalid day value. Please enter a day from 1 to 31: ";
            std::getline(cin, dateVal);
            continue;
        }

        if (month < 1 || month > 12) {
            std::cout << "Invalid month value. Please enter a month from 1 to 12: ";
            std::getline(cin, dateVal);
            continue;
        }

        break;
    }
}

void inputValidator::validateTime(std::string& timeVal) {
    while (true) {
        if (timeVal.size() != 5 || timeVal[2] != ':') {
            std::cout << "Invalid time format. Please use hh:mm: ";
            std::getline(cin, timeVal);
            continue;
        }

        if (!std::isdigit(timeVal[0]) || !std::isdigit(timeVal[1]) ||
            !std::isdigit(timeVal[3]) || !std::isdigit(timeVal[4])) {
            std::cout << "Invalid time value. Please enter numeric values for hours and minutes: ";
            std::getline(cin, timeVal);
            continue;
        }

        stringstream ss(timeVal);
        int hour_val, minutes_val;
        char colon;
        ss >> hour_val >> colon >> minutes_val;

        if (hour_val < 0 || hour_val > 23) {
            std::cout << "Invalid hour value. Please enter an hour from 00 to 23: ";
            std::getline(cin, timeVal);
            continue;
        }

        if (minutes_val < 0 || minutes_val > 59) {
            std::cout << "Invalid minutes value. Please enter minutes from 00 to 59: ";
            std::getline(cin, timeVal);
            continue;
        }

        break;
    }
}
