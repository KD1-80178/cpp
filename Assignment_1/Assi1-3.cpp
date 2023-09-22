#include<iostream>

using namespace std;
class Student
{
    private:
    int rollno;
    string name;
    int marks;

    public:
    void initStudent()
    {
        this->rollno=10;
        this->name="NIVEDITA";
        this->marks=105;
    }
    void acceptDataFromConsole()
    {
        cout<<"accept the data\n";
        cout<<"enter the rollno,name,marks\n";
        cin>>rollno>>name>>marks;

    }
    
    void printDataOnConsole()
    {
        cout<<"Student data= "<< rollno << "," << name << "," << marks << endl;
    }

};
int main()
{
    Student s1;
    int choice;
    do
    {
    printf("enter the choice:0.break 1.initStudent 2.acceptDataFromConsole\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        s1.initStudent();
        s1.printDataOnConsole();
        break;

        case 2:
        s1.acceptDataFromConsole();
        s1.printDataOnConsole();
        break;
        } 
    }while(choice!=0);
}