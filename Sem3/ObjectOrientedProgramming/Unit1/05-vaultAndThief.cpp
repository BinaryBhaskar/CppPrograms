// The Vault and The Thief
// Concepts Tested: Classes (Private Access), Inline Functions, Friend Functions, Friend Classes.
// Create a security simulation program.
// Requirements:
// Create a class named BankVault.
// It must have private data members: int cashAmount and std::string masterPassword.
// Provide an inline function inside the class called isEmpty() that returns true if cashAmount is 0.
// Create a standalone global friend function named fleeceVault(BankVault &v) that directly sets the private cashAmount to 0 without using a public setter.
// Create a friend class named FBIInspector. Give it a member function audit(const BankVault &v) that prints the secret password and total cash directly to the screen.
// Test the whole flow in main() by initializing a vault, letting the FBI inspect it, running the rogue friend function to rob it, and checking if it's empty using the inline function.

#include <iostream>

class BankVault {
    int cashAmount;
    std::string masterPassword;

public:
    BankVault(int money, std::string pwd): cashAmount(money), masterPassword(pwd) {}

    bool isEmpty() {
        return cashAmount == 0;
    }

    friend void fleeceVault(BankVault& v);
    friend class FBIInspector;
};

void fleeceVault(BankVault& v) {
    v.cashAmount = 0;
};

class FBIInspector {
public: 
    void audit(const BankVault &v) {
        std::cout << "Password: " << v.masterPassword << ", Amount: " << v.cashAmount << std::endl;
    }
};

int main() {
    BankVault vault(5000, "GGV");
    FBIInspector inspector;

    inspector.audit(vault);

    fleeceVault(vault);
    inspector.audit(vault);

    return 0;
}