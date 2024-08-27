#include <iostream>
#include <vector>

class RatingSystem {
public:
    float calculateRating(std::vector<float> ratings) {
        float sum = 0.0f;
        for (float rating : ratings) {
            sum += rating;
        }
        return ratings.empty() ? 0.0f : sum / ratings.size();
    }

    void updateRating(Member* member, float newRating) {
        // Update the member's ratingScore based on newRating
        member->setRatingScore(calculateRating({member->getRatingScore(), newRating}));
    }
};