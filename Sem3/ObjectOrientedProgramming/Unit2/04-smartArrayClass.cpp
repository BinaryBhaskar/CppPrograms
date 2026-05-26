// Problem 1: The Smart Array Class
// Concepts: Deep Copy Constructor, Dynamic Initialization, Destructor Heap Cleanup.
// Task: Create a class SmartArray that encapsulates a raw dynamic array.
// Requirements:
// It should have two private attributes: int* arr and int size.
// Write a parameterized constructor SmartArray(int s) that allocates an integer array of size s on the heap and fills it with sequential squares (0,1,4,9,…).
// Write a proper Copy Constructor that performs a strict deep copy.
// Write a destructor that safely releases the heap memory and prints [Deleted Array of size X].
// The Test Block: Inside main(), create an instance SmartArray a1(4);. In a nested block { }, create a clone using instantiation syntax: SmartArray a2 = a1;. Ensure that when a2 goes out of scope and is destroyed, a1's internal array remains uncorrupted and accessible.

#include <iostream>

class SmartArray {
    int *arr;
    int size;

public:
    SmartArray(int s) {
        size = s;
        arr = new int[size];

        for (int i=0; i<this->size; i++) {
            arr[i] = i*i;
        }
    }

    SmartArray(const SmartArray& smartArr) {
        size = smartArr.size;
        arr = new int[size];
        for (int i=0; i<this->size; i++) {
            arr[i] = smartArr.arr[i];
        }
    }

    ~SmartArray() {
        delete[] arr;
        std::cout << "[Deleted array of size " << size << "]" << std::endl;
    }
};

int main() {
    SmartArray a1(4);
    {
        SmartArray a2 = a1;
    }
    return 0;
}