// Practice Problem 10: Stream Operator Overloading (<< and >>)
// Concepts Tested: Friend Functions, Stream Insertion Operator (<<), Stream Extraction Operator (>>), Validation Logic.
//
// Description:
// Create a Time class representing hours, minutes, and seconds, and overload iostream operators (<< and >>) as friend functions.
//
// Requirements:
// 1. Create a class named 'Time'.
// 2. Private Members:
//    - int hours
//    - int minutes
//    - int seconds
// 3. Constructors:
//    - Time(int h = 0, int m = 0, int s = 0) (Applies default arguments and normalization, e.g. 65 sec -> 1 min 5 sec).
// 4. Friend Stream Operators:
//    - friend std::ostream& operator<<(std::ostream& os, const Time& t):
//      Prints formatted time as `HH:MM:SS` (padded with leading zeros if < 10).
//    - friend std::istream& operator>>(std::istream& is, Time& t):
//      Prompts user for hours, minutes, seconds, and normalizes invalid minute/second ranges (> 59).
// 5. Member Functions:
//    - void normalize(): Adjusts seconds/minutes if >= 60.
// 6. In main():
//    - Use `std::cin >> t1;` to read a Time object from user/console.
//    - Output the object directly using `std::cout << t1 << std::endl;`.

#include <iostream>
#include <iomanip>

// TODO: Define your Time class and stream operator overloads here

int main() {
    // TODO: Write code demonstrating cin >> time and cout << time

    return 0;
}
