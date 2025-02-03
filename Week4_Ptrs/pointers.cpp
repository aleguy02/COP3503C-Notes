#include <iostream>
#include <string>


int main()
{
    std::string temp = "Hello World";
    std::string* ptr = &temp;
    std::string** ptr_to_ptr = &ptr;

    // print pointer value
    {
        std::cout << *ptr << std::endl;
    }

    // print double pointer value
    {
        std::cout << *ptr_to_ptr << std::endl;
        std::cout << **ptr_to_ptr << std::endl;
    }
}