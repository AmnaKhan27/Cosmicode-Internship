#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string course;
    int year;

public:
   
    Student(string n, int roll, string c, int y) 
        : name(n), rollNumber(roll), course(c), year(y) {}

    void display() const {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Year: " << year << endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
  
    void addStudent() {
        string name, course;
        int roll, year;

        cout << "\nEnter student details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Roll Number: ";
        cin >> roll;
        cout << "Course: ";
        cin.ignore();
        getline(cin, course);
        cout << "Year: ";
        cin >> year;

        students.emplace_back(name, roll, course, year);
        cout << "Student added successfully!" << endl;
    }

    void deleteStudent() {
        if (students.empty()) {
            cout << "No students to delete!" << endl;
            return;
        }

        int roll;
        cout << "Enter roll number of student to delete: ";
        cin >> roll;

        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNumber() == roll) {
                students.erase(it);
                cout << "Student deleted successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << roll << " not found!" << endl;
        }
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students to display!" << endl;
            return;
        }

        cout << "\nAll Students:" << endl;
        for (const auto& student : students) {
            student.display();
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.deleteStudent();
                break;
            case 3:
                sms.displayAllStudents();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}