#include <iostream>

class Node {
public:
    int data;

    // 1. The 'this' Pointer
    // Constant pointer available to member methods. Resolves local parameter variable hiding conflicts.
    Node(int data){
        this->data = data;
    }

    void printMemoryLocation() {
        std::cout << "Object internal location value (this): " << this << std::endl;
    }

    void showData() {
        std::cout << "Node data payload contents: " << data << std::endl;
    }
};

int main() {
    std::cout << "=== TOPIC: DYNAMIC OPERATORS, THIS & MEMBER POINTERS ===" << std::endl;

    // 2. Array of Objects & Pointers to Objects
    std::cout << "\n--- Array of Objects ---" << std::endl;
    Node cluster[2] = { Node(10), Node(20) };
    Node* clusterPtr = cluster; // Pointer targeting initial array element
    clusterPtr->showData();
    (clusterPtr + 1)->showData(); // Pointer arithmetic shift step to next element block

    // 3. C++ Dynamic Allocation Operators (new & delete)
    std::cout << "\n--- Heap Memory Dynamics ---" << std::endl;
    
    // Initializing Allocated Memory on Allocation
    int* dynamicScalar = new int(1337); 
    
    // Allocating Array dynamically on the heap space
    int* dynamicArray = new int[3]{100, 200, 300}; 

    // Allocating Objects Dynamically
    Node* dynamicNode = new Node(500);
    dynamicNode->printMemoryLocation();

    // Mandatory Explicit Cleanup Phase
    delete dynamicScalar;
    delete[] dynamicArray; // delete[] syntax is required here for arrays to avoid memory leakage
    delete dynamicNode;    // Safely invokes destructor instance automatically

    // 4. Pointer to Class Members (Specific Complex Syntax)
    std::cout << "\n--- Pointer to Class Members ---" << std::endl;
    Node sampleInstance(88);

    // Pointer to Data Member declaration layout
    int Node::*dataMemberPtr = &Node::data;
    std::cout << "Direct variable retrieval via data pointer layout: " << sampleInstance.*dataMemberPtr << std::endl;

    // Pointer to Member Function declaration layout
    void (Node::*methodMemberPtr)() = &Node::showData;
    std::cout << "Executing class method pointer structure: ";
    (sampleInstance.*methodMemberPtr)(); // Uses special pointer syntax structure instance operator

    return 0;
}