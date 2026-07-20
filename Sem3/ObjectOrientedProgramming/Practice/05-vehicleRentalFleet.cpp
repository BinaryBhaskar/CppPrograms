// Practice Problem 05: Vehicle Rental Fleet (Single & Multilevel Inheritance)
// Concepts Tested: Inheritance, Constructor Initialization List, Function Overriding, Protected Access Specifier.
//
// Description:
// Model a vehicle rental system using multilevel inheritance: Base class `Vehicle` -> Derived `Car` -> Derived `ElectricCar`.
//
// Requirements:
// 1. Base Class 'Vehicle':
//    - Protected Members: std::string brand, double rentalRatePerDay.
//    - Public Constructor: Vehicle(std::string b, double rate)
//    - Public Member Function: void displayDetails() const
// 2. Derived Class 'Car' (inherits publicly from Vehicle):
//    - Protected Members: int numberOfDoors, std::string fuelType.
//    - Public Constructor: Car(std::string b, double rate, int doors, std::string fuel) (Uses base initializer list!)
//    - Function Overriding: void displayDetails() const (Extends base displayDetails to include doors and fuel type).
// 3. Derived Class 'ElectricCar' (inherits publicly from Car):
//    - Private Members: double batteryCapacitykWh, double chargeRangeKm.
//    - Public Constructor: ElectricCar(std::string b, double rate, int doors, double battery, double range)
//    - Function Overriding: void displayDetails() const
// 4. In main():
//    - Instantiate a Vehicle, a Car, and an ElectricCar object.
//    - Call displayDetails() on each object to demonstrate method overriding across multilevel inheritance.

#include <iostream>
#include <string>

// TODO: Define Vehicle, Car, and ElectricCar classes here

int main() {
    // TODO: Write test code demonstrating multilevel inheritance

    return 0;
}
