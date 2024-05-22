#include <iostream>
#include <string>
#include <map>

using namespace std;

// Структура для представлення оцінок студента
struct Grades {
    int grade1;
    int grade2;
    int grade3;
};

// Прототипи функцій
void addStudent(map<string, Grades>& group);
void displayStudents(const map<string, Grades>& group);

int main() {
    map<string, Grades> studentGroup;

    char choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            addStudent(studentGroup);
            break;
        case '2':
            displayStudents(studentGroup);
            break;
        case '3':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != '3');

    return 0;
}

// Підпрограма для додавання студента до колекції
void addStudent(map<string, Grades>& group) {
    string lastName;
    cout << "Enter student's last name: ";
    cin >> lastName;

    int grade1, grade2, grade3;
    do {
        cout << "Enter student's grades (3 grades separated by spaces): ";
        cin >> grade1 >> grade2 >> grade3;
        if (grade1 < 0 || grade1 > 100 || grade2 < 0 || grade2 > 100 || grade3 < 0 || grade3 > 100) {
            cout << "Invalid input! Please enter again." << endl;
        }
    } while (grade1 < 0 || grade1 > 100 || grade2 < 0 || grade2 > 100 || grade3 < 0 || grade3 > 100);

    group[lastName] = { grade1, grade2, grade3 };
}

// Підпрограма для виведення інформації про всіх студентів у колекції
void displayStudents(const map<string, Grades>& group) {
    cout << "List of students:" << endl;
    for (const auto& pair : group) {
        const string& lastName = pair.first;
        const Grades& grades = pair.second;
        cout << "Last Name: " << lastName << ", Grades: " << grades.grade1 << " "
            << grades.grade2 << " " << grades.grade3 << endl;
    }
}
