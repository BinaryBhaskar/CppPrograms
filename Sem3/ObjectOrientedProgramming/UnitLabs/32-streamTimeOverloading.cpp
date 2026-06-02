// Write a program to overload << and >> operators to display time object.

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        normalize();
    }
    void normalize() {
        hours += minutes / 60;
        minutes %= 60;
        if (hours < 0) {
            hours = 0;
            minutes = 0;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
    friend std::istream& operator>>(std::istream& is, Time& t);
};

std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.hours << " hours and " << t.minutes << " minutes";
    return os;
}

std::istream& operator>>(std::istream& is, Time& t) {
    std::cout << "Enter hours: ";
    is >> t.hours;
    std::cout << "Enter minutes: ";
    is >> t.minutes;
    t.normalize();
    return is;
}

int main() {
    Time time1;
    std::cin >> time1; // Input time using overloaded >> operator
    std::cout << "You entered: " << time1 << std::endl; // Output time using overloaded << operator

    return 0;
}