// Create a class named 'Student' with a string variable 'name' and an integer variable 'roll no'. Assign the value of roll no as '2' and that of name as 'John' by creating an object of the class Student.

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
};

int main() {
    Student s;
    s.name = "John";
    s.rollNo = 2;

    cout << "Student name: " << s.name << endl;
    cout << "Student roll number: " << s.rollNo << endl;

    return 0;
}
