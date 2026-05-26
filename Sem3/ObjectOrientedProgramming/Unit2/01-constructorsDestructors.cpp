#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int* grades; // Pointer for dynamic memory tracking inside the class

public:
    // 1. Introduction & Default Constructor
    // Access Specifier Note: Placed in 'public' so instantiation is permitted outside the class.
    Student() {
        name = "Unknown";
        grades = new int[3]{0, 0, 0}; // Initializing allocated memory
        std::cout << "[Default Constructor] Object created with no explicit values." << std::endl;
    }

    // 2. Parameterized Constructor
    Student(std::string studentName) {
        name = studentName;
        grades = new int[3]{90, 85, 95};
        std::cout << "[Parameterized Constructor] Object created for: " << name << std::endl;
    }

    // 3. Multiple Constructors / Constructor with Default Arguments
    // This handles both (int) and (int, string) signatures due to the default argument value.
    Student(int performanceScore, std::string category = "General") {
        name = "Assigned (" + category + ")";
        grades = new int[3]{performanceScore, performanceScore, performanceScore};
        std::cout << "[Default Arg Constructor] Category initialized to: " << category << std::endl;
    }

    // 4. Copy Constructor (CRITICAL EXAM TOPIC)
    // Must pass source by reference (const Student& source) to avoid infinite layout recursion!
    Student(const Student& source) {
        this->name = source.name + " (Copied Instance)";
        
        // DEEP COPY MECHANISM:
        // Allocating completely unique memory space instead of copying the raw address pointer.
        this->grades = new int[3];
        for (int i = 0; i < 3; i++) {
            this->grades[i] = source.grades[i]; // Copying actual values over
        }
        std::cout << "[Copy Constructor] Deep copy completed successfully." << std::endl;
    }

    // 5. Destructor
    // Automatically invoked when object leaves its scope block or 'delete' is called.
    ~Student() {
        delete[] grades; // Clean up the allocated heap array inside the object to avoid memory leaks
        std::cout << "[Destructor] Memory cleared out for " << name << "." << std::endl;
    }

    void showData() {
        std::cout << "Student Profile: " << name << " -> Grade 1: " << grades[0] << std::endl;
    }
};

int main() {
    std::cout << "=== TOPIC: CONSTRUCTORS & DESTRUCTORS ===" << std::endl;

    // Instantiation variations
    Student s1;                  // Default
    Student s2("Naina");         // Parameterized
    Student s3(92);              // Using default parameter rule ("General")
    
    std::cout << "\n--- Triggering Copy Constructor ---" << std::endl;
    Student s4 = s2;             // Invokes Copy Constructor
    
    s2.showData();
    s4.showData();

    std::cout << "\n--- Stack Cleanup Approaching ---" << std::endl;
    return 0;
}