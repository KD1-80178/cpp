#include <iostream>
using namespace std;

class Volume
{
    private:
    int length;
    int width;
    int height;

    public:
    Volume()
    {
        this->length=1;
        this->width=1;
        this->height=1;
    }
    void acceptData()
    {
        cout<<"enter the length="<<endl;
        cout<<"enter the width="<<endl;
        cout<<"enter the height="<<endl;
        cin>>length;
        cin>>width;
        cin>>height;
    }
    void dispData()
    {
        cout<<"length="<<length<<","<<"width"<<width<<","<<"height"<<height<<endl;
    }
    void volume()
    {
        int volume=length*width*height;
        cout<<"Volume= "<<volume<<endl;
    }

};
int menu()
{
    int choice;
    cout<<"enter the choice=0.exit 1.acceptData 2.dispData 3.volume";
    cin>>choice;
    return choice;
}
int main()
{
    Volume v1;
    int choice;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1:
            v1.acceptData();
            break;
            case 2:
            v1.dispData();
            break;
            case 3:
            v1.volume();
        }
    }
} 