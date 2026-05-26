#include <iostream>

// ============================================================================
// CONSTRUCTOR / DESTRUCTOR ORDER & PARAMETER PASSING
// ============================================================================
class Mother {
protected:
    int houseNumber;
public:
    // Parameterized constructor
    Mother(int hn) : houseNumber(hn) {
        std::cout << "[Mother Constructor] Running." << std::endl;
    }
    ~Mother() {
        std::cout << "[Mother Destructor] Running." << std::endl;
    }
};

class Child : public Mother {
private:
    int age;
public:
    // Passing Parameters to Base Class Constructors using Member Initializer List
    Child(int hn, int a) : Mother(hn), age(a) {
        std::cout << "[Child Constructor] Running. Passed house number: " << this->houseNumber << std::endl;
    }
    ~Child() {
        std::cout << "[Child Destructor] Running." << std::endl;
    }
};

// ============================================================================
// VIRTUAL BASE CLASSES (THE DIAMOND PROBLEM)
// ============================================================================
class Grandparent {
public:
    int goldAmount = 500;
};

// CRITICAL EXAM SYNTAX: Use 'virtual public' to ensure only ONE copy of Grandparent is inherited.
class ParentA : virtual public Grandparent {};
class ParentB : virtual public Grandparent {};

class Grandchild : public ParentA, public ParentB {
public:
    void showGold() {
        // Without 'virtual', this line throws an AMBIGUITY COMPILER ERROR because
        // Grandchild would have two distinct copies of 'goldAmount' (one from ParentA, one from ParentB).
        std::cout << "Grandchild inherited " << goldAmount << " gold bars securely!" << std::endl;
    }
};


int main() {
    std::cout << "=== TOPIC: LIFECYCLES & VIRTUAL BASE CLASSES ===" << std::endl;

    std::cout << "\n--- Instantiating Child ---" << std::endl;
    {
        Child c(123, 15);
        // CRITICAL EXAM RULE: 
        // Constructors execute TOP-DOWN (Base first, then Derived).
        // Destructors execute BOTTOM-UP (Derived first, then Base).
    } // 'c' goes out of scope here, firing destructors

    std::cout << "\n--- Testing Diamond Problem Solution ---" << std::endl;
    Grandchild gc;
    gc.showGold(); 

    return 0;
}