// Concepts: Try-Catch-Throw sequence loops, Type-specific cascading catch structures, Catch-All fallback implementation.
// Task: Simulate a vehicle navigation routing terminal that throws specific exception signatures when hitting spatial environment hazards.
// Requirements:
// Write a function MapsSector(int conditionCode) that evaluates a tracking integer parameter:
// If code is 1 → throw a raw integer value 505 (representing an internal sensor tilt fault).
// If code is 2 → throw a string literal phrase character array ("Obstacle Obstruction Identified").
// If code is 3 → throw a floating-point calculation error variable 9.81f (representing an environmental traction variance).
// In main(), set up a loop that iterates from 1 to 3, wrapping your function call inside a singular, solid try framework block.
// Build a sequential cascade of handlers matching your targets:
// A catch interceptor specifically targeting int identifiers.
// A catch interceptor specifically targeting const char* message descriptions.
// A Catch-All Handler (catch(...)) to capture the remaining unmapped float error instance.
// Concept Verification Check: In your code comments at the bottom of the file, explain what would happen at runtime if you accidentally placed the catch(...) block at the very top of the catch chain instead of the bottom.

#include <iostream>
#include <string>

void MapsSelector(int conditionCode) {
    if (conditionCode == 1) {
        throw 505;
    }
    else if (conditionCode == 2) {
        throw "Obstacle Obstruction Identified";
    }
    else if (conditionCode == 3) {
        throw 9.81f;
    }
}

int main() {
    for (int i=1; i<4; i++) {
        try {
            MapsSelector(i);
        }
        catch (int errorCode) {
            std::cout << "[Caught Integer Fault]: Error Code Code " << errorCode << std::endl;
        }
        catch (const char* errorCode) {
            std::cout << "[Caught String Fault]: Error Details: " << errorCode << std::endl;
        }
        // If catch(...) {} was at the top of the exception handling list, it will precede all other error handling after it.
        catch(...) { 
            std::cout << "[Unknown Fault Error]: Unknown Exception Handled" << std::endl;
        }
    }
}