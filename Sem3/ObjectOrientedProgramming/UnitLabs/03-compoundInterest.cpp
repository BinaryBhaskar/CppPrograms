// Write a program to calculate compound interest given P, R and T.

#include <iostream>

int main() {
    float p, r, t;
    std::cout << "Enter principal amount: ";
    std::cin >> p;
    std::cout << "Enter rate: ";
    std::cin >> r;
    std::cout << "Enter time period: ";
    std::cin >> t;

    float res = p;
    for (int i=0; i<t; i++) res *= (1+r/100);

    std::cout << "Total amount to be paid back is: " << res << std::endl;
    return 0;
}