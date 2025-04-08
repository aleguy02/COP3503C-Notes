#include <iostream>
#include <string>
using namespace std;

// refer to YouTube video for explanation

class Base {
    public:
    string name;
    int number;

    Base(string _name, int _number) : name(_name), number(_number) {}
};

class Derived : public Base {
    public:
    int another_number;

    Derived(string _name, int _number, int _another_number) : Base(_name, _number), another_number(_another_number) {}
};

int main()
{
    Derived derived("hello world", 5, 17);
    cout << derived.name << ", " << derived.number << ", " << derived.another_number << endl;
}