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