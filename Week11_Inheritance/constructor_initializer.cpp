#include <iostream>
#include <string>

// topic: inheritance, constructor-initializer-list, constness

class Vehicle {
    public:
    const std::string brand;
    const int speed;

    /* Constructor Initializer List
     * the variables `brand` and `speed` are initialized before the constructor body is executed. Optimizes performance
     * and is more readable (in my opinion). **Also**, `const` class variables can only be initialized using a CIL
     */
    Vehicle(std::string _brand, int _speed) : brand(_brand), speed(_speed)
    {
        std::cout << "Vehicle constructor called" << std::endl;
    }
};

// This is a derived class
class Car : public Vehicle {
    public:
    const int num_doors;

    /* Constructor initializer list WITHOUT base class constructor
     * This is bad. Here, we fail to initialize the variables that were defined in the `Vehicle` parent class.
     * Uncomment this constructor and note the warning
     */
    // Car(int _num_doors) : num_doors(_num_doors) {}

    /* Constructor initializer list WITH base class constructor
     * Parameterized constructors of a base class can ONLY be called in a CIL
     */
    Car (std::string _brand, int _speed, int _num_doors) : Vehicle(_brand, _speed), num_doors(_num_doors)
    {
        std::cout << "Car constructor called" << std::endl;
    }
};

int main()
{
    Vehicle vehicle("Yamaha", 100);
    Car car("Toyota", 150, 4);

    return 0;
}