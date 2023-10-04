#include<iostream>
using namespace std;
class Date
{
    private:
    int day;
    int month;
    int year;
    public:
    Date()
    {
        this->day=01;
        this->month=01;
        this->year=2020;
    }
    Date(int day,int month,int year)
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    void accept()
    {
        cout<<"enter the day = "<<endl;
        cin>>day;
        cout<<"enter the month = "<<endl;
        cin>>month;
        cout<<"enter the year = "<<endl;
        cin>>year;
    }
    void disp()
    {
        cout<<"Date = "<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
    }
    int getDay()
    {
        return day;
    }
    void setDay(int day)
    {
        this->day=day ;
    }
    int getMonth()
    {
        return month;
    }
    void setMonth(int month)
    {
        this->month=month;
    }
    int getYear()
    {
        return year;
    }
    void setYear(int year)
    {
        this->year=year;
    }
};
class Person
{
    private:
    string name;
    string address;
    Date birth_date;
    public:
    Person()
    {
        this->name=" ";
        this->address="karad";
    }     
    Person(string name,string address,int day,int month,int year):birth_date(day,month,year)
    {
        this->name=name;
        this->address=address;        
    }
    void acceptperson()
    {
        cout<<"enter the person name = "<<endl;
        cin>>name;
        cout<<"enter the address = "<<endl;
        cin>>address;
        cout<<"enter the birth details= "<<endl;
        birth_date.accept();      
    }
    void dispperson()
    {
        cout<<"data of person = "<<name<<","<<address<<endl;
        cout<<"Employee date of birth = "<<endl;
        birth_date.disp();
    }
    string getName()
    {
        return name;
    }
    void setname(string name)
    {
        this->name=name ;
    }
    string getAddress()
    {
        return address;
    }
    void setAddress(string address)
    {
        this->address=address ;
    }
};
class Employee:public Person
{
    private:
    int id;
    float salary;
    string name;
    Date dobj;
    public:
    Employee()
    {
        this->id=1;
        this->salary=1000;
        this->name="Nivedita";
    }
    Employee(int id,float salary,string name,int day,int month,int year):dobj(day,month,year)
    {
        this->id=id;
        this->salary=salary;
        this->name=name;
        // this->dobj.setDay(day);
        // this->dobj.setDay(month);
        // this->dobj.setDay(year);
    }
    void acceptEmployee()
    {
        Person::acceptperson();
        cout<<"Enter the id = "<<endl;
        cin>>id;
        cout<<"Enter the salary = "<<endl;
        cin>>salary;
        cout<<"Enter the employee name = "<<endl;
        cin>>name;
        cout<<"enter the joining details= "<<endl;
        dobj.accept();
    }
    void dispEmployee()
    {
        Person::dispperson();
        cout<<"Employee details = "<<id<<","<<salary<<","<<name<<endl;
        cout<<"Employee date of joining = "<<endl;
        dobj.disp();
    }
    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id=id ;
    }
    double getSalary()
    {
        return salary;
    }
    void setSalary(double salary)
    {
        this->salary=salary;
    }
    string getName()
    {
        return name;
    }
    void setDay(string name)
    {
        this->name=name ;
    }
};
int main()
{
    Employee e;
    e.acceptEmployee();
    e.dispEmployee();

    Employee e1(10,50000,"pratik",23,11,1991);
    e1.dispEmployee();

    Person p1;
    p1.dispperson();

    Person p2("prabha","miraj",02,02,1975);
    p2.dispperson();

}