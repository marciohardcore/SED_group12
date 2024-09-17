#include "..\lib\IdentityVerifier.h"

bool IdentityVerifier::verifyCaptCha(){
    IDgenerator captcha;
    std::string input;
    std::string combination = captcha.generate_captcha();
    std::cout << GREEN << "This is your captcha: "<< combination <<"\n" << RESET;
    std::cout << GREEN << "Re-enter captcha for identity verifying: "<< RESET;
    std::getline(std::cin, input);

    if (input == combination){
        return true;
    }
    else{
        return false;
    }
}
