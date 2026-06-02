// Write a program to show the highest scorer in a test out of three students who appeared in an exam. Use this pointer to refer to objects.

#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    double score;
public:
    Student(std::string n, double s) : name(n), score(s) {}
    std::string getName() const {
        return name;
    }
    double getScore() const {
        return score;
    }
    void display() const {
        std::cout << "Name: " << name << ", Score: " << score << std::endl;
    }
};

int main() {
    Student students[3] = {
        Student("Alice", 85.5),
        Student("Bob", 92.0),
        Student("Charlie", 88.0)
    };

    Student* highestScorer = &students[0]; // Initialize with the first student

    for (int i = 1; i < 3; ++i) {
        if (students[i].getScore() > highestScorer->getScore()) {
            highestScorer = &students[i]; // Update highest scorer
        }
    }

    std::cout << "Highest Scorer: " << std::endl;
    highestScorer->display();

    return 0;
}