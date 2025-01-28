//
// Created by darth on 1/25/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class College {
    private:
        std::string name;
        int ranking;
    public:
        // Default constructor
        College();

        // Parameterized constructor
        College(std::string name, int ranking);

        // Function to print out college name and ranking
        void showRanking();
};

#endif //STUDENT_H
