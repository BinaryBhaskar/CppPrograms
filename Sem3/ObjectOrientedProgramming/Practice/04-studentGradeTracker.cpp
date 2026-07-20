// Practice Problem 04: Student Grade Tracker
// Concepts Tested: Array of Objects, Static Data Members, Static Member Functions, Data Aggregation.
//
// Description:
// Create a Student class to track academic marks for multiple students using static data members to track
// class-wide statistics across all instantiated objects.
//
// Requirements:
// 1. Create a class named 'Student'.
// 2. Private Members:
//    - int rollNo
//    - std::string name
//    - double marks[3] (array of 3 subject marks)
// 3. Static Members:
//    - private static int totalStudents (tracks number of active Student instances)
//    - private static double classTotalMarksSum (tracks sum of all student average marks)
// 4. Public Functions:
//    - Student(int r, std::string n, double m1, double m2, double m3)
//    - ~Student() -> Decrements totalStudents.
//    - double getAverage() const -> Returns average of the 3 subject marks.
//    - void display() const -> Prints student roll number, name, and average marks.
//    - static int getTotalStudents() -> Returns total count of students currently created.
//    - static double getClassAverage() -> Returns overall average score across all created students.
// 5. In main():
//    - Remember to initialize static members outside the class definition!
//    - Create an array of 3 Student objects.
//    - Iterate through the array to display individual student averages.
//    - Call static functions to display the class total student count and overall class average.

#include <iostream>
#include <string>

// TODO: Define your Student class here

int main() {
    // TODO: Implement student grade tracking tests

    return 0;
}
