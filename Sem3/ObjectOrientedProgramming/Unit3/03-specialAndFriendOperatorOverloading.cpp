#include <iostream>

class CustomArray {
private:
    int data[5];
    int size;

public:
    CustomArray() : size(5) {
        for (int i = 0; i < 5; i++) data[i] = (i + 1) * 10;
    }

    // 1. Overloading Special Operator: Subscript [ ]
    // Must return a reference to allow assignment (e.g., obj[0] = 5;)
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            std::cout << "Out of bounds!" << std::endl;
            return data[0];
        }
        return data[index];
    }

    // 2. Overloading Special Operator: Function Call ( )
    // Turns an object into a "Functor" (an object that acts like a function)
    void operator()(std::string message) {
        std::cout << "Functor called with message: " << message << std::endl;
    }

    // 3. Overloading Special Operator: Comma ,
    // Evaluates both expressions but discards the left and returns the right
    int operator,(int value) {
        std::cout << "Comma operator intercepting: " << value << std::endl;
        return value;
    }

    // 4. Overloading Special Operator: Member Access (->)
    // Used commonly in Smart Pointers. Must return a pointer to a class type.
    CustomArray* operator->() {
        return this;
    }
    
    void fallbackMethod() {
        std::cout << "Fallback method invoked via overloaded -> pointer simulation." << std::endl;
    }

    // 5. Operator Overloading Using Friend Function (<<)
    // CRITICAL EXAM TOPIC: Why must stream insertion << be a friend function and not a member?
    // ANSWER: For a member function, the invoking object must be on the LEFT-hand side.
    // In 'std::cout << obj', the left side is 'std::ostream', which you cannot modify.
    // Therefore, it must be written as a non-member friend function.
    friend std::ostream& operator<<(std::ostream& out, const CustomArray& arr);
};

std::ostream& operator<<(std::ostream& out, const CustomArray& arr) {
    out << "[ ";
    for (int i = 0; i < arr.size; i++) {
        out << arr.data[i] << " ";
    }
    out << "]";
    return out; // Return out stream to allow stream chaining (e.g., cout << a << b;)
}

int main() {
    std::cout << "=== TOPIC: SPECIAL & FRIEND OPERATORS ===" << std::endl;

    CustomArray container;

    // Testing Friend stream operator
    std::cout << "Printing entire object via << : " << container << std::endl;

    // Testing Subscript [ ]
    container[2] = 999;
    std::cout << "Modified index 2 via []: " << container[2] << std::endl;

    // Testing Functor ( )
    container("Hello Syllabus!");

    // Testing -> pointer simulation
    container->fallbackMethod();

    // Testing Comma operator
    int finalResult = (container , 42); 
    std::cout << "Comma Operator final evaluated outcome: " << finalResult << std::endl;

    return 0;
}