#include<iostream>
using namespace std;
class Product
{
    protected:
    int id;
    string title;
    char type;
    double price;
    public:
    Product()
    {
        this->id=0;
        this->title="   ";
        this->price=0.0;
    }
    Product(int id,string title,int price)
    {
        this->id=id;
        this->title=title;
        this->price=price;
    }
    virtual void accept()
    {
        cout<<"enter the id= "<<endl;
        cin>>this->id;
        cout<<"enter the title= "<<endl;
        cin>>this->title;
        cout<<"enter the price= "<<endl;
        cin>>this->price;
    }
    void disp()
    {
        cout<<"Id= "<<id<<endl; 
        cout<<"Title= "<<title<<endl; 
        cout<<"Price= "<<price<<endl;      
    }
    int getId()
    {
        return this->id;
    }
    void setId(int id)
    {
        this->id=id;
    }
    string getTitle()
    {
        return this->title;
    }
    void setTitle(string title)
    {
        this->title=title;
    }
    double getPrice()
    {
        return this->price;
    }
    void setprice(double price)
    {
        this->price=price;
    }
    char getType()
    {
        return this->type;
    }
    void setType(char type)
    {
        this->type=type;
    }
    friend void calculateBill(Product *ptr[],int index);
};
class Book:public Product
{
    private:
    string author; 
    char type;   
    public:
    Book()
    {
       this->author="   ";
       this->setType('B');
    }
    Book(string author,int id,string title,int price):Product(id,title,price)
    {
        this->author=author;
        setType('B');
    }

    void accept()
    {
        Product::accept();
        cout<<"enter the author= "<<endl;
        cin>>this->author;        
    }
    void disp()
    {
        Product::disp();
        cout<<"Author= "<<author<<endl;
    }
    
};
class Tape:public Product
{
    private:
    string artist;
    char type;    
    public:
    Tape()
    {
       this->artist="  ";
       this->setType('T');
    }
    Tape(string artist,int id,string title,int price):Product(id,title,price)
    {
        this->artist=artist;
        setType('T');
    }
    void accept()
    {
        Product::accept();
        cout<<"enter the artist= "<<endl;
        cin>>this->artist;        
    }
    void disp()
    {
        Product::disp();
        cout<<"Artist= "<<artist<<endl;
    }
      
};
int menu()
{
    int choice;
    cout<<"enter the choice = "<<endl;
    cout<<"0.exit"<<endl;
    cout<<"1.add book"<<endl;
    cout<<"2.add tape"<<endl;
    cout<<"3.Display products"<<endl;
    cout<<"4.Display bill"<<endl;
    cin>>choice;
    return choice;
}
void calculateBill(Product *ptr[],int index)
{
    double total_price=0;
    for (int i=0;i<index;i++)
    {
        if(ptr[i]->type=='B')
        {
            total_price=ptr[i]->price*0.9;
        }
        else
        {
            total_price=ptr[i]->price*0.95;
        }
        cout<<"Total price = "<<total_price<<endl;
    }
}
int main()
{
    int choice;
    Product *p[3];
    int index=0;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1:
            if (index < 3)
            {
                p[index] = new Book();
                p[index]->accept();
                index++;
            }
            else
            {
                cout << "no more books are added" << endl;
            }
            break;

            case 2:
            if (index < 3)
            {
                p[index] = new Tape();
                p[index]->accept();
                index++;
            }
            else
            {
                cout << "no more tape are added" << endl;
            }
            break;

            case 3:
            {
            for (int i = 0; i < 3; i++)
            {
                p[i]->disp();
            }
            }
            break;

            case 4:
            calculateBill(p,index);
            break;
            
            default:
            cout<<"invalid choice....."<<endl;
            break;
        }
        for(int i=0;i<index;i++)
        {
        delete p[i];
        }        
    }
    return 0;
}
