// Practice Problem 02: Bank Account Security & Audit
// Concepts Tested: Encapsulation, Const Member Functions, Friend Functions, Scope Resolution.
//
// Description:
// Build a BankAccount class that securely manages user funds, and create a standalone audit function
// that can inspect account details without modifying them.
//
// Requirements:
// 1. Create a class named 'BankAccount'.
// 2. Private Data Members:
//    - std::string accountNumber
//    - std::string accountHolder
//    - double balance
// 3. Public Member Functions:
//    - Constructor accepting accountNumber, accountHolder, and initial balance (default initial balance = 0.0).
//    - void deposit(double amount): Adds amount to balance if amount > 0.
//    - bool withdraw(double amount): Subtracts amount if amount > 0 and balance >= amount. Returns true on success, false otherwise.
//    - double getBalance() const: Returns current balance.
// 4. Friend Function:
//    - Declare a friend function: friend void auditAccount(const BankAccount& acc);
//    - Outside the class, implement auditAccount(): Prints account number, holder, balance, and prints a warning flag if balance < $100.0.
// 5. In main():
//    - Create two accounts (e.g., Alice with $500, Bob with $50).
//    - Perform deposit and withdrawal operations.
//    - Call auditAccount() on both accounts to verify friend function access.

#include <iostream>
#include <string>

// TODO: Define your BankAccount class here

// TODO: Declare and implement friend function auditAccount()

int main() {
    // TODO: Write code to test BankAccount and auditAccount

    return 0;
}
