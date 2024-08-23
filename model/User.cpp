#include <iostream>

class User{
private:
    std::string userName;
    std::string password;
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string User_id;
    int creditPoint;
    float ratingScore;
public:
    //constructor
    User(){}
    //User():{}

    void viewProfile(){

    }
    
    void updateProfile(){

    }

    void rateUser(User *user, float score, std::string comment){

    }

    void addCreditPoints(){

    }

    //saveUser() (save to file)
    friend class UserController;
};