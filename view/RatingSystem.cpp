#include <iostream>
#include <vector>
#include "..\lib\RatingSystem.h"


RatingSystem::RatingSystem(std::string userIDVal, double scoreVal, std::string commentsVal) 
    : userID(userIDVal), score(scoreVal), comments(commentsVal) {
}
RatingSystem::RatingSystem(std::string userIDVal):userID(userIDVal){}

// void RatingSystem::addRating(double rate, std::string comment){
//     // comments.push_back(comment);
//     // cout << "Current rate:" << rate << "\n";
//     // cout << "Current comment size:" << comments.size() << "\n";

//     //score = (double)(comments.size() * score + value) / (comments.size() + 1);
//     // if (score == 0) {
//     //     score = rate;
//     // }
//     // else{
//     //     score = (rate + score)/2.0;
//     // }
//     FileManager file;
//     file.updateRating(userID, rate, comment);
//     //ownerID, userID, score, comment
// }
std::string RatingSystem::getUserID() const {return userID;}
std::string RatingSystem::getComments() const { return comments;}
double RatingSystem::getScore() const {return score;}
// int RatingSystem::getSize() const {return size;}
// double RatingSystem::getValue() const {return value;}