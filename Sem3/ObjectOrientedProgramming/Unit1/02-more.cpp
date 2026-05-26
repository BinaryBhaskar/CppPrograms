#include <iostream>
#include <string>

// ============================================================================
// PART 1: USER DEFINED DATA TYPES
// ============================================================================

// 1. Enumerated Types (enum) & Use of Tag Names
// "SecurityLevel" is the TAG NAME. In C++, you can use it directly as a type 
// without typing the word 'enum' every time.
enum SecurityLevel {
    LOW,      // Defaults to 0
    MEDIUM,   // Defaults to 1
    HIGH = 5, // Explicitly set to 5
    CRITICAL  // Automatically increments to 6
};

// 2. Scope of Tag Names
// Global scope tag name: accessible anywhere in this file.
struct GlobalStruct { 
    int data; 
}; 

void demonstrateScope() {
    // Local scope tag name: only visible inside this function.
    struct LocalStruct { int id; }; 
    LocalStruct localObj{101};
}

void demonstrateAnonymousUnion() {
    // 3. Anonymous Unions
    // It has no tag name and no object name. 
    // All members share the exact same memory space (size of the largest element).
    // Members are accessed directly in the surrounding scope.
    union {
        int rawInt;
        char bytes[4];
    };

    rawInt = 0x41424344; // Hex values for ASCII characters D, C, B, A

    std::cout << "--- Anonymous Union ---" << std::endl;
    // Because they share memory, altering rawInt alters bytes!
    std::cout << "Directly accessing byte 0: " << bytes[0] << std::endl; 
}


// ============================================================================
// PART 2: CLASSES, OBJECTS, & STRUCT DIFFERENCES
// ============================================================================

// Structure vs Class:
// The ONLY difference in C++ is default access control.
struct DemoStruct {
    int x; // Members are PUBLIC by default!
};

class Box {
    // Members are PRIVATE by default!
    double width;
    double height;

public:
    // Constructor
    Box(double w, double h) : width(w), height(h) {}

    // 4. Inline Function
    // Functions defined completely INSIDE a class declaration are implicitly inline.
    // The compiler replaces the call site with actual code to reduce function overhead.
    double getArea() { 
        return width * height; 
    }

    // Prototyping a function to be defined outside using Scope Resolution
    void printDimensions();
    
    // Friend declarations (Part 4)
    friend void doubleWidth(Box& b);
    friend class BoxInspector;
};

// 5. Scope Resolution Operator (::)
// Used here to define a class member function outside the class body definition.
void Box::printDimensions() {
    // 'width' and 'height' are accessible because this function belongs to Box
    std::cout << "Box: " << this->width << "x" << this->height << std::endl;
}


// ============================================================================
// PART 3: STATIC CLASS MEMBERS & OBJECT HANDLING
// ============================================================================

class Item {
private:
    int id;
public:
    // 6. Static Data Member 
    // Shared by ALL objects of this class. Only one instance exists in memory.
    // Must be declared inside the class and defined OUTSIDE.
    static int itemCount;

    Item(int i) : id(i) {
        itemCount++; // Every time an object is made, increment the shared counter
    }

    // 7. Static Member Function
    // Can be called using the class name directly without creating any object.
    // CRITICAL EXAM RULE: Static functions can ONLY access static data/functions. 
    // They do NOT have a 'this' pointer.
    static int getItemCount() {
        // return id; // ERROR! Cannot access non-static member 'id'
        return itemCount; 
    }
};

// MANDATORY EXAM STEP: Define and initialize static data member outside the class!
int Item::itemCount = 0;

// 8. Passing Objects to Functions
// Pass-by-value: Creates a copy using the copy constructor. Modifications are local.
void modifyByValue(Item tempItem) {
    // tempItem is a copy
}

// Pass-by-reference: Highly efficient, works directly on the original object.
void modifyByReference(Item& realItem) {
    // Edits here affect the original object
}

// 9. Returning Objects
Item createDefaultItem() {
    Item defaultObj(999);
    return defaultObj; // Returns a temporary object copy (optimized by modern compilers)
}


// ============================================================================
// PART 4: FRIEND FUNCTIONS & FRIEND CLASSES
// ============================================================================

// 10. Friend Function
// A non-member function granted full access to private/protected members of Box.
void doubleWidth(Box& b) {
    b.width *= 2; // Accessing private member 'width' directly!
}

// 11. Friend Class
// All member functions of BoxInspector can access private members of Box.
class BoxInspector {
public:
    void inspect(const Box& b) {
        // Accessing private members 'width' and 'height' directly
        std::cout << "Inspector reports area: " << b.width * b.height << std::endl;
    }
};


// ============================================================================
// MAIN FUNCTION (Execution)
// ============================================================================
int main() {
    std::cout << "=== ALL-NIGHTER SYLLABUS CODE ===" << std::endl << std::endl;

    // --- Enums & Tags ---
    SecurityLevel systemStatus = CRITICAL;
    if(systemStatus == 6) {
        std::cout << "Enums are fundamentally integers. Status is CRITICAL (6)." << std::endl;
    }

    // --- Anonymous Unions ---
    demonstrateAnonymousUnion();
    std::cout << std::endl;

    // --- Struct vs Class Default Access ---
    DemoStruct s;
    s.x = 10; // Completely valid! Public by default.
    
    Box myBox(5.0, 4.0);
    // myBox.width = 10.0; // COMPILER ERROR! Private by default.

    // --- Inline & Scope Resolution ---
    std::cout << "--- Inline & Scope Resolution ---" << std::endl;
    myBox.printDimensions();
    std::cout << "Area (via Inline Function): " << myBox.getArea() << std::endl << std::endl;

    // --- Static Class Members ---
    std::cout << "--- Static Members ---" << std::endl;
    Item a(10), b(20), c(30);
    // Calling static function using class scope name directly without an object
    std::cout << "Total items created: " << Item::getItemCount() << std::endl << std::endl;

    // --- 12. Object Assignment ---
    std::cout << "--- Object Assignment ---" << std::endl;
    Item source(100);
    Item target(200);
    
    target = source; // Object Assignment!
    // By default, C++ performs a bitwise (shallow) copy of data members from source to target.

    // --- Friends ---
    std::cout << "--- Friend Functions & Classes ---" << std::endl;
    BoxInspector inspector;
    inspector.inspect(myBox); // Before modifying
    
    doubleWidth(myBox); // Modifying private data using friend function
    std::cout << "After running friend function doubleWidth():" << std::endl;
    myBox.printDimensions();

    return 0;
}