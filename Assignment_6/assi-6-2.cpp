#include<iostream>
using namespace std;
class Employee
{
    private:
    int id;
    float sal;
    public:
    Employee()
    {
        this->id=10;
        this->sal=50000;
    }
    Employee(int id,float sal)
    {
        this->id=id;
        this->sal=sal;
    }
    void accept()
    {
        cout<<"enter the id ="<<endl;
        cin>>id;
        cout<<"enter the sal = "<<endl;
        cin>>sal;
    }
    void disp()
    {
        cout<<"Inside Employee class "<<endl;
        cout<<"ID = "<<id<<endl;
        cout<<"Salary = "<<sal<<endl;
        cout<<endl;
    }
};
class Manager:virtual public Employee
{
    private:
    float bonus;
    public:
    Manager()
    {
        this->bonus=5000;
    }
    Manager(float bonus)
    {
        this->bonus=bonus;
    }
    void accept()
    {
        Employee::accept();
    }
    protected:

    void acceptManager()
    {
        
        cout<<"enter the bonus ="<<endl;
        cin>>bonus;
    }
    void dispManager()
    {
        Employee::disp();
        cout<<"Inside Manager class "<<endl;
        cout<<"Bonus = "<<bonus<<endl;
        cout<<endl;
    }
};
class Salesman:virtual public Employee
{
    private:
    float comm;
    public:
    Salesman()
    {
        this->comm=2500;
    }
    Salesman(float bonus)
    {
        this->comm=comm;
    }
    void accept()
    {
        Employee::accept();
    }
    protected:
    void acceptSalesman()
    {
        cout<<"enter the comm ="<<endl;
        cin>>comm;
    }
    void dispSalesman()
    {
        cout<<"Inside salesman class "<<endl;
        cout<<"Comm = "<<comm<<endl;
        cout<<endl;
    }
};
class Sales_manager:public Manager,public Salesman
{
    public:
    void acceptSales_manager()
    {
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }
    void dispSales_manager()
    {
        Employee::disp();
        Manager::dispManager();
        Salesman::dispSalesman();
        
    }
};
int main()
{
    Sales_manager s;
    s.acceptSales_manager();
    s.dispSales_manager();

    
    return 0;
}