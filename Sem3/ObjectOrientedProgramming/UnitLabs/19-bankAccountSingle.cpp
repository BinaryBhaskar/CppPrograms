// Define a class to represent a bank account. Include account management members (Single customer version).

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string customerName;
    double balance;

public:
    BankAccount(std::string accNum, std::string custName, double initialBalance) {
        accountNumber = accNum;
        customerName = custName;
        balance = initialBalance;
    }

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