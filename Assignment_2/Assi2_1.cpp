#include<iostream>

using namespace std;
namespace Nstudent
{
    int rollno=10;
    string name="Pratik";
    int marks=115;

    class Students
    {
    public:
    int rollno;
    string name;
    int marks;
    };
}
using namespace Nstudent;
int main()
{
    Nstudent::Students s1,s2;
    s1.rollno=10;
    s1.name="Nivedita";
    s1.marks=110;
    cout<<"within class (s1) = "<<s1.rollno<<endl;
    cout<<"within class = "<<s1.name<<endl;
    cout<<"within class = "<<s1.marks<<endl;

    s2.rollno=12;
    s2.name="Pratik";
    s2.marks=115;
    cout<<"within class (s2) = "<<s2.rollno<<endl;
    cout<<"within class = "<<s2.name<<endl;
    cout<<"within class = "<<s2.marks<<endl;

    using namespace Nstudent;   
    cout<<"within namespace = "<<rollno<<endl;
    cout<<"within namespace = "<<name<<endl;
    cout<<"within namespace = "<<marks<<endl;

    
}