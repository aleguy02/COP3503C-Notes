#include <iostream>

struct Grades {
    int* grades;
    int capacity;
    int curr_size;  // Without current size, we won't know how many elements are in our dynamic array

    Grades()
    {
        capacity = 5;
        curr_size = 0;
        grades = new int[capacity];
    }

    // Try commenting one out and leaving the other, then seeing the output
    /* Good Copy Constructor
     * This copy constructor creates a "deep copy" of the 'grades' from the object it is copying
     */
    Grades(const Grades& other)
    {
        this->capacity = other.capacity;
        this->curr_size = other.curr_size;
        this->grades = new int[this->capacity];

        // Make a deep copy of grades
        for (int i = 0; i < curr_size; i++) {
            this->grades[i] = other.grades[i];
            std::cout << grades[i] << std::endl;
        }
    }

    /* Bad Copy Constructor
     * This copy constructor creates a "shallow copy" of the 'grades' from the object it is copying
     */
    // Grades(const Grades& other)
    // {
    //     this->capacity = other.capacity;
    //     this->curr_size = other.curr_size;
    //     this->grades = other.grades;  // This is bad!
    // }


    Grades& operator=(const Grades& other)
    {
        /* Handle self-assignment
         * Remember, 'this' is  a pointer, in other words 'this' is a variable holding a hex memory address.
         * We want to see if 'this' and 'other' exist at the same memory address and avoid unnecessary operations.
         *
         * So, lets use the & symbol to get the memory address of 'other' and compare it to 'this'.
         */
        if (this == &other) {
            return *this;
        }
        // Free the memory of grades so you have a clean slate
        delete[] this->grades;

        this->capacity = other.capacity;
        this->curr_size = other.curr_size;
        this->grades = new int[this->capacity];

        // Make a deep copy of grades
        for (int i = 0; i < curr_size; i++) {
            this->grades[i] = other.grades[i];
        }

        return *this;
    }
    ~Grades()
    {
        delete[] grades;
    }

    void push(int grade)
    {
        grades[curr_size] = grade;
        curr_size++;
    }

    int pop()
    {
        int temp = grades[curr_size -1];
        grades[curr_size - 1] = 0;
        curr_size--;

        return temp;
    }

    void display()
    {
        std::cout << "{\n";
        for (int i = 0; i < curr_size; i++) {
            std::cout << "  " << grades[i] << ": " << &grades[i] << "," << std::endl;
        }
        std::cout << "}\n";
    }
};

int main()
{
    Grades joe;
    joe.push(1);
    joe.push(2);
    joe.push(3);
    joe.push(4);
    joe.push(5);
    // joe.display();

    Grades ben = joe;
    // ben.display();

    // Now let's modify joe.grades and see what happens to ben.grades
    std::cout << "\n\n";
    joe.pop();
    joe.pop();
    // joe.display();
    // ben.display();

    return 0;
}