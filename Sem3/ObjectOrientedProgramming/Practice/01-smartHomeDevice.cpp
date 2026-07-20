// Practice Problem 01: Smart Home Device Tracker
// Concepts Tested: Classes, Private Data Members, Parameterized Constructor, Getters/Setters, Inline Member Functions.
//
// Description:
// Design a SmartDevice class representing an IoT home device (e.g., Smart Thermostat, Smart Bulb).
//
// Requirements:
// 1. Create a class named 'SmartDevice'.
// 2. Private Data Members:
//    - std::string deviceID
//    - std::string deviceName
//    - bool isOnline
//    - double powerRating (in Watts)
// 3. Constructors & Destructor:
//    - Default constructor initializing ID to "DEV-000", name to "Generic Device", isOnline to false, powerRating to 0.0.
//    - Parameterized constructor initializing ID, name, and powerRating. Set isOnline to false by default.
// 4. Member Functions:
//    - inline void togglePower(): Flips the isOnline state (true <-> false).
//    - void setPowerRating(double watts): Updates powerRating (validate that watts > 0).
//    - double getPowerRating() const: Returns current power rating.
//    - bool getStatus() const: Returns online status.
//    - void displayStatus() const: Prints device details nicely formatted.
// 5. In main():
//    - Instantiate one device using default constructor and one using parameterized constructor.
//    - Toggle the power of the parameterized device to online.
//    - Update its power rating.
//    - Display status of both devices to verify output.

#include <iostream>
#include <string>

// TODO: Define your SmartDevice class here
class SmartDevice {
private:
    std::string deviceID;
    std::string deviceName;
    bool isOnline;
    double powerRating;

public:
    SmartDevice(): deviceID("DEV-000"), deviceName("Generic Device"), powerRating(0.0), isOnline(false){}
    SmartDevice(std::string id, std::string name, double watts) {
        deviceID = id;
        deviceName = name;
        powerRating = watts;
        isOnline = false;
    }
    ~SmartDevice() = default;

    inline void togglePower() {
        isOnline = !isOnline;
    }

    void setPowerRating(double watts) {
        if (watts > 0) {
            powerRating = watts;
        }
    }

    double getPowerRating() const {
        return powerRating;
    }

    bool getStatus() const {
        return isOnline;
    }

    void displayStatus() const {
        std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        std::cout << "Device ID    : " << deviceID << '\n';
        std::cout << "Device Name  : " << deviceName << '\n';
        std::cout << "Power Rating : " << powerRating << " W\n";
        std::cout << "Status       : " << (isOnline ? "Online" : "Offline") << '\n';
        std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    }
};

int main() {
    SmartDevice device1;
    SmartDevice device2("BULB-001", "Havells Smart Bulb", 12.0);

    std::cout << "Initial Status:\n";
    device1.displayStatus();
    device2.displayStatus();

    device2.togglePower();
    device2.setPowerRating(15.0);

    std::cout << "\nAfter Changes:\n";
    device2.displayStatus();

    return 0;
}
