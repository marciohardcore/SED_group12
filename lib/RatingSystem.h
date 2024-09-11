#pragma once

#ifndef RATING_H
#define RATING_H

#include <string>

class RatingSystem {
private:
    std::string userID;    // The ID of the user being rated
    std::string comments;  // Comments associated with the rating
    double score;          // The score of the rating (e.g., 1-5 scale)

public:
    // Constructors
    RatingSystem(std::string userIDVal); // Constructor for userID only
    RatingSystem(std::string userIDVal, double scoreVal, std::string commentsVal); // Full constructor

    // Getters
    std::string getUserID() const;    // Getter for userID
    std::string getComments() const;  // Getter for comments
    double getScore() const;          // Getter for score
};

#endif
