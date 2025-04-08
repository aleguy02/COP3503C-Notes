#include <iostream>
#include <vector>
using namespace std;

// refer to YouTube video for explanation

class Base {
    public:
    virtual ~Base() = default;  // this is equivalent to `virtual ~Base() {};`
    virtual void print()
    {
        cout << "print() from Base" << endl;
    }
};

class Derived : public Base {
    public:
    void print() override
    {
        cout << "print() from Derived" << endl;
    }
};

int main()
{
    {
        Derived derived;
        Base* ptr = &derived;
        ptr->print();

        Base base;
        ptr = &base;
        ptr->print();
    }

    {
        vector<Base*> vec;
        Derived derived;
        Base base;

        Base* derived_ptr = &derived;
        Base* base_ptr = &base;

        vec.push_back(derived_ptr);
        vec.push_back(base_ptr);

        vec[0]->print();
        vec[1]->print();
    }
}