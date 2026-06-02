// Define a class to represent a bank account (FOR 100 CUSTOMERS).

#include <iostream>
#include <string>
class BankAccount {
private:
    std::string accountNumber;
    std::string customerName;
    double balance;
public:
    BankAccount(std::string accNum, std::string custName, double initialBalance)
        : accountNumber(accNum), customerName(custName), balance(initialBalance) {}
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }
    double getBalance() const {
        return balance;
    }
    void displayAccountInfo() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Customer Name: " << customerName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

int main() {
    const int MAX_CUSTOMERS = 100;
    BankAccount* accounts[MAX_CUSTOMERS];

    // Create accounts for 100 customers
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        std::string accNum = "ACC" + std::to_string(i + 1);
        std::string custName = "Customer" + std::to_string(i + 1);
        double initialBalance = 1000.0; // Initial balance for each account
        accounts[i] = new BankAccount(accNum, custName, initialBalance);
    }

    // Display account information for all customers
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        accounts[i]->displayAccountInfo();
        std::cout << "-------------------------" << std::endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        delete accounts[i];
    }

    return 0;
}