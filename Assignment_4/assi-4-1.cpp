#include<iostream>
using namespace std;

class Time
{
    private:
    int hr;
    int min;
    int sec;

    int gethr()
    {
        return this->hr;
    }
    void sethr(int hr)
    {
        this->hr=hr;
    }
    int getmin()
    {
        return this->min;
    }
    void setmin(int min)
    {
        this->min=min;
    }
    int getsec()
    {
        return this->sec;
    }
    void setsec(int sec)
    {
        this->sec=sec;
    }


    public:
    Time()
    {
        hr=10;
        min=15;
        sec=25;
    }
    Time(int hr,int min,int sec)
    {
        this->hr=hr;
        this->min=min;
        this->sec=sec;
    }
    void accept()
    {
        cout<<"enter the hr ="<<endl;
        cin>>this->hr;
        cout<<"enter the min ="<<endl;
        cin>>this->min;
        cout<<"enter the sec ="<<endl;
        cin>>this->sec;
    }
    void printTime()
    {
        cout<<"Time = "<<hr<<":"<<min<<":"<<sec<<endl;
    }
    
};

int main()
{
    Time *ptr[3];
    // DYNAMIC MEMORY ALLOCATION FOR OBJECTS
    ptr[0]=new Time(10,25,56);
    ptr[1]=new Time();
    ptr[2]=new Time(8,15,45);

    //DISPLAYING THE OBJECTS
    for (int i=0;i<3;i++)
    {
        ptr[i]->printTime();
    }
    for (int i=0;i<3;i++)
    {
        ptr[i]->accept();
        ptr[i]-> printTime();
     }


    delete ptr[0];
    delete ptr[1];
    delete ptr[2];
    
    ptr[0]=NULL;
    ptr[1]=NULL;
    ptr[2]=NULL;
    return 0;


}