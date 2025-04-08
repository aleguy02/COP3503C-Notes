#include <iostream>
using namespace std;

// refer to YouTube video for explanation

class Z {
    public:
    void print()
    {
        cout << "Printing to console" << endl;
    }
};

class A : virtual public Z {};

class B : virtual public Z {};

class C : public A, public B {};

int main()
{
    C c;
    c.print();
}