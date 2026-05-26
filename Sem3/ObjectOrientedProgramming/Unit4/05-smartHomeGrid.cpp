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