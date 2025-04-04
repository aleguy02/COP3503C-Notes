#include <iostream>

// topic: virtual-function, pure-virtual-function, abstract-base-class, polymorphism

class Animal {
    public:
    // Intentionally not virtual:
    void Move() {
        std::cout << "This animal moves in some way" << std::endl;
    }
    virtual void Feed() = 0;
};

class Llama : public Animal {
    public:
    // The non-virtual function Move is inherited but not overridden.
    void Feed() override {
        std::cout << "mmm grass is so yummy!" << std::endl;
    }
};

class Frog : public Animal {
    public:
    // The non-virtual function Move is inherited but not overridden.
    void Feed() override {
        std::cout << "wow bugs are so good!" << std::endl;
    }
};

int main() {
  // Animal is an abstract base class. Abstract base classes are meant ONLY to be "starting points" for derived classes
  // By design, they can't be initialized. Uncomment the line below and observe the errors
  // Animal animal;

    Llama llama;
    // llama.Feed();

    /* Practical Application
     * You might be asking "why is this useful"?
     * Imagine you have a zoo and want to keep an array of all your animals. You want
     * to automate feeding them by looping through the array and calling each animal's `Feed` function.
     * If you're thinking "wait Ale, this isn't possible, you can't have an array containing different data types"
     * you're absolutely correct. You CANNOT have an array containing different data types.
     * You CAN, however, upcast `frog` and `llama` into type `Animal`, and store an array of Animal pointers
     */
    Frog frog;

    Animal* zoo_animals[2] = {&llama, &frog};
    int temp = 5;
    for (Animal* animal : zoo_animals) {
        animal->Feed();
    }

    // RABBIT HOLE ALERT: how does this work? https://en.wikipedia.org/wiki/Dynamic_dispatch
}