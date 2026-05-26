// Set 3: Runtime Polymorphism
// Concepts: Early vs. Late Binding Verification, Pure Virtual Functions (Abstract Interface), Overriding Base Frameworks.
// Task: Create a flexible physics simulation loop engine that resolves rigid-body entity states dynamically at runtime.
// Requirements:
// Create an abstract base class named PhysicsEntity.
// Add a non-virtual method logIdentity() that prints "[Static] Base Entity Static Registry Tracker.".
// Add a pure virtual function virtual void calculateForces() = 0;.
// Derive a concrete class named Projectile from PhysicsEntity. Implement the mandatory calculateForces() method to print "[Dynamic] Projectile recalculating gravity arc trajectories!".
// Inside Projectile, override the non-virtual logIdentity() method to print "[Static] Projectile Override Signature.".
// In main(), declare a raw base pointer (PhysicsEntity* entityPtr). Target it to a dynamically allocated heap instance of Projectile (new Projectile()).
// Execute both methods through that base pointer. In your code comments, explain precisely why one statement showcases Early Binding while the other showcases Late Binding. Clean up the heap allocation using delete.

#include <iostream>

class PhysicsEntity {
public:
    virtual void calculateForces() = 0;

    void logEntity() {
        std::cout << "[Static] Base Entity Static Registry Tracker." << std::endl;
    }
};

class Projectile: public PhysicsEntity {
    void calculateForces() override {
        std::cout << "[Dynamic] Projectile recalculating gravity arc trajectories!" << std::endl;
    }

    void logEntity() {
        std::cout << "[Static] Projectile Override Signature." << std::endl;
    }
};

int main() {
    PhysicsEntity* entityPtr;
    Projectile arrow;
    entityPtr = &arrow;

    entityPtr->calculateForces(); // uses overridden function in Projectile because it is pure virtual function and every inheritance has its own signature for it, thus being Late Binding.
    entityPtr->logEntity(); // uses Base function because of Early Binding / Static Binding
}

/* entityPtr->logEntity(); (Early/Static Binding)
    Because logEntity() is not declared with the virtual keyword in the base class,
    the compiler resolves this call at compile-time based strictly on the data type
    of the pointer (PhysicsEntity*).
    Since the pointer is technically a PhysicsEntity*,
    it binds directly to the base class method implementation,
    ignoring the fact that it points to a Projectile object.
*/

/* entityPtr->calculateForces(); (Late/Dynamic Binding)
    Because calculateForces() is declared as a virtual function,
    the compiler defers resolution until runtime.
    The program uses the hidden class instance pointer (_vptr) to look up
    the active object's Virtual Method Table (V-Table).
    Since the active object at that address is a Projectile,
    it dynamically maps to and executes Projectile::calculateForces().
*/