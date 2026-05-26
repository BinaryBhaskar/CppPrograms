----
# 1. Overview of C++ & OOP Concepts

### Core
- **Class**: A blueprint or template for creating objects. It defines data and methods.
- **Object**: An instance of a class.
- **Encapsulation**: Wrapping data (variables) and code (functions) together as a single unit to protect data from outside interference.
- **Data Hiding**: Restricting access to internal data components using access specifiers (private, protected).
- **Abstraction**: Hiding complex implementation details and showing only the essential features.
- **Inheritance**: The capability of a class to derive properties and characteristics from another class (promotes reusability).
- **Polymorphism**: The ability of a message or function to be displayed in more than one form (e.g., function overloading, virtual functions).

### Advantages & Usage
- **Advantages**: Efficient memory management, high performance, code reusability (via inheritance), and better software maintainability.
- **Usage**: System software, game engines (like Unreal Engine), browsers, GUI-based applications, and financial trading platforms.

----
# 2. C++ Environment & Standards
To run a C++ program, it goes through a specific development environment cycle:
- Editor: Writing the source code (.cpp).
- Preprocessor: Handles directives starting with # (like #include).
- Compiler: Translates source code into object code (.obj or .o).
- Linker: Combines object code with standard library functions to create an executable (.exe).

### Compilers & Libraries
- **Compilers**: GCC (GNU Compiler Collection), Clang, MSVC (Microsoft Visual C++).
- **Standards**: C++ has evolved through standards managed by ISO: C++98, C++11 (modern C++), C++14, C++17, C++20, and C++23.
- **C++ Standard Libraries**: Provides built-in capabilities like iostream (input/output), vector, string, and the STL (Standard Template Library) which provides ready-made data structures.

# 3. C++ as a Superset of C (Enhancements)
- C++ includes everything C does, but adds powerful quality-of-life and architectural upgrades.
- New Style Comments: C only used /* block */. C++ introduced // single-line comments.
- Data Types: C++ introduced native bool (true/false) and string types, alongside standard primitives (int, char, float, double).
- Function Prototyping: Enforced strictly in C++. You must declare a function's signature before using it so the compiler can check types.
- Meaning of Empty Argument List: * In C, void func() means a function can take any number of arguments.
- In C++, void func() strictly means it takes zero arguments (identical to void func(void)).

## Zero Arguments
``` c
// If this is compiled in C:

void printMessage(); // Means: "I can accept any arguments you throw at me."
printMessage(5, "hello", 3.14); // Valid in C!
```

``` cpp
// If this is compiled in C++:
void printMessage(); // Means: "I accept absolutely nothing."
printMessage(5); // COMPILATION ERROR in C++!
```

## Function Prototyping
A prototype is a declaration of a function that tells the compiler about the function’s name, return type, and its parameter list before it is actually called or fully defined.

### Why is it needed?
C++ uses a single-pass compiler, meaning it reads your file from top to bottom. If you call a function before defining it, the compiler will panic because it doesn't know what types to validate.
```C++
#include <iostream>

// 1. FUNCTION PROTOTYPE (Declaration)
int add(int a, int b); 

int main() {
    // 2. FUNCTION CALL
    // The compiler allows this because the prototype promised 'add' exists and takes two ints.
    int sum = add(5, 10); 
    std::cout << sum;
    return 0;
}

// 3. FUNCTION DEFINITION
int add(int a, int b) { 
    return a + b;
}
```

## Default Arguments
C++ allows you to assign a default value to a function parameter in its declaration. If the caller does not provide a value for that parameter, the default value kicks in.

The Crucial Rules
- Right-to-Left Rule: You must assign default values from right to left. You cannot give a default value to a parameter unless all parameters to its right also have default values.
- Declaration Only: Default values should only be specified in the prototype/declaration, not in the definition.

Syntax Check
```C++
// VALID
void setVolume(int length, int width = 10, int height = 20); 

// INVALID (Compiler error! What happens if you only pass one argument?)
void setVolume(int length = 5, int width, int height = 20); 

int main() {
    setVolume(5);        // length = 5, width = 10 (default), height = 20 (default)
    setVolume(5, 15);    // length = 5, width = 15,            height = 20 (default)
    setVolume(5, 15, 25);// length = 5, width = 15,            height = 25
}
```

## Argument Matching (Function Overloading Resolution)
When you have multiple functions with the same name but different parameters (Function Overloading), how does the compiler choose which one to run? It follows a strict internal checklist to find the best match.

The 4-Step Resolution Hierarchy
- Exact Match: The compiler looks for a function where the argument types perfectly match the parameter types without changing anything.
- Promotion: If no exact match is found, the compiler attempts to upgrade smaller types to larger internal types.
    - char, unsigned char, short → promoted to int
    - float → promoted to double
- Standard Conversion: If promotion fails, it tries standard structural conversions.
    - int → converted to float or double
    - double → converted to long double
- User-Defined Conversion: Looking at class constructors or conversion operators (we'll see this later).
- The Danger: Ambiguity Error
If the compiler finds two matching functions at the same hierarchy level, it gives up and throws an Ambiguity Error.

```C++
#include <iostream>

void printValue(int x) { std::cout << "Integer: " << x << "\n"; }
void printValue(double x) { std::cout << "Double: " << x << "\n"; }

int main() {
    float num = 5.5f;
    
    // AMBIGUITY ERROR! 
    // A 'float' can be converted to an 'int' OR a 'double' via Standard Conversion.
    // Both choices are at Step 3. The compiler does not know which to pick.
    printValue(num); 
}
```