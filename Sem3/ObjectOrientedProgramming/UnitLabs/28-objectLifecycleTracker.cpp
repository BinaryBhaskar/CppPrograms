// Write a program to illustrate the creation and destruction of objects.

#include <iostream>

class LifecycleTracker {
public:
    LifecycleTracker() {
        std::cout << "Object created." << std::endl;
    }

    ~LifecycleTracker() {
        std::cout << "Object destroyed." << std::endl;
    }
};

int main() {
    LifecycleTracker obj1;
    LifecycleTracker obj2;

    return 0;
}
