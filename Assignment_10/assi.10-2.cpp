#include <iostream>
#include<vector>
using namespace std;

class insufficient_funds
{
private:
    int id;
    double cur_balance;
    double withdrow_amount;

public:
    insufficient_funds(int id, double cur_balance, double withdrow_amount)
    {
        this->id = id;
        this->cur_balance;
        this->withdrow_amount;
    }

    void display()
    {
        cout << "ERROR : insufficient_funds..." << endl;
        cout << "Account ID: \t" << this->id << endl;
        cout << "Current Balance: \t" << this->cur_balance << endl;
        cout << "Withdrowing amount: \t" << this->withdrow_amount << endl;
    }
    void display2(string type)
    {
        cout << type << " amount cannot be equal to or less than zero." << endl;
    }
};

enum account_type
{
    Saving ,
    Current,
    Dmat
};

class Account
{
private:
    int id;
    account_type type;
    double balance;

public:
    Account()
    {
        this->id = 0;
        this->type = Current;
        this->balance = 200;
    }

    Account(int id, account_type type)
    {
        this->id = id;
        this->type = type;
    }

    void accept()
    {
        int num;
        cout << "Enter Account ID: \t";
        cin >> this->id;
        cout << "Enter Account Type\n1. Saving\n2. Current\n3. Dmat: \t";
        cin >> num;
        type = account_type(num);

        cout << "Enter Balance Amount: \t";
        cin >> this->balance;
    }

    void display()
    {
        cout << "****Account Details****" << endl;
        cout << "Account ID: \t" << this->id << endl;
        cout << "Account Type: \t" << account_type(this->type) << endl;
        cout << "Account Balance: \t" << this->balance << endl;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_type(account_type type)
    {
        this->type = type;
    }

    int get_id()
    {
        return this->id;
    }

    account_type get_type()
    {
        return this->type;
    }

    double get_balance()
    {
        return this->balance;
    }

    void deposit(double amount)
    {
        this->balance += amount;
    }

    void withdraw(double amount)
    {
        if(this->balance < amount)
            throw insufficient_funds(this->id, this->balance, amount);
        else
            this->balance -= amount;
    }
};

enum emenu1
{
    EXIT,
    CREATE_ACCOUNT,
    SHOW_ACCOUNTS,
    MAKE_TRANSACTION
};

emenu1 menu1()
{
    int choice;
    cout << "------Menu--------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Amount" << endl;
    cout << "3. Withdraw Amount" << endl;
    cout << "4. find account details" << endl;
    cout << "5. Display all Account Details in forward order" << endl;
    cout << "6. Display all Account Details in reverse order" << endl;
    cout << "-----------------" << endl;
    cin >> choice;
    return emenu1(choice);
}

enum emenu2
{
    RETURN_TO_MENU,
    DEPOSIT,
    WITHDRAW
};

emenu2 menu2()
{
    int choice;
    cout << "0. Return to Menu" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cin >> choice;
    return emenu2(choice);
}

int main()
{
    vector <Account*> acclist;
    int choice1, choice2, acc_no, amount;
    Account *arr;
    while ((choice1 = menu1()) != 0)
    {
        switch (choice1)
        {
        case 1:
            {
            arr = new Account;
            arr->accept();
            acclist.push_back(dynamic_cast<Account*>(arr));
            }
            break;

        case 2:
            cout << "Enter account No: \t";
            cin >> acc_no;
            cout << "Enter Amount: \t";
            cin >> amount;
            for (int i = 0; i < acclist.size(); i++)
            {
                if (acclist.at(i)->get_id() == acc_no)
                {
                    try
                    {
                        acclist.at(i)->deposit(amount);
                    }
                    catch(insufficient_funds error)
                    {
                        error.display();
                    }
                    acclist.at(i)->display();
                }
            }
            break;

        case 3:
                cout << "Enter Account ID = ";
            cin >> acc_no;

            for (int i = 0; i < acclist.size(); i++)
        {

            if (acclist.at(i)->get_id() == acc_no)
            {
            cout << "Enter withdraw amount = ";
            cin >> amount;

            try
            {
                acclist.at(i)->withdraw(amount);
            }
            catch (insufficient_funds i)
            {
                i.display();
                i.display2("Withdraw");
            }
            break;
            }
            else
            {
            cout << "Wrong Account No entered..." << endl;
            break;
            }
        }
        case 4:
            cout << "Enter Account ID = ";
            cin >> acc_no;

        for (int i = 0; i < acclist.size(); i++)
        {
            if (acclist.at(i)->get_id() == acc_no)
            {
                acclist.at(i)->display();
                break;
            }
            else
            {
                cout << "Wrong Account No entered..." << endl;
                break;
            }
        }
        break;
        case 5:
            for (int i = 0; i < acclist.size(); i++)
                acclist.at(i)->display();
            break;
        case 6:
            for (int i = acclist.size() - 1; i >= 0; i--)
                acclist.at(i)->display();
            break;
        default:
            cout << "Wrong choice entered." << endl;
            break;
        }
    }
    for (int i = 0; i < acclist.size(); i++)
    {
        delete acclist.at(i);
    }

    return 0;
}
