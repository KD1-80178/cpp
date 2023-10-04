#include<iostream>
using namespace std;

class Student
{
    private:
    string name;
    string gender;
    int rollno;
    double marks[3];

    public:
    void accept()
    {
        cout<<"enter the name of student = "<<endl;
        cin>>name;
        cout<<"enter the gender = "<<endl;
        cin>>gender;
        cout<<"enter the roll no = "<<endl;
        cin>>rollno;
        cout<<"enter the marks = "<<endl;
        for(int i=0;i<3;i++)
        {
            cin>> marks[i];
        }
    }
    double percentage()
    {
        return (marks[1]+marks[2]+marks[3])/3.0;
    }    
    void disp()
    {
        cout<<"student data = "<<name<<","<<gender<<","<<rollno<<","<<endl;
        for (int i=0;i<3;i++)
        {
            cout<<"marks = "<<marks[i]<<endl;
        }
    }
    int getRollNumber() 
    {
    return rollno;
    }

};
    int searchRecords(Student arr[], int size, int rollNumber) 
    {
    for (int i = 0; i < size; i++) 
    {
        if (arr[i].getRollNumber() == rollNumber) 
        {
            return i;
        }
    }
    }
    // Function to sort array of Student objects based on their roll numbers
    void sortRecords(Student arr[], int size) 
    {
    for (int i = 0; i < size-1; i++) 
    {
        for (int j = 0; j < size-i-1; j++) 
        {
        if (arr[j].getRollNumber() > arr[j+1].getRollNumber()) 
        {
            swap(arr[j], arr[j+1]);
        }
        }
    }
    }

int main()
{
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int numStudents = 0;

int choice;
do {
    cout << "***** Student Management System *****" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Print All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Sort Students by Roll Number" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) 
    {
    case 1: {
    if (numStudents < MAX_STUDENTS) {
    cout << "Enter student details: " << endl;
    students[numStudents].accept();
    numStudents++;
    } else {
    cout << "Maximum number of students reached!" << endl;
    }
    break;
    }
    case 2: {
    cout << "Printing all students: " << endl;
    for (int i = 0; i < numStudents; i++) {
    students[i].disp();
    cout << endl;
    }
    break;
    }
    case 3: {
    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;

    int index = searchRecords(students, numStudents, rollNumber);
    if (index != -1) {
    cout << "Student found at index " << index << endl;
    students[index].accept();
    } else {
    cout << "Student not found!" << endl;
    }
    break;
    }
    case 4: {
    sortRecords(students, numStudents);
    cout << "Students sorted based on roll number!" << endl;
    break;
    }
    case 5: {
    cout << "Exiting the program..." << endl;
    break;
    }
    default: {
    cout << "Invalid choice. Please try again." << endl;
    }
    }

    cout << endl;
    } while (choice != 5);

    return 0;
}