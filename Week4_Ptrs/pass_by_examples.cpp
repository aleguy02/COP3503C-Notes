#include <iostream>


void passByVal(int num)  // has no & symbol
{
    num += 10;
}

void passByRef(int& num)  // has & symbol
{
    num += 10;
}

int main()
{
    // Pass by value
    {
        int temp = 5;
        passByVal(temp);
        std::cout << temp << std::endl;
    }

    // Pass by reference
    {
        int temp = 5;
        passByRef(temp);
        std::cout << temp << std::endl;
    }

}