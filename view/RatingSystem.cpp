#include <iostream>
#include <vector>
#include "..\lib\RatingSystem.h"


RatingSystem::RatingSystem(std::string userIDVal, double scoreVal, std::string commentsVal) 
    : userID(userIDVal), score(scoreVal), comments(commentsVal) {
}
RatingSystem::RatingSystem(std::string userIDVal):userID(userIDVal){}

std::string RatingSystem::getUserID() const {return userID;}
std::string RatingSystem::getComments() const { return comments;}
double RatingSystem::getScore() const {return score;}
