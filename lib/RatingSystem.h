#pragma once

#ifndef RATING_H
#define RATING_H

// content of the header file


#include <iostream>
#include <vector>
#include "..\lib\FileManager.h"

class RatingSystem {
private:
    std::string userID;
    std::vector <std::string> comments;
    double score;
    int size;
    double value;
public:
    RatingSystem(std::string userIDVal);
    RatingSystem(std::string userIDVal, float scoreVal, double valueVal);

    void addRating(double rate, std::string comment);
};


#endif
