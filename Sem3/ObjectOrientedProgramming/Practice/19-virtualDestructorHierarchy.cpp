// Practice Problem 19: Virtual Destructors & Memory Leak Prevention
// Concepts Tested: Virtual Destructors, Base Class Pointers, Dynamic Memory Allocation in Derived Classes, Polymorphic Deletion.
//
// Description:
// Demonstrate the critical importance of virtual destructors when deleting derived class objects through base class pointers.
//
// Requirements:
// 1. Class 'BaseResource':
//    - Protected Member: std::string resourceName
//    - Public Constructor: BaseResource(std::string name)
//    - VIRTUAL Destructor: virtual ~BaseResource():
//      Prints message showing BaseResource destructor cleanup.
//    - Virtual Function: virtual void useResource() const
// 2. Class 'NetworkConnection' (inherits from BaseResource):
//    - Private Member: char* packetBuffer (dynamically allocated dynamic memory!)
//    - Constructor: NetworkConnection(std::string name, int bufferSize):
//      Allocates `packetBuffer = new char[bufferSize]`.
//    - Destructor: ~NetworkConnection() override:
//      Prints message and executes `delete[] packetBuffer;` to prevent memory leaks!
//    - Function Overriding: void useResource() const override
// 3. In main():
//    - Create a base pointer targeting a dynamic derived object:
//      `BaseResource* resource = new NetworkConnection("ServerStream", 1024);`
//    - Invoke `resource->useResource();` polymorphically.
//    - Call `delete resource;`.
//    - Verify in terminal output that BOTH NetworkConnection destructor and BaseResource destructor are executed in reverse order.
//    - Comment on what would happen if ~BaseResource() was NOT marked virtual.

#include <iostream>
#include <string>

// TODO: Define BaseResource and NetworkConnection classes here

int main() {
    // TODO: Write code testing polymorphic deletion with virtual destructor

    return 0;
}
