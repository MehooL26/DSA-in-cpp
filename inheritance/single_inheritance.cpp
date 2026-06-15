// In single inheritance, a sub-class is derived from only one super class. It inherits the properties and behavior of a single-parent class.
#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "This is a Vehicle" << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        cout << "This Vehicle is Car" << endl;
    }
};

int main() {
   
    Car obj;
    return 0;
}