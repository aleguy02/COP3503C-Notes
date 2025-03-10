#include <vector>
#include <string>
#include <iostream>

class Superheros {
    public:
        std::vector<std::string> names;

        Superheros() {};
        Superheros(std::string name1, std::string name2)
        {
            this->names.push_back(name1);
            this->names.push_back(name2);
        };

        void print()
        {
            for (int i = 0; i < this->names.size(); i++) {
                std::cout << this->names[i] << std::endl;
            }
        }


        // Overloaded operators
        Superheros operator+(const Superheros& other)
        {
            // this->names.push_back(other.names[0]);
            // this->names.push_back(other.names[1]);
            Superheros res;
            // using a for loop
            for (int i = 0; i < this->names.size(); i++) {
                res.names.push_back(this->names[i]);
            }
            for (int i = 0; i < other.names.size(); i++) {
                res.names.push_back(other.names[i]);
            }

            res.print();
            return res;
        }
};

int main()
{
    Superheros DC("Batman", "Superman");
    Superheros Marvel("Spiderman", "Squirrel Girl");
    DC.print();
    Superheros res = DC + Marvel;
    res.print();
}