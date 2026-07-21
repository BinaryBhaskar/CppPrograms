#include <iostream>

void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int numA, numB;
    std::cout << "Enter number A: ";
    std::cin >> numA;
    std::cout << "Enter number B: ";
    std::cin >> numB;

    std::cout << "Before swapping: A = " << numA << ", B = " << numB << "\n";

    swap(numA, numB);

    std::cout << "After swapping: A = " << numA << ", B = " << numB << "\n";

    return 0;
}