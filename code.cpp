#include<iostream>
#include<string>
using namespace std;

struct Student
{
    string name;
    int id;
    int marks[3];

    void input();
    void display();
};

char calculateGrade(int total);

int main()
{
    Student s1;
    int total = 0;

    s1.input();
    s1.display();

    // Calculate total marks
    for (int i = 0; i < 3; i++)
    {
        total += s1.marks[i];
    }

    cout << "\nTotal Marks: " << total << "/300" << endl;

    char grade = calculateGrade(total);

    cout << "Grade: " << grade << endl;

    return 0;
}

// Function Definitions

void Student::input()
{
    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter marks of subject " << i + 1 << " (0-100): ";
        cin >> marks[i];

        // Validation
        while (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks! Enter again (0-100): ";
            cin >> marks[i];
        }
    }
}

void Student::display()
{
    cout << "\n------ Student Details ------\n";
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Marks of subject " << i + 1 << ": " << marks[i] << endl;
    }
}

char calculateGrade(int total)
{
    float percentage = (total / 300.0) * 100;

    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 60)
        return 'C';
    else
        return 'F';
}