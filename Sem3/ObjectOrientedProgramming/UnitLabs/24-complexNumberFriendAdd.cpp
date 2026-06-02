// Write a program to add two complex numbers using a friend function and appropriate constructor function.

#include <iostream>

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
    friend Complex addComplex(const Complex& c1, const Complex& c2);
};

Complex addComplex(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(2.5, 3.5);
    Complex c2(1.5, 4.5);

    std::cout << "Complex Number 1: ";
    c1.display();
    std::cout << "Complex Number 2: ";
    c2.display();

    Complex result = addComplex(c1, c2);
    std::cout << "Sum of Complex Numbers: ";
    result.display();

    return 0;
}
