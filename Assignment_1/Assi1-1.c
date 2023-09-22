#include<stdio.h>


struct Date{
  int day;
  int month;
  int year;
};

void initDate(struct Date *ptr)
{
    ptr->day=01;
    ptr->month=01;
    ptr->year=2020;  
}

void acceptDateFromConsole(struct Date *ptr)
{
    printf("Enter the day,month and year\n");
    scanf("%d%d%d",&ptr->day,&ptr->month,&ptr->year);
}

void printDateOnConsole(struct Date *ptr)
{
    printf("Date= %d:%d:%d\n",ptr->day,ptr->month,ptr->year);
}
int main()
{
    
    struct Date d1;
    int choice;
    do
    {
    printf("enter the choice:0.break 1.initDate 2.acceptDateFromConsole\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        initDate(&d1);
        printDateOnConsole(&d1);
        break;
        case 2:
        acceptDateFromConsole(&d1);
        printDateOnConsole(&d1);
        break;

    } 
    }while(choice!=0);
}