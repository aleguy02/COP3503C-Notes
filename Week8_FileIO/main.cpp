#include <cassert>
#include <iostream>
#include <typeinfo>
using namespace std;

/* Uncomment the name of the example you want to see */
// #define IMPLICIT_CAST
// #define C_STYLE_CAST
// #define STATIC_CAST
// #define REINTERPRET_CAST

int main()
{
#ifdef IMPLICIT_CAST
    {
        const int num = 5;
        const float num_implicit_cast = num;
        const int another_num = num_implicit_cast;
        cout << num << " : " << typeid(num).name() << endl;
        cout << num_implicit_cast << " : " << typeid(num_implicit_cast).name() << endl;
        cout << another_num << " : " << typeid(another_num).name() << endl;

        // You can cast in unexpected ways
        const char ch = 't';
        const int ch_implicit_cast = ch;
        cout << ch << " : " << typeid(ch).name() << endl;
        cout << ch_implicit_cast << " : " << typeid(ch_implicit_cast).name() << endl;
    }
#endif

#ifdef C_STYLE_CAST
    {
        /* Every FAQ, guide, or explanation of casting in C++ suggests the same thing:
         * Avoid C style casts
         */
        // Sometimes it works
        const int y = 42;
        const float cast_y = (float)y;
        cout << "Float value: " << cast_y << endl;

        // ...but sometimes it doesn't
        const int x = 42;
        const int* temp = &x;  // uncomment and view in debug
        // const double* ptr = (double*)&x;
        cout << "Interpreted double value: " << *temp << endl;  // This is called undefined behavior
    }
#endif

#ifdef STATIC_CAST
    {
        const int x = 5;
        // const double* ptr = static_cast<const double*>(&x);  // uncomment and see what happens
        const float x_cast = static_cast<float>(x);
        cout << x_cast << " : " << typeid(x_cast).name() << endl;
    }
#endif

#ifdef REINTERPRET_CAST
    // This code converts a pointer to integer and back
    // A scenario where this would be useful is if you wanted to create portable code
    // that prints pointer address with the same formatting on every system this code
    // runs
    {
        int i = 7;

        // using static_cast raises an error
        // std::uintptr_t v1 = static_cast<std::uintptr_t>(&i);

        // uintptr_t is just an unsigned integer capable of holding a pointer to void
        std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i);

        // This makes sure the output is formatted the same across systems
        std::cout << "The value of &i is " << std::showbase << std::hex << v1 << std::flush;

        // cast integer back to a pointer
        int* p1 = reinterpret_cast<int*>(v1);
        assert(p1 == &i);
    }
#endif
}