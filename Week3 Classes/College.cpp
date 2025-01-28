//
// Created by darth on 1/25/2025.
//
#include "College.h"
#include <iostream>

College::College()
{
    this->name = "Monsters University";
    this->ranking = 1;
}

College::College(std::string name, int ranking)
{
    this->name = name;
    this->ranking = ranking;
}


void College::showRanking()
{
    // "Name's ranking is ranking"
    std::cout << name << "'s ranking is #" << ranking << std::endl;
}
