#include <iostream>

class SmartDevice {
public:
    // 1. Early Binding (Static Binding)
    // Resolved at compile time based strictly on the type of the pointer/reference.
    void bootMessage() {
        std::cout << "[Early Binding] Booting standard device firmware..." << std::endl;
    }

    // 2. Virtual Function / Late Binding (Dynamic Binding)
    // Resolved at runtime based on the actual object being pointed to, via a V-Table lookup.
    virtual void processAction() {
        std::cout << "Device performing generic system calculations." << std::endl;
    }
};

class SmartPhone : public SmartDevice {
public:
    void bootMessage() {
        std::cout << "[Early Binding] Booting customized iOS/Android skin..." << std::endl;
    }

    void processAction() override {
        std::cout << "Phone running advanced mobile application processing!" << std::endl;
    }
};

// ============================================================================
// PURE VIRTUAL FUNCTIONS & ABSTRACT CLASSES
// ============================================================================
// Any class containing at least one pure virtual function is an ABSTRACT CLASS.
// You cannot instantiate an object of this class type directly.
class Appliance {
public:
    // 3. Pure Virtual Function
    // Forces any concrete derived class to implement this specific signature.
    virtual void turnOn() = 0; 

    void generalSpecs() { std::cout << "120V Electrical Appliance." << std::endl; }
};

class Microwave : public Appliance {
public:
    // Implementing the mandatory pure virtual function
    void turnOn() override {
        std::cout << "Microwave humming. Heating food components." << std::endl;
    }
};

int main() {
    std::cout << "=== TOPIC: VIRTUAL FUNCTIONS & POLYMORPHISM ===" << std::endl;

    SmartDevice* ptr;
    SmartPhone phone;
    ptr = &phone; // Base pointer targeting derived object

    // Demonstration of Early vs Late Binding
    std::cout << "\n--- Binding Mechanics ---" << std::endl;
    ptr->bootMessage();   // Calls SmartDevice::bootMessage (Compiler look-up: Early Binding)
    ptr->processAction(); // Calls SmartPhone::processAction (Runtime look-up: Late/Dynamic Binding)

    // Demonstration of Abstract Classes
    std::cout << "\n--- Abstract Classes ---" << std::endl;
    // Appliance app; // ERROR! Cannot instantiate an abstract class directly.
    
    Microwave wave;
    Appliance* appliancePtr = &wave;
    appliancePtr->turnOn(); // Polymorphic invocation
    appliancePtr->generalSpecs();

    return 0;
}