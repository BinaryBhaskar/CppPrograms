// Write a Program to Concatenate two Strings Using Operator Overloading(+).

#include <iostream>
#include <cstring>

class MyString {
private:
    char str[100];
public:
    MyString(const char* s = "") {
        strncpy(str, s, sizeof(str) - 1);
        str[sizeof(str) - 1] = '\0'; // Ensure null-termination
    }
    MyString operator+(const MyString& other) const {
        MyString result;
        strncpy(result.str, str, sizeof(result.str) - 1);
        strncat(result.str, other.str, sizeof(result.str) - strlen(result.str) - 1);
        return result;
    }
    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString str1("Hello, ");
    MyString str2("World!");

    MyString str3 = str1 + str2; // Concatenate str1 and str2 using overloaded + operator

    std::cout << "Concatenated String: ";
    str3.display(); // Display the concatenated string

    return 0;
}