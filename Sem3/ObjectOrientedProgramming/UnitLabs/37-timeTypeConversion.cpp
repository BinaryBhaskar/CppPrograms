// Write a program to convert time type object to an Integer value and integer type value to object of time type.

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
    operator int() const {
        return hours * 60 + minutes; // Convert time to total minutes
    }
    Time operator=(int totalMinutes) {
        hours = totalMinutes / 60;
        minutes = totalMinutes % 60;
        return *this; // Return the current object
    }
    void display() const {
        std::cout << hours << " hours and " << minutes << " minutes" << std::endl;
    }
};

int main() {
    Time time1(2, 30); // 2 hours and 30 minutes
    std::cout << "Time 1: ";
    time1.display();

    int totalMinutes = time1; // Convert Time object to integer (total minutes)
    std::cout << "Total Minutes: " << totalMinutes << std::endl;

    Time time2;
    time2 = totalMinutes; // Convert integer back to Time object
    std::cout << "Time 2 (converted from total minutes): ";
    time2.display();

    return 0;
}