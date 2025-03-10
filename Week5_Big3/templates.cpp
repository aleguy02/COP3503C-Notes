#include <string>
#include <iostream>

/* Template Function
 * Template functions should be used for when you want to perform a function that is pretty similar across types
 * For example, addition. Addition is more or less the same for ints and floats, so a template function would be
 * the perfect solution.
 *
 * T is a placeholder for whatever type you pass into the function. So, when walking through the
 * code just imagine that you are working with an int or a double or whatever type you want.
 */
template<typename T>
void swap(T& a, T& b)  // pass by reference so our 'swap' is reflected in outer scope (main)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T return_max(const T& a, const T& b)
{
    return (a > b) ? a : b;   // this is called a ternary statement by the way. It's a nicer way to write simple if-else statements
}

int main()
{
    // Using template function 'swap' with ints
    {
        int x = 5;
        int y = 10;
        swap(x, y);
    }

    // Using template function 'swap' with strings
    {
        std::string x = "foo";
        std::string y = "bar";
        swap(x, y);
    }

    // Using template function 'max' with ints
    {
        int x = 1;
        int y = 2;
        int a = return_max(x, y);

        // std::cout << a << std::endl;
    }

    // Using template function 'max' with strings
    {
        std::string x = "abc";
        std::string y = "xyz";
        std::string a = return_max(x, y);

        // std::cout << a << std::endl;
    }
    return 0;
}