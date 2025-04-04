#include <iostream>
using namespace std;
class A {
  public:
    A() {
      cout << "A constructor called" << endl;
    }
    A& operator=(const A& other) {
      cout << "Assignment operator called" << endl;
    }
    ~A() {
      cout << "A destructor called" << endl;
    }
};

class B {
  A a_in;

  public:
    B(A _a) {
      a_in = _a;
    }
    // B(A _a) : a_in(_a) {}
};

int main() {
  A a_out;
  B b_out(a_out);

  cout << "bye bye" << endl;
}