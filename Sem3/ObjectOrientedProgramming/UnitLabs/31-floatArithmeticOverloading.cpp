// Create a class FLOAT that contains one float data member. Overload all the four arithmetic operators so that they operate on the objects of FLOAT.

#include <iostream>

class FLOAT {
private:
    float value;
public:
    FLOAT(float v = 0.0f) : value(v) {}
    FLOAT operator+(const FLOAT& other) const {
        return FLOAT(value + other.value);
    }
    FLOAT operator-(const FLOAT& other) const {
        return FLOAT(value - other.value);
    }
    FLOAT operator*(const FLOAT& other) const {
        return FLOAT(value * other.value);
    }
    FLOAT operator/(const FLOAT& other) const {
        if (other.value != 0) {
            return FLOAT(value / other.value);
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
            return FLOAT(0); // Return a default value in case of division by zero
        }
    }
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    FLOAT f1(5.5f);
    FLOAT f2(2.0f);

    FLOAT sum = f1 + f2;
    FLOAT difference = f1 - f2;
    FLOAT product = f1 * f2;
    FLOAT quotient = f1 / f2;

    std::cout << "f1: ";
    f1.display();
    std::cout << "f2: ";
    f2.display();
    std::cout << "Sum: ";
    sum.display();
    std::cout << "Difference: ";
    difference.display();
    std::cout << "Product: ";
    product.display();
    std::cout << "Quotient: ";
    quotient.display();

    return 0;
}