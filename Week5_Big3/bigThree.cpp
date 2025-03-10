// This demo DOES NOT use dynamic memory. For an example with dynamic memory, look at bigThree_dynamicMem.cpp

#include <string>
#include <vector>
#include <iostream>

class ToDo {
    public:
    std::string dayOfWeek;
    std::vector<std::string> items;

    // all the 'const' keyword is doing here is ensuring we can't modify arguments, technically optional
    ToDo(const std::string day, const std::vector<std::string> items) : dayOfWeek(day), items(items) {}

    /* Copy Constructor
     * Use the 'const' keyword so you can ensure that you don't accidentally modify the 'other' object. It's just
     * a safety precaution. Also, pass by reference so you don't make an unnecessary copy of 'other'
     *
     * Copy constructors are most useful when you are working with dynamically allocated memory and "deep copying"
     */
    ToDo(const ToDo& other)
    {
        this->dayOfWeek = other.dayOfWeek;
        this->items = other.items;
    }

    /* Copy Assignment Operator
     * IMPORTANT: You only need this when working with dynamic memory. I included it here so you could see a simpler
     * version NOT using dynamic memory, but it's technically not necessary
     *
     * Use the 'const' keyword so you can ensure that you don't accidentally modify the 'other' object. It's just
     * a safety precaution. Also, pass by reference so you don't make an unnecessary copy of 'other'
     */
    ToDo& operator=(const ToDo& other)
    {
        this->dayOfWeek = other.dayOfWeek;
        this->items = other.items;

        return *this;
    }

    /* Destructor
     * This the easiest one. All you have to do here is free the memory you allocated for this object.
     * In other words, for every 'new' keyword you use in the constructor, you need to have a 'delete' keyword in
     * the destructor
     */
    ~ToDo()
    {
        std::cout << "bye bye" << std::endl;
    }
};

int main()
{
    // create vector to be used in examples
    std::vector<std::string> items {
        "water plant",
        "finish homework",
        "walk dog",
    };

    // Copy constructor operator
    {
        ToDo mon("Monday", items);
        ToDo mon2(mon);

        // Uncomment these lines to see the memory addresses of mon.items and mon2.items
        // std::cout << &mon.items << std::endl;
        // std::cout << &mon2.items << std::endl;
    }

    // Copy assignment operator
    {
        ToDo tue("Tuesday", items);
        ToDo tue_copy("temp", std::vector<std::string> {"item 1", "item 2"});
        // ^^^ Initialize values to temp values so you can see the changes after using the copy assignment operator

        tue_copy = tue;

        int temp = 5;
    }


    return 0;
};