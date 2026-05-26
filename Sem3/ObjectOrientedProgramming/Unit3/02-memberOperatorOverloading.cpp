#include <iostream>

class Score {
private:
    int points;

public:
    Score(int p) : points(p) {}

    void display() const {
        std::cout << "Score Points: " << points << std::endl;
    }

    // 1. Overloading Shorthand Assignment Operations (+=)
    // Always return a reference to the current object (*this) to allow chaining.
    Score& operator+=(const Score& rhs) {
        this->points += rhs.points;
        return *this; 
    }

    // 2. Prefix Increment (++obj)
    // No parameters. Increments the object state first, then returns a reference to itself.
    Score& operator++() {
        this->points++;
        return *this;
    }

    // 3. Postfix Increment (obj++)
    // CRITICAL EXAM SYNTAX: Takes a dummy "int" parameter to distinguish it from prefix!
    // Creates a temporary copy, increments the original object, then returns the untouched old copy by value.
    Score operator++(int) {
        Score temp = *this; // Keep a backup copy of current state
        this->points++;     // Increment original object state
        return temp;        // Return the copy from before the increment happened
    }
};

int main() {
    std::cout << "=== TOPIC: MEMBER OPERATOR OVERLOADING ===" << std::endl;

    Score teamA(10);
    Score teamB(5);

    // Testing shorthand operation
    teamA += teamB; 
    std::cout << "After += operation: ";
    teamA.display();

    // Testing Prefix vs Postfix
    std::cout << "\n--- Increment Testing ---" << std::endl;
    Score s1(100);
    
    Score s2 = ++s1; // s1 becomes 101, s2 receives 101
    std::cout << "Prefix outcomes -> ";
    s1.display(); s2.display();

    Score s3 = s1++; // s1 becomes 102, s3 receives old s1 (101)
    std::cout << "Postfix outcomes -> ";
    s1.display(); s3.display();

    /* 4. OPERATOR OVERLOADING RESTRICTIONS (GUARANTEED EXAM QUESTION)
    The following operators CANNOT be overloaded:
    - Scope Resolution Operator (::)
    - Sizeof Operator (sizeof)
    - Member Selector Operator (.)
    - Member Pointer Selector Operator (.*)
    - Ternary Conditional Operator (?:)
    
    Other Restrictions:
    - You cannot alter operator precedence or associativity.
    - You cannot create completely new operators (like overloading ** for exponentiation).
    - At least one operand must be a user-defined type (you can't redefine how 2 + 2 works for built-in ints).
    */

    return 0;
}