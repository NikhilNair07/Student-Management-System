#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 25;

struct Student {
    int id;
    float marks, per;
    string name, grade;
} s[MAX_STUDENTS];

int studentCount = 0;

void insert() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\n\n *** Maximum number of students reached. Cannot insert more. ***";
        return;
    }

    cout << "\n\n\t\t\t *** Insert Record ***";
    cout << "\n\n Enter Student Id: ";
    cin >> s[studentCount].id;
    cout << "\n\n Enter Student Name: ";
    cin >> s[studentCount].name;
    cout << "\n\n Enter Student Marks: ";
    cin >> s[studentCount].marks;
    s[studentCount].per = (s[studentCount].marks / 100) * 100; // Calculate percentage
    if (s[studentCount].per >= 85) {
        s[studentCount].grade = "A+";
    } else if (s[studentCount].per >= 75) {
        s[studentCount].grade = "A";
    } else if (s[studentCount].per >= 65) {
        s[studentCount].grade = "B+";
    } else if (s[studentCount].per >= 55) {
        s[studentCount].grade = "B";
    } else if (s[studentCount].per >= 50) {
        s[studentCount].grade = "C";
    } else if (s[studentCount].per >= 45) {
        s[studentCount].grade = "D";
    } else if (s[studentCount].per >= 33) {
        s[studentCount].grade = "E";
    } else {
        s[studentCount].grade = "F";
    }
    studentCount++;
    cout << "\n\n *** Record Inserted Successfully ***";
}

void search() {
    cout << "\n\n\t\t\t *** Search Record ***";
    if (studentCount == 0) {
        cout << "\n\n *** No Record Found ***";
    } else {
        int id, found = 0; 
        cout << "\nEnter Student Id: ";
        cin >> id;
        for (int a = 0; a < studentCount; a++) {
            if (id == s[a].id) {
                cout << "\n\n Student Name: " << s[a].name;
                cout << "\n\n Student Marks: " << s[a].marks;
                cout << "\n\n Student Percentage: " << s[a].per;
                cout << "\n\n Student Grade: " << s[a].grade;
                found++;
            }
        }
        if (found == 0) {
            cout << "\n\n *** Student Id Not Found ***";
        }
    }
}

void update() {
    cout << "\n\n\t\t\t *** Update Record ***";
    if (studentCount == 0) {
        cout << "\n\n *** No Record Found ***";
    } else {
        int id, found = 0;
        cout << "\nEnter Student Id: ";
        cin >> id;
        for (int a = 0; a < studentCount; a++) {
            if (id == s[a].id) {
                cout << "\n\n Enter New Student Name: ";
                cin >> s[a].name;
                cout << "\n\n Enter New Student Marks: ";
                cin >> s[a].marks;
                s[a].per = (s[a].marks / 100) * 100; // Calculate percentage again
                if (s[a].per >= 85) {
                    s[a].grade = "A+";
                } else if (s[a].per >= 75) {
                    s[a].grade = "A";
                } else if (s[a].per >= 65) {
                    s[a].grade = "B+";
                } else if (s[a].per >= 55) {
                    s[a].grade = "B";
                } else if (s[a].per >= 50) {
                    s[a].grade = "C";
                } else if (s[a].per >= 45) {
                    s[a].grade = "D";
                } else if (s[a].per >= 33) {
                    s[a].grade = "E";
                } else {
                    s[a].grade = "F";
                }
                cout << "\n\n *** Record Updated Successfully ***";
                found++;
            }
        }
        if (found == 0) {
            cout << "\n\n *** Student Id Not Found ***";
        }
    }
}

void deleteRecord() {
    cout << "\n\n\t\t\t *** Delete Record ***";
    if (studentCount == 0) {
        cout << "\n\n *** No Record Found ***";
    } else {
        int id, found = 0;
        cout << "\nEnter Student Id: ";
        cin >> id;
        for (int a = 0; a < studentCount; a++) {
            if (id == s[a].id) {
                for (int j = a; j < studentCount - 1; j++) {
                    s[j] = s[j + 1];
                }
                studentCount--;
                cout << "\n\n *** Record Deleted Successfully ***";
                found++;
            }
        }
        if (found == 0) {
            cout << "\n\n *** Student Id Not Found ***";
        }
    }
}

void showRecords() {
    cout << "\n\n\t\t\t *** Show Records ***";
    if (studentCount == 0) {
        cout << "\n\n *** No Record Found ***";
    } else {
        cout << "\n\n *** Student Records ***";
        for (int a = 0; a < studentCount; a++) {
            cout << "\n\n Student ID: " << s[a].id;
            cout << "\n Student Name: " << s[a].name;
            cout << "\n Student Marks: " << s[a].marks;
            cout << "\n Student Percentage: " << s[a].per;
            cout << "\n Student Grade: " << s[a].grade;
        }
    }
}

int main() {
    char choice;
    do {
        cout << "\n\n\t\t\t*** Student Management System ***";
        cout << "\n\n 1) Insert Record";
        cout << "\n\n 2) Search Record";
        cout << "\n\n 3) Update Record";
        cout << "\n\n 4) Delete Record";
        cout << "\n\n 5) Show Records";
        cout << "\n\n 6) Exit";
        cout << "\n\n Enter Your Choice -> ";
        cin >> choice;
        switch (choice) {
            case '1':
                insert();
                break;
            case '2':
                search();
                break;
            case '3':
                update();
                break;
            case '4':
                deleteRecord();
                break;
            case '5':
                showRecords();
                break;
            case '6':
                exit(0);
            default:
                cout << "\n\n *** Invalid Choice ***";
        }
        cout << "\n\nPress any key to continue...";
        cin.ignore();
        cin.get();
    } while (choice != '6');

    return 0;
}
