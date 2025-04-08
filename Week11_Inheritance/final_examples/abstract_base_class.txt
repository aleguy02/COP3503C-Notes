#include <iostream>
using namespace std;

// refer to YouTube video for explanation

class Animal {
    public:
    virtual void Feed() = 0;  // this is known as a "pure virtual function". It tells the compiler that this is an ABC
    virtual ~Animal() {};
};

class Llama : public Animal {
    public:
    void Feed() override
    {
        cout << "mm delicious grass" << endl;
    }
};

class Frog: public Animal {
    public:
    void Feed() override
    {
        cout << "yummy bugs mm" << endl;
    }
};

int main()
{
    // Animal animal;

    Llama llama;
}