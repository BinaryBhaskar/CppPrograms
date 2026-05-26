#include <iostream>

class Engine {
public:
    void startEngine() { std::cout << "Engine purring..." << std::endl; }
};

class Wheels {
public:
    void rotateWheels() { std::cout << "Wheels turning..." << std::endl; }
};

// 1. Inheriting Multiple Base Classes
// Separate the base classes with a comma, each with its own access specifier.
class Car : public Engine, public Wheels {
    // This class inherits methods from both Engine and Wheels seamlessly.
};

// 2. Base Class Access Control Variations
class Base {
private:
    int privateVar = 1;     // Accessible ONLY inside Base
protected:
    int protectedVar = 2;   // Accessible in Base and Derived classes
public:
    int publicVar = 3;      // Accessible anywhere
};

// Public Inheritance: Public stays Public, Protected stays Protected.
class PublicDerived : public Base {
    void access() {
        // int x = privateVar; // ERROR!
        int y = protectedVar;  // Valid
        int z = publicVar;     // Valid
    }
};

// Protected Inheritance: Both Public and Protected members become PROTECTED inside this class.
class ProtectedDerived : protected Base {
    // publicVar is now PROTECTED inside this class. Outside code cannot see it anymore.
};

// Private Inheritance: Both Public and Protected members become PRIVATE inside this class.
class PrivateDerived : private Base {
public:
    // 3. Granting Access (Access Declaration)
    // If you used private inheritance, you can selectively bring back a base member 
    // to its original public status using the 'using' keyword.
    using Base::publicVar; // Restores publicVar to public status for PrivateDerived
};

int main() {
    std::cout << "=== TOPIC: INHERITANCE ACCESS & MULTIPLE BASE CLASSES ===" << std::endl;

    Car myCar;
    myCar.startEngine();  // From Engine
    myCar.rotateWheels(); // From Wheels

    PrivateDerived pd;
    // pd.protectedVar = 10; // ERROR! It's private now.
    pd.publicVar = 100;      // VALID because we explicitly granted access back!
    std::cout << "Restored Public Var: " << pd.publicVar << std::endl;

    return 0;
}