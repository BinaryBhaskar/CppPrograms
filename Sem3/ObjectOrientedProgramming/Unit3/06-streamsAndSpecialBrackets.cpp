// The Safe String Safe
// Concepts: Stream Insertion (<<) via Friend Functions, Subscript Operator [], Functor () Execution.
// Task: Create a class named StringSafe that acts as a secure, printable collection of characters.
// Requirements:
// It should have a private character array char secret[4] and an integer size. Initialize it in a constructor with a 4-character string like "GOLD".
// Overload the Subscript Operator [] as a member function. It must return a reference (char&) so you can overwrite individual letters (e.g., safe[1] = 'A';).
// Overload the Function Call Operator () to act as a functor. When called with an integer key like safe(1234), it prints "[ACCESS GRANTED] Vault decrypted." if the key is correct.
// Overload the Stream Insertion Operator (<<) as a non-member friend function so you can print the entire object content directly via std::cout << safe << std::endl;.
// In your code comments, write a brief explanation detailing exactly why you were forced to make the << operator a global friend function instead of a regular class member function.

#include <iostream>
#include <string>
#include <cstring>

class StringSafe {
    char secret[4];
    int size;

public:
    StringSafe(char pwd[4]) {
        strcpy(secret, pwd);
        this->size = 4;
    }

    char& operator[](int index) {
        return secret[index];
    }

    void operator()(int code) {
        if (code == 1234) {
            std::cout << "[ACCESS GRANTED] Vault decrypted." << std::endl;
        } else {
            std::cout << "[ACCESS DENIED] Vault is ecrypted." << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const StringSafe& safe);
};

std::ostream& operator<<(std::ostream& out, const StringSafe& safe) {
    out << "Secret: " << safe.secret << ", Size: " << safe.size;
    return out;
};

int main() {
    StringSafe safe("BUG");

    std::cout << safe[0] << std::endl;
    safe(1123);
    safe(1234);
    std::cout << safe << std::endl;

    return 0;
}