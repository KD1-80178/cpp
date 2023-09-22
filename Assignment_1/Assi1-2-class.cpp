#include<iostream>
 using namespace std;
class Date
{
    private:
    int day;
    int month;
    int year;

    public:
    void initDate()
    {
        day=01;
        month=01;
        year=2020;
    }
    void acceptDateFromConsole()
    {
        cout<<"accept the data";
        cout<<"enter the day,month,year";
        cin>>day>>month>>year;

    }
    void isLeapYear()
    {
        
        if (year%4==0 & year%100 != 0)
        cout<<year<<" is a leap year\n";
        else
        cout<<year<<" is a not leap year\n";
    }
    void printDateOnConsole()
    {
        cout<<"date= "<<day<<"/"<<month<<"/"<<year<<endl;
    }

};
int main()
{
    Date d1;
    int choice;
    do
    {
    printf("enter the choice:0.break 1.initDate 2.acceptDateFromConsole\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        d1.initDate();
        d1.printDateOnConsole();
        d1.isLeapYear();
        break;

        case 2:
        d1.acceptDateFromConsole();
        d1.printDateOnConsole();
        d1.isLeapYear();
        break;
        } 
    }while(choice!=0);
}