#include <iostream>

int main() {
    int num;
    std::cout << "Enter size of Matrix: ";
    std::cin >> num;

    int arr[100][100];
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i>=j) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    std::cout << "Lower Triangle Matrix: \n";

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}