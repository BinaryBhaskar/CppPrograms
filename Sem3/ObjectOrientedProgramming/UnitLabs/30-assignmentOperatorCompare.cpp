// Create two objects of a class with two integer type members. Compare if the two objects have same member values using overloaded == operator.

#include <iostream>

class MyClass {
private:
    int member1;
    int member2;
public:
    MyClass(int m1, int m2) : member1(m1), member2(m2) {}
    bool operator==(const MyClass& other) const {
        return (member1 == other.member1) && (member2 == other.member2);
    }
    void display() const {
        std::cout << "Member 1: " << member1 << ", Member 2: " << member2 << std::endl;
    }
};

int main() {
    MyClass obj1(10, 20);
    MyClass obj2(10, 20);
    MyClass obj3(15, 25);
    obj1.display();
    obj2.display();
    obj3.display();
    if (obj1 == obj2) {
        std::cout << "obj1 and obj2 are equal." << std::endl;
    } else {
        std::cout << "obj1 and obj2 are not equal." << std::endl;
    }
    if (obj1 == obj3) {
        std::cout << "obj1 and obj3 are equal." << std::endl;
    } else {
        std::cout << "obj1 and obj3 are not equal." << std::endl;
    }
    return 0;
}