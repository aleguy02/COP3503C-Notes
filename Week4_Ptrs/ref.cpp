//
// Created by darth on 2/3/2025.
//
#include <iostream>

int main()
{
    int temp = 5;
    int& ref = temp;
    std::cout << &temp << "\n" << &ref << std::endl;

    int temp2 = 100;
    ref = temp2;
}