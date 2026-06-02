// Write a program to show the highest scorer in a test out of three students who appeared in an exam. Use this pointer to refer to objects. (USER INPUT)

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
        std::cout << "Name: " << name << ", Score: " << score <<
        std::endl;
    }
};

int main() {
    Student students[3] = {
        Student("", 0.0),
        Student("", 0.0),
        Student("", 0.0)
    };

    // Get user input for student names and scores
    for (int i = 0; i < 3; ++i) {
        std::string name;
        double score;

        std::cout << "Enter name of student " << (i + 1) << ": ";
        std::getline(std::cin, name);
        std::cout << "Enter score of student " << (i + 1) << ": ";
        std::cin >> score;
        std::cin.ignore(); // Clear the newline character from the input buffer

        students[i] = Student(name, score);
    }

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