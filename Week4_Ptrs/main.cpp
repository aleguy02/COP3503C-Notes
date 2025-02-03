#include <iostream>
#include <vector>



// class that has a vector of two coordinates
class Coordinate {
    private:
        std::vector<int> coords;

    public:
        Coordinate(int x, int y) : coords{x, y} {};

        // prints coordinates formatted as {x, y}
        void print() const
        {
            std::cout << "{" << coords.at(0) << ", " << coords.at(1) << "}" << std::endl;
        };


        // Creates new object
        Coordinate operator+(const Coordinate& other)  // const here just means this function won't modify the argument
        {
            // We create a local object
            Coordinate res(0, 0);
            res.coords[0] = this->coords[0] + other.coords[0];
            res.coords[1] = this->coords[1] + other.coords[1];

            // and return it by value (make a copy)
            return res; // return by value
        };

        // Modifies this object and returns a reference
        Coordinate& operator+=(const Coordinate& other)
        {
            // this->coords[0] = this->coords[0] + other.coords[0];
            // this->coords[1] = this->coords[1] + other.coords[1];

            coords[0] = coords[0] + other.coords[0];
            coords[1] = coords[1] + other.coords[1];

            std::cout << this << std::endl;
            // Return a derefenced pointer to this (in other words return the invoking object)
            return *this;
        }
};

int main()
{
    // Initialize 2 'Coordinate' objects
    Coordinate UF(1, 1), FSU(2,2);
    UF.print();
    FSU.print();


    // Overloading + operator
    std::cout << "Overloading + operator:" << std::endl;
    {
        Coordinate sum = UF + FSU;  // UF is the 'invoking' object, FSU is the 'other' object
        sum.print();
    }


    // Overloading += operator
    std::cout << "Overloading += operator:" << std::endl;
    {
        UF += FSU;
        UF.print();
        std::cout << &UF << std::endl;
    }

}