// Create a structure data type with data items roll number, name, and total marks.Write main function to read data for two students and also display the stored data.

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    float totalMarks;
};

int main() {
    Student s1, s2;

    cout << "Enter roll number, name and total marks for student 1: ";
    cin >> s1.rollNumber >> s1.name >> s1.totalMarks;

    cout << "Enter roll number, name and total marks for student 2: ";
    cin >> s2.rollNumber >> s2.name >> s2.totalMarks;

    cout << "Student 1: " << s1.rollNumber << " " << s1.name << " " << s1.totalMarks << endl;
    cout << "Student 2: " << s2.rollNumber << " " << s2.name << " " << s2.totalMarks << endl;

    return 0;
}