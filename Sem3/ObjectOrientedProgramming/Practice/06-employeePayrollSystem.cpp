// Practice Problem 06: Employee Payroll & Multiple Inheritance
// Concepts Tested: Multiple Inheritance, Diamond Problem / Virtual Base Class, Ambiguity Resolution.
//
// Description:
// Build a TechManager class that combines capabilities from two distinct base classes: `TechnicalStaff` and `ManagerialStaff`.
//
// Requirements:
// 1. Base Class 'Person':
//    - Members: std::string name, int id.
//    - Constructor initializing name and id.
//    - Function: void showIdentity() const.
// 2. Class 'TechnicalStaff' (inherits virtually from Person):
//    - Members: std::string primaryLanguage.
//    - Constructor passing name & id to Person base.
//    - Function: void showTechnicalSkills() const.
// 3. Class 'ManagerialStaff' (inherits virtually from Person):
//    - Members: int teamSize.
//    - Constructor passing name & id to Person base.
//    - Function: void showManagementSkills() const.
// 4. Derived Class 'TechManager' (inherits publicly from both TechnicalStaff and ManagerialStaff):
//    - Constructor initializing name, id, primaryLanguage, and teamSize.
//    - Function: void showFullProfile() const (Calls showIdentity(), showTechnicalSkills(), and showManagementSkills()).
// 5. Note on Virtual Base Class:
//    - Use `virtual public Person` in TechnicalStaff and ManagerialStaff so TechManager inherits only ONE copy of Person!
// 6. In main():
//    - Instantiate a TechManager object.
//    - Call showFullProfile().
//    - Call showIdentity() directly from TechManager instance without resolution ambiguity.

#include <iostream>
#include <string>

// TODO: Define Person, TechnicalStaff, ManagerialStaff, and TechManager classes here

int main() {
    // TODO: Test multiple and virtual inheritance logic

    return 0;
}
