// Practice Problem 18: Functors & Higher-Order Filters
// Concepts Tested: Function Objects (Functors), Overloading Function Call Operator (operator()), Higher-Order Functions.
//
// Description:
// Implement a function object (functor) that encapsulates a filtering criterion, and pass it to a generic array filter function.
//
// Requirements:
// 1. Functor Class 'ThresholdFilter':
//    - Private Member: int threshold
//    - Constructor: ThresholdFilter(int t) : threshold(t) {}
//    - Overloaded Operator: bool operator()(int value) const:
//      Returns true if value >= threshold, false otherwise.
// 2. Functor Class 'RangeFilter':
//    - Private Members: int minVal, maxVal
//    - Constructor: RangeFilter(int minV, int maxV) : minVal(minV), maxVal(maxV) {}
//    - Overloaded Operator: bool operator()(int value) const:
//      Returns true if value is within [minVal, maxVal] inclusive.
// 3. Generic Global Function:
//    - template <typename Predicate>
//      void printFiltered(const int arr[], int size, Predicate pred, std::string filterName):
//      Iterates through `arr`, calls `pred(arr[i])`, and prints elements that satisfy the predicate.
// 4. In main():
//    - Declare an array of integers: `{12, 45, 7, 89, 23, 56, 3, 90, 34}`.
//    - Instantiate `ThresholdFilter filter50(50)`.
//    - Call `printFiltered(numbers, size, filter50, "Values >= 50")`.
//    - Instantiate `RangeFilter range20to60(20, 60)`.
//    - Call `printFiltered(numbers, size, range20to60, "Values between 20 and 60")`.

#include <iostream>
#include <string>

// TODO: Define ThresholdFilter, RangeFilter, and printFiltered template function here

int main() {
    // TODO: Write code testing functor filtering mechanisms

    return 0;
}
