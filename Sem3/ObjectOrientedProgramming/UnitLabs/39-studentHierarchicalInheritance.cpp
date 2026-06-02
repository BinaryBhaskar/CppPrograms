// Define a class Student with data members as rollno and name. Derive classes Fees and Result to demonstrate Hierarchical Inheritance.

#include <iostream>
#include <string>

class Student {
protected:
    int rollno;
    std::string name;
public:
    Student(int r, std::string n) : rollno(r), name(n) {}
    void displayStudentInfo() const {
        std::cout << "Roll No: " << rollno << ", Name: " << name << std::endl;
    }
};

class Fees : public Student {
private:
    double feeAmount;
public:
    Fees(int r, std::string n, double fee) : Student(r, n),
        feeAmount(fee) {}
    void displayFees() const {
        displayStudentInfo();
        std::cout << "Fee Amount: $" << feeAmount << std::endl;
    }
};

class Result : public Student {
private:
    double marks;
public:
    Result(int r, std::string n, double m) : Student(r, n), marks(m) {}
    void displayResult() const {
        displayStudentInfo();
        std::cout << "Marks: " << marks << std::endl;
    }
};

int main() {
    Fees student1(101, "Alice", 1500.0);
    Result student2(102, "Bob", 85.5);

    std::cout << "Student 1 (Fees):" << std::endl;
    student1.displayFees();

    std::cout << "\nStudent 2 (Result):" << std::endl;
    student2.displayResult();

    return 0;
}