// Create a class time to store time in hours and minutes. Use objects as arguments to sum() function and object return type from sum() function.

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
    Time sum(const Time& t) const {
        Time result;
        result.hours = hours + t.hours;
        result.minutes = minutes + t.minutes;
        result.normalize();
        return result;
    }
    void display() const {
        std::cout << hours << " hours and " << minutes << " minutes" << std::endl;
    }
};

int main() {
    Time time1(2, 45); // 2 hours and 45 minutes
    Time time2(1, 30); // 1 hour and 30 minutes

    Time totalTime = time1.sum(time2);
    std::cout << "Total Time: ";
    totalTime.display();

    return 0;
}