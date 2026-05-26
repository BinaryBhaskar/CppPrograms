// Set 2: Lifecycles & Diamonds
// Concepts: Top-Down Constructor Order, Passing Parameters to Base Constructors, Virtual Base Class (Diamond Solution).
// Task: Build a power distribution layout for a smart appliance grid that avoids ambiguous resource duplication.
// Requirements:
// Create a root base class called PowerGrid with a parameterized constructor that initializes an integer voltage.
// Inherit two intermediate classes from PowerGrid: SolarRouter and BatteryRouter. Both must use virtual inheritance (virtual public) to eliminate structural duplication. Ensure their constructors pass the voltage parameter back to PowerGrid.
// Create a final derived class called SmartHub that inherits from both SolarRouter and BatteryRouter. Its parameterized constructor must accept a voltage parameter and pass it down via the member initializer list.
// Inside SmartHub, write a method showGridVoltage() that prints the inherited voltage variable.
// In main(), instantiate a SmartHub object inside a nested block { } to observe the constructor and destructor sequences.
// Verify in your code output that PowerGrid's constructor executes exactly once instead of twice, and that the destructors clear out in perfect bottom-up reverse order.

#include <iostream>

class PowerGrid {
public:
    int voltage;

    PowerGrid(int v) {
        this->voltage = v;
        std::cout << "Power Grid created" << std::endl;
    }

    ~PowerGrid() {
        std::cout << "Power Grid destroyed" << std::endl;
    }
};

class SolarRouter: virtual public PowerGrid {
public:
    SolarRouter(int v): PowerGrid(v) {
        std::cout << "Solar Grid created" << std::endl;
    }
    ~SolarRouter() {
        std::cout << "Solar Grid destroyed" << std::endl;
    }
};

class BatteryRouter: virtual public PowerGrid {
public:
    BatteryRouter(int v): PowerGrid(v) {
        std::cout << "Battery Grid created" << std::endl;
    }
    ~BatteryRouter() {
        std::cout << "Battery Grid destroyed" << std::endl;
    }
};

class SmartHub: public SolarRouter, public BatteryRouter {
public:
    SmartHub(int v): PowerGrid(v), SolarRouter(v), BatteryRouter(v) {
        std::cout << "Smart Hub created" << std::endl;
    }

    ~SmartHub() {
        std::cout << "Smart Hub destroyed" << std::endl;
    }

    void showGridVoltage() {
        std::cout << this->voltage << std::endl;
    };
};

int main() {
    {
        SmartHub wifiRouter(100);
    }

    return 0;
}