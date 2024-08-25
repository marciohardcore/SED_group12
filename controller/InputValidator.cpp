#include <iostream>
#include <ctype.h>
#include <regex>
#include <sstream>

using std::stringstream;

// using namespace std;
class inputValidator{
public:
    bool validateUsername(std::string usernameVal);
    bool validatePassword(std::string passwordVal);
    bool validatePhoneNumber(std::string PhoneNumberVal);
    bool validateDate(std::string DateVal);
    bool validateTime(std::string TimeVal);
};
bool validateUsername(std::string usernameVal){
    //check to database, if trung` thi khong duoc
    do{
        std::cout << "Username already taken, please try again\n";
        std::cin >> usernameVal;

    }
    while (find(usernameVal, username.dat) == true);
}
bool validatePassword(std::string passwordVal){
    //length < 8
    do{
        std::cout << "Please input at least 8 character\n";
        std::cin >> passwordVal;
    }
    while (passwordVal.size() < 8);

    //special character
    std::regex regx("[@_!#$%^&*()<>?/|}{~:]");
    do{
        std::cout << "Please add special character\n";
        std::cin >> passwordVal;
    }
    while(regex_search(passwordVal, regx) == 0);

    //capital character
    do{
        std::cout << "Please capitalize the first character\n";
        std::cin >> passwordVal;
    }
    while (!isupper(passwordVal[0]));

    //space
    do{
        std::cout << "Do not include space in the password!\n Please try again.\n";
        std::cin >> passwordVal;        
    }
    while (passwordVal.find(' ') != std::string::npos);

}
bool validatePhoneNumber(std::string PhoneNumberVal){
    std::regex regx("0123456789");
    do{
        std::cout << "\n";
        std::cin >> PhoneNumberVal;
    }
    while(regex_search(PhoneNumberVal, regx) == 0);

}
bool validateDate(std::string DateVal){
    //invalid format of dd/mm/yyyy
    if (DateVal.size() != 10 && DateVal[2] != '/' && DateVal[5] != '/'){
        return false;
    }

    for (char i:DateVal){
        if (!std::isdigit(i) && i != '/'){
            std::cout << "Invalid time value. Please enter numeric values for hours and minutes.\n";
            return false;
        }
    }

    stringstream ss;
    ss << DateVal;
    int day, month, year;
    char slash;
    ss >> day >> slash >> month >> slash >> year;
    //if minute > 60 -> error
    //hh:mm only

    do{
        std::cout << "Invalid day value\n Please enter time from 1 to 31.\n";
    }
    while(day > 31 ||  day < 1);
    
    do{
        std::cout << "Invalid month value\n Please enter time from 1 to 12.\n";
    }
    while(month > 12 || month < 1);
}
bool validateTime(std::string TimeVal){
    
    //invalid format of hh::mm
    if (TimeVal.size() != 5 && TimeVal[2] != ':'){
        return false;
    }

    if (!std::isdigit(TimeVal[0]) || !std::isdigit(TimeVal[1]) || 
        !std::isdigit(TimeVal[3]) || !std::isdigit(TimeVal[4])) {
        std::cout << "Invalid time value. Please enter numeric values for hours and minutes.\n";
        return false;
    }

    stringstream ss;
    ss << TimeVal;
    int hour_val, minutes_val;
    char colon;
    ss >> hour_val >> colon >> minutes_val;
    //if minute > 60 -> error
    //hh:mm only

    do{
        std::cout << "Invalid hour value\n Please enter time from 00:00 to 23:59.\n";
    }
    while(hour_val > 24 ||  hour_val < 0);
    
    do{
        std::cout << "Invalid minutes value\n Please enter time from 00:00 to 23:59.\n";
    }
    while(minutes_val > 60 || minutes_val < 0);
}
