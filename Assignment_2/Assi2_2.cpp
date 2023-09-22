#include<iostream>
using namespace std;

class Address
{
    private:
    string building;
    string street;
    string city;
    int pin;
    
    public:
    Address()       //parameterless ctor
    {
        building="Dwarka";
        street="Miraj road";
        city="miraj";
        pin=416410;
    }
    Address(string building,string street,string city,int pin)  //parameterised ctor
    {
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }
    void accept()
    {
       cout<<"Enter the date";
       cin>>this->building>>this->street>>this->city>>this->pin; 
    }

    void display()
    {
        cout<<"address= "<< building<<","<< street<<","<< city<<","<< pin<<endl;
    }

    void setbuilding(string building)
    {
        this->building=building;
    }
    void setstreet(string street)
    {
        this->street=street;
    }
    void setcity(string city)
    {
        this->city=city;
    }
    void setpin(int pin)
    {
        this->pin=pin;
    }
    //getters
    string getbuilding()
    {
        return this->building;
    }
    string getstreet()
    {
        return this->street;
    }
    string getcity()
    {
        return this->city;
    }
    int getpin()
    {
        return this->pin;
    }


};
int main()
{
    Address a1;
    a1.display();
    Address a2("Dyandeep","sangli road","sangli",416415);
    a2.display();
    a2.setbuilding("sagar");
    a2.setstreet("market road");
    a2.setcity("pune");
    a2.setpin(416425);

    cout<<"address= "<< a2.getbuilding()<<","<< a2.getstreet()<<","<< a2.getcity()<<","<< a2.getpin()<<endl;
}
    