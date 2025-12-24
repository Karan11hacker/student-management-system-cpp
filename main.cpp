#include<iostream>
#include<vector>
#include<string>

using namespace std;

class student{
    private:

    string name;
    int roll_no;
    int age;
    string course;

    public: 

    student(string n, int r, int a, string c){
        name= n;
        roll_no = r;
        age = a;
        course = c;
    }

    int getrollno(){
        return roll_no;
    }

    void display(){
        cout << "Roll Number: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
    }
};

void addStudent(vector<student> &students){
    int roll;
    int age;
    string name;
    string course;

    cout << "Enter Roll number of student: ";
    cin >> roll;
    cin.ignore();

    cout << "Enter name of student: ";
    getline(cin, name);

    cout << "Enter age of student: ";
    cin >> age;
    cin.ignore();

    cout << "Enter the course student is enrolled in: ";
    getline(cin, course);
    students.push_back(student(name,roll,age,course));

    cout << "\n----Student added successfully----\n";

}

void SearchStudent(vector<student> &students){
    int roll;
    cout << "Enter roll number of student: ";
    cin >> roll;

    for(auto &s : students){
        if(s.getrollno()==roll){
            cout << "Student found: \n";
            s.display();
            return;
        }
    }
    cout << "Student not found!!" << endl;
}

void displayAllStudents(vector<student> &students){
    if(students.empty()){
        cout << "-----No Student Record Found-----" << endl;
        return;
    }
    cout << "\n----Students Record----\n";
    for(auto &s: students){
        s.display();
    }
}

int main() {
    vector<student> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                SearchStudent(students);
                break;
            case 3:
                displayAllStudents(students);
                break;
            case 4:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}