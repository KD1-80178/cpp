#include<iostream>
using namespace std;

class Distance
{
    private:
    int inch;
    int feet;
    public:
    Distance()
    {
        this->inch=1;
        this->feet=1;
    }
    Distance(int inch,int feet)
    {
        this->inch=inch;
        this->feet=feet;
    }
    void disp()
    {
        cout<<"Distance in inch = "<<feet<<endl;
        cout<<"Distance in feet = "<<inch<<endl;
    }
    Distance operator+ (Distance d2)
    {
        Distance result;
        result.inch=this->inch+d2.inch;
        result.feet=this->feet+d2.feet;
        return result;
    } 

    Distance operator++(int)
    {
        // returned value should be a copy of the object before increment
        Distance temp = *this;
        ++inch;
        return temp;
    }

    friend bool operator== (const Distance &c,const Distance &c1);
    friend void operator<< (ostream &out,Distance d);
    friend void operator>> (istream &in,Distance &d);
    friend void operator++ (Distance d);
};
bool operator== (const Distance &c,const Distance &c1)
{
    return (c.inch == c1.inch && c.feet == c1.feet);
}
void operator<< (ostream &out,Distance d)
{
    out<<"Distance in inch = "<<d.inch<<endl;
    out<<"Distance in feet = "<<d.feet<<endl;
}
void operator>> (istream &in,Distance &d)
{
    cout<<"enter the inch = "<<endl;
    in>>d.inch;
    cout<<"enter the feet = "<<endl;
    in>>d.feet;
}
void operator++ (Distance d)
{
     d.inch++;
     d.feet++;
}
void operator++ (Distance d)
{
     ++d.inch;
     ++d.feet;
}

int main()
{
    Distance d1;
    d1.disp();

    Distance d2(15,12);
    d2.disp();
    Distance d3(15,10);
    d2.disp();

    Distance d4=d1+d2;
    cout<<"Inside + operator overloading"<<endl;
    d3.disp();

    Distance d5;
    cout<<"Inside >> operator overloading"<<endl;
    cin>>d5;
    cout<<"Inside << operator overloading"<<endl;
    cout<<d5;

    cout<<"Inside == operator overloading"<<endl;
    if(d2==d3)
    cout<<"Distances are same...."<<endl;
    else
    cout<<"Distances are not same...."<<endl;

    cout<<"Inside ++(post-increment) operator overloading"<<endl;
    d5++; 
    d5.disp(); 

    Distance d6=d2+d3;
    ++d6;
    d6.disp();  
    
    return 0;
}