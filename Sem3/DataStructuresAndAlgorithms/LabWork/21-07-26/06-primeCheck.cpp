#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    bool isPrime = true;

    if (num <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        std::cout << num << " is a prime number. \n";
    } else {
        std::cout << num << " is not a prime number. \n";
    }

    return 0;
}