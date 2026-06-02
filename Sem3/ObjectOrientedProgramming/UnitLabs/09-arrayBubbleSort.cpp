// Write a function to perform sorting using bubble sort algorithm. Use arrays to store the list of numbers. Also write main() function to read contents and display output.

#include <iostream>
#include <array>

std::array<int, 100> bubbleSort(std::array<int, 100> arr, int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

int main() {
    std::array<int, 100> arr;
    int n;
    arr = {5, 2, 9, 1, 5, 6};
    n = 6;

    arr = bubbleSort(arr, n);
    for (int i=0; i<n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}