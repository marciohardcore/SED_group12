#include "..\lib\IdentityVerifier.h"

bool IdentityVerifier::verifyCapCha(){
    IDgenerator capcha;
    std::string input;
    std::string combination = capcha.generate_capcha();
    std::cout << GREEN << "This is your capcha: "<< combination <<"\n" << RESET;
    std::cout << GREEN << "Re-enter capcha for identity verifying: "<< RESET;
    std::getline(std::cin, input);

    if (input == combination){
        return true;
    }
    else{
        return false;
    }
}
