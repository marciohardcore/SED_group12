#include <iostream>
#include <vector>
#include "..\lib\RatingSystem.h"
// #include "..\lib\FileManager.h"

// RatingSystem::RatingSystem(std::string userIDVal, float scoreVal = 0.0, double valueVal = 0.0):
//             userID(userIDVal), score(scoreVal), value(valueVal){}
RatingSystem::RatingSystem(std::string userIDVal):userID(userIDVal){}

void RatingSystem::addRating(double rate, std::string comment){
    comments.push_back(comment);
    cout << "Current rate:" << rate << "\n";
    cout << "Current comment size:" << comments.size() << "\n";

    //score = (double)(comments.size() * score + value) / (comments.size() + 1);
    if (score == 0) {
        score = rate;
    }
    else{
        score = (rate + score)/2.0;
    }
    FileManager file;
    file.updateRating(userID, score, comments);
    //ownerID, userID, score, comment
}
