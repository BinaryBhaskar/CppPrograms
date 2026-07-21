#include <iostream>

void fibonacci(int n, int arr[]) {
    arr[0] = 0;
    arr[1] = 1;

    for (int i=2; i<n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
}

int main() {
    int num;
    int fibSeq[100];

    std::cout << "Enter n: ";
    std::cin >> num;

    fibonacci(num, fibSeq);

    for (int i=0; i<num; i++) {
        std::cout << fibSeq[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}