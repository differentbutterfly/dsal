#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class student {
public:
    int roll;
    char name[20], div[5], address[50];
};

void addStudent() {
    student s;
    ofstream fout("student.txt", ios::app);

    cout << "Enter the roll.no: ";
    cin >> s.roll;
    cin.ignore();

    cout << "Enter student name: ";
    cin.getline(s.name, 20);

    cout << "Enter student division: ";
    cin.getline(s.div, 5);

    cout << "Enter student address: ";
    cin.getline(s.address, 50);

    // Removed extra spaces and consistent format for reading back
    fout << s.roll << "\n" << s.name << "\n" << s.div << "\n" << s.address << "\n";
    fout.close();
}

void displayStudentByRollNo(int roll) {
    student s;
    ifstream fin("student.txt");
    bool found = false;

    while (fin >> s.roll) {
        fin.ignore();
        fin.getline(s.name, 20);
        fin.getline(s.div, 5);
        fin.getline(s.address, 50);

        if (s.roll == roll) {
            cout << "\nRoll No: " << s.roll
                 << "\nName: " << s.name
                 << "\nDivision: " << s.div
                 << "\nAddress: " << s.address << endl;
            found = true;
            break;
        }
    }
    fin.close();
    if (!found)
        cout << "Student not found.\n";
}

void displayAllStudent() {
    student s;
    ifstream fin("student.txt");
    bool found = false;

    while (fin >> s.roll) {
        fin.ignore();
        fin.getline(s.name, 20);
        fin.getline(s.div, 5);
        fin.getline(s.address, 50);

        cout << "\nRoll No: " << s.roll
             << "\nName: " << s.name
             << "\nDivision: " << s.div
             << "\nAddress: " << s.address << endl;
        found = true;
    }

    fin.close();
    if (!found)
        cout << "No student records found.\n";
}

void deleteStudentByRoll(int rollNo) {
    student s;
    ifstream fin("student.txt");
    ofstream fout("temp.txt");
    bool deleted = false;

    while (fin >> s.roll) {
        fin.ignore();
        fin.getline(s.name, 20);
        fin.getline(s.div, 5);
        fin.getline(s.address, 50);

        if (s.roll != rollNo) {
            fout << s.roll << "\n" << s.name << "\n" << s.div << "\n" << s.address << "\n";
        } else {
            deleted = true;
        }
    }

    fin.close();
    fout.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (deleted)
        cout << "Student record deleted.\n";
    else
        cout << "Student does not exist.\n";
}

int main() {
    int ch, rollNo;

    do {
        cout << "\nMenu:\n"
             << "0. Exit\n"
             << "1. Add Student\n"
             << "2. Display Student by Roll No\n"
             << "3. Display All Students\n"
             << "4. Delete Student\n"
             << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 0:
                cout << "Exiting...\n";
                break;
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter roll number to search: ";
                cin >> rollNo;
                displayStudentByRollNo(rollNo);
                break;
            case 3:
                displayAllStudent();
                break;
            case 4:
                cout << "Enter roll number to delete: ";
                cin >> rollNo;
                deleteStudentByRoll(rollNo);
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (ch != 0);

    return 0;
}
