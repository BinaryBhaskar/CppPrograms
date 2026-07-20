// Practice Problem 15: Binary File I/O Student Database
// Concepts Tested: Binary File Operations (std::ios::binary, write, read), reinterpret_cast, Random Access (seekg, seekp).
//
// Description:
// Build a simple student record database storing fixed-size records directly to a binary file `students.dat`.
//
// Requirements:
// 1. Structure 'StudentRecord':
//    - int id
//    - char name[50]
//    - double gpa
// 2. Class 'StudentDatabase':
//    - Private Member: std::string filename
// 3. Public Functions:
//    - StudentDatabase(std::string file = "students.dat")
//    - void addStudent(const StudentRecord& rec):
//      Opens file in `std::ios::binary | std::ios::app`, writes binary record using `file.write(reinterpret_cast<const char*>(&rec), sizeof(rec))`.
//    - void displayAll() const:
//      Opens file in `std::ios::binary | std::ios::in`, reads records sequentially using `file.read(...)` in a loop until EOF.
//    - bool searchStudent(int searchID, StudentRecord& outRecord) const:
//      Searches binary file record by record. Returns true if found and populates `outRecord`.
// 4. In main():
//    - Create three `StudentRecord` objects (e.g. ID 101, 102, 103).
//    - Add records to binary file.
//    - Display all records read from binary file.
//    - Perform a search for ID 102 and display the result.

#include <iostream>
#include <fstream>
#include <cstring>

// TODO: Define StudentRecord and StudentDatabase here

int main() {
    // TODO: Test binary file I/O operations

    return 0;
}
