#include <iostream>
#include <cctype>
#include <regex>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
class inputValidator {
public:
    void validateUsername(std::string& usernameVal);
    void validatePassword(std::string& passwordVal);
    void validatePhoneNumber(std::string& PhoneNumberVal);
    void validateDate(std::string& DateVal);
    void validateTime(std::string& TimeVal);
};

bool find(const std::string& usernameVal, const std::string& filePath);