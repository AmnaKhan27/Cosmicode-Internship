#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
  
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        cout << real;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << -imag << "i";
        }
        cout << endl;
    }
};

int main() {
  
    Complex c1(3.5, 2.7);
    Complex c2(1.2, -4.3);

    Complex result = c1 + c2;

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    cout << "Sum of complex numbers: ";
    result.display();

    return 0;
}