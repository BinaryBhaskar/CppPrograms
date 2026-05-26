// The Step Counter Engine
// Concepts: Prefix vs. Postfix Overloading Syntax, Shorthand Operators (+=), Returning References.
// Task: Build a distance tracking tracker class called StepCounter.
// Requirements:
// Add a private attribute: int steps. Initialize it via a constructor.
// Overload the Prefix Increment (++obj) member function. It must increment steps by 1 and return a reference to the current object.
// Overload the Postfix Increment (obj++) member function. It must take the mandatory hidden int dummy parameter, cache a temporary snapshot, increment the actual object's step count, and return the old snapshot by value.
// Overload the Shorthand Compound Assignment (+=) operator as a member function to add a raw integer directly to your steps (e.g., counter += 500;). Return *this as a reference.
// Validate in main() by performing assignments like StepCounter finalCount = ++myCounter; and verify that prefix and postfix match their expected structural behaviors.

#include <iostream>

class StepCounter {
    int steps;

public:
    StepCounter() {
        this->steps = 0;
    }

    StepCounter(int steps) {
        this->steps = steps;
    }

    StepCounter operator++(int) {
        StepCounter temp = *this;
        (this->steps)++;
        return temp;
    };

    StepCounter& operator++() {
        ++(this->steps);
        return *this;
    }

    StepCounter& operator+=(StepCounter rhs) {
        this->steps+=rhs.steps;
        return *this;
    }

    void count() {
        std::cout << "Steps taken: " << steps << std::endl;
    }
};

int main() {
    StepCounter c1 = StepCounter();
    StepCounter c2 = StepCounter(100);

    std::cout << "C1 and C2" << std::endl;
    c1.count();
    c2.count();

    std::cout << "C1 incremented" << std::endl;
    c1++;
    c1.count();

    std::cout << "C2 stored before increment and then printed after increment" << std::endl;
    StepCounter c = ++c2;
    c.count();
    c2.count();

    std::cout << "C1 after adding C2 to it" << std::endl;
    c1+=c2;
    c1.count();

    return 0;
}