#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//initialize priors assumimg vehicle at landmark +/- 1.0 meters position stdev
std::vector<float> initialize_priors(int map_size, std::vector<float> landmark_positions,
                                     float control_stdev);

int main() {

    //set standard deviation of position:
    float control_stdev = 1.0f;


    //set map horizon distance in meters 
    int map_size = 25;

    //initialize landmarks
    std::vector<float> landmark_positions {5, 10, 20};

    // initialize priors
    std::vector<float> priors = initialize_priors(map_size, landmark_positions,
                                                  control_stdev);
    
    //print values to stdout 
    for (unsigned int p = 0; p < priors.size(); p++) {
        std::cout << priors[p] << endl;
    }
        
    return 0;

};

//TODO: Complete the initialize_priors function
std::vector<float> initialize_priors(int map_size, std::vector<float> landmark_positions,
                                     float control_stdev) {

    //initialize priors assumimg vehicle at landmark +/- 1.0 meters position stdev
    std::vector<float> priors(map_size);
    
    // loop through positions and stdev values
    for (int i=0; i < landmark_positions.size(); ++i) {
        priors[landmark_positions[i]] += 1 / (landmark_positions.size()*(2*control_stdev + 1));
        for (int j=1; j <= control_stdev; ++j) {
            priors[landmark_positions[i] + j] += 1 / (landmark_positions.size()*(2*control_stdev + 1));
            priors[landmark_positions[i] - j] += 1 / (landmark_positions.size()*(2*control_stdev + 1));
        }
    }
    
    return priors;
}
