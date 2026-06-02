// Write a program to calculate average of five numbers given by user.

#include <iostream>

int main() {
    int sum = 0, n;

    std::cout << "Enter 5 numbers: " << std::endl;
    for(int i=0; i<5; i++) {
        std::cin >> n;
        sum+=n;
    }

    float avg = sum/5.0;

    std::cout << "The average of the 5 numbers is: " << avg << std::endl;

    return 0;
}