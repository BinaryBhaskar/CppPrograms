// Write a program that would print the information (name, year of joining, salary, address) of three employees by creating a class named 'Employee'.

#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    int yearOfJoining;
    double salary;
    string address;

    Employee(string n, int y, double s, string a) {
        name = n;
        yearOfJoining = y;
        salary = s;
        address = a;
    }
};

int main() {
    Employee emp1("Alice", 2010, 50000, "123 Main St");
    Employee emp2("Bob", 2015, 60000, "456 Elm St");
    Employee emp3("Charlie", 2020, 55000, "789 Oak St");

    cout << "Employee 1: " << emp1.name << ", Year of Joining: " << emp1.yearOfJoining 
        << ", Salary: $" << emp1.salary << ", Address: " << emp1.address << endl;

    cout << "Employee 2: " << emp2.name << ", Year of Joining: " << emp2.yearOfJoining 
        << ", Salary: $" << emp2.salary << ", Address: " << emp2.address << endl;

    cout << "Employee 3: " << emp3.name << ", Year of Joining: " << emp3.yearOfJoining 
        << ", Salary: $" << emp3.salary << ", Address: " << emp3.address << endl;

    return 0;
}