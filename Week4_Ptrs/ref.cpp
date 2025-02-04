//
// Created by darth on 2/3/2025.
//
#include <iostream>

int main()
{
    // Modifying references
    {
        int temp = 5;
        int& ref = temp;
        std::cout << &temp << "\n" << &ref << std::endl;

        int temp2 = 100;
        ref = temp2;
    }
    std::cout << std::endl;

    // looping with auto, also demonstrating references
    {
        int arr_size = 5;
        int arr[arr_size] {1, 2, 3, 4, 5};

        // modify each reference
        for (auto& el: arr) {  // Try removing the ampersand to see what happens
            el += 10;
            std::cout << el << std::endl;
        }

        std::cout << "\n";
        for (auto el: arr) {
            std::cout << el << std::endl;
        }
    }
}