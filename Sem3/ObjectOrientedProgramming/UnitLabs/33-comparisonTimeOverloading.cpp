// Write a program to overload <=, >= and == operator to compare time objects.

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
    bool operator==(const Time& other) const {
        return (hours == other.hours) && (minutes == other.minutes);
    }
    bool operator<=(const Time& other) const {
        if (hours < other.hours) {
            return true;
        } else if (hours == other.hours) {
            return minutes <= other.minutes;
        } else {
            return false;
        }
    }
    bool operator>=(const Time& other) const {
        if (hours > other.hours) {
            return true;
        } else if (hours == other.hours) {
            return minutes >= other.minutes;
        } else {
            return false;
        }
    }
    void display() const {
        std::cout << hours << " hours and " << minutes << " minutes" << std::endl;
    }
};

int main() {
    Time time1(2, 30); // 2 hours and 30 minutes
    Time time2(3, 15); // 3 hours and 15 minutes
    Time time3(2, 30); // 2 hours and 30 minutes

    std::cout << "Time 1: ";
    time1.display();
    std::cout << "Time 2: ";
    time2.display();
    std::cout << "Time 3: ";
    time3.display();

    if (time1 == time3) {
        std::cout << "Time 1 is equal to Time 3." << std::endl;
    } else {
        std::cout << "Time 1 is not equal to Time 3." << std::endl;
    }

    if (time1 <= time2) {
        std::cout << "Time 1 is less than or equal to Time 2." << std::endl;
    } else {
        std::cout << "Time 1 is greater than Time 2." << std::endl;
    }

    if (time2 >= time1) {
        std::cout << "Time 2 is greater than or equal to Time 1." << std::endl;
    } else {
        std::cout << "Time 2 is less than Time 1." << std::endl;
    }

    return 0;
}