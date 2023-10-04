#include<iostream>
using namespace std;
class Factorial
{
    private:
    int num;
    int fact;
    public:
    Factorial()
    {
        this->num=1;
        this->fact=1;
    }
    void acceptData()
    {
        cout<<"enter the num = "<<endl;
        cin>>num;
        if(num)
        throw 1.2;
    }
    void factorial()
    {
        for(int i=1;i<=num;i++)
        {
            fact=fact*i;
        }
        cout<<"Factorial = "<<fact<<endl;
    }
};
int main()
{
    Factorial f;
    
    try{
    f.acceptData();
    f.factorial();
    }
    catch(double i)
    {
        cout<<"number is invalid ....";
    }
    return 0;
}
