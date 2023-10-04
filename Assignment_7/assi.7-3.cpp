#include <iostream>
using namespace std;

class Employee
{

private:
    int id;
    float salary;

public:
    Employee()
    {
        this->id = 0;
    }
    Employee(int id, float sal)
    {
        // this->set_id(id);
        // this->set_salary(sal);
        this->id = id;
        this->salary = salary;
    }
    int get_id()
    {
        return this->id;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_salary(float salary)
    {
        this->salary = salary;
    }
    float getSalary()
    {
        return this->salary;
    }

    void display()
    {
        cout << "Employee id = " << this->id << endl;
        cout << "Salary = " << this->salary << endl;
    }

    void accept()
    {
        cout << "Enter Employee id : " << endl;
        cin >> this->id;
        cout << "Enter Salary : " << endl;
        cin >> this->salary;
    }

    virtual ~Employee()
    {
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

public:
    void accept_manager()
    {
        cout << "Enter bonus ! " << endl;
        cin >> this->bonus;
    }

    void display_manager()
    {
        cout << "bonus = " << this->bonus << endl;
    }

    Manager()
    {
        this->bonus = 0;
    }
    Manager(int id, float salary, float bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    float get_bonus()
    {
        return this->bonus;
    }

    void set_bonus(float bonus)
    {
        cout << "Enter Bonus = " << endl;
        cin >> this->bonus;
    }
    void accept()
    {
        Employee::accept();
        this->accept_manager();
    }
    void display()
    {
        Employee::display();
        this->display_manager();
    }
    ~Manager()
    {
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

public:
    void display_salesman()
    {
        cout << "Commission = " << this->comm << endl;
    }
    void accept_salesman()
    {
        cout << "Enter commission ! " << endl;
        cin >> this->comm;
    }

    Salesman()
    {
        this->comm = 0;
    }
    Salesman(int id, int salary, int comm) : Employee(id, salary)
    {
        this->comm = comm;
    }

    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        cout << "Enter commision = " << endl;
        cin >> this->comm;
    }
    void display()
    {
        Employee::display();
        this->display_salesman();
    }
    void accept()
    {
        Employee::accept();
        this->accept_salesman();
    }
    ~Salesman()
    {
    }
};

class sales_manager : public Manager, public Salesman
{
public:
    sales_manager()
    {
    }
    sales_manager(int id, float salary, float bonus, float comm) : Manager(id, salary, bonus), Salesman(id, salary, bonus)
    {
    }

    void accept()
    {
        Employee::accept();
        this->accept_manager();
        this->accept_salesman();
    }
    void display()
    {
        Employee::display();
        this->display_manager();
        this->display_salesman();
    }
    ~sales_manager()
    {
    }
};

int main()
{

    Employee *employees[10];
    int choice = -1;

    Manager *m = NULL;
    Salesman *s = NULL;
    sales_manager *sm = NULL;
    int employeeCount = 0;

    while (choice != 0)
    {

        cout << "----------------------" << endl;
        cout << "Menu..." << endl;
        cout << "1. Accept Employee" << endl;
        cout << "2. Display the count of all employees with respect to designation" << endl;
        cout << "3. Display All Managers" << endl;
        cout << "4. Display All SalesMan" << endl;
        cout << "5. Display All SalesManager" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "----------------------" << endl;

        switch (choice)
        {
        case 1:
        {
            int empChoice;
            cout << "----------------------" << endl;
            cout << "Enter employee choice : " << endl;
            cout << "1. Employee " << endl;
            cout << "2. Manager " << endl;
            cout << "3. Salesman " << endl;
            cout << "4. SalesManager " << endl;
            cout << "0. Back to main menu " << endl;
            cout << "Enter your choice " << endl;
            cin >> empChoice;
            cout << "----------------------" << endl;
            Employee *emp = NULL;

            switch (empChoice)
            {
            case 1:
                employees[employeeCount] = new Employee();
                employees[employeeCount]->accept();
                employeeCount++;
                break;
            case 2:
                employees[employeeCount] = new Manager();
                employees[employeeCount]->accept();
                m = dynamic_cast<Manager *>(employees[employeeCount]);
                m->accept_manager();
                employeeCount++;
                break;
            case 3:
                employees[employeeCount] = new Salesman();
                employees[employeeCount]->accept();
                s = dynamic_cast<Salesman *>(employees[employeeCount]);
                s->accept_salesman();
                employeeCount++;
                break;
            case 4:
                employees[employeeCount] = new sales_manager();
                employees[employeeCount]->accept();
                sm = dynamic_cast<sales_manager *>(employees[employeeCount]);
                sm->accept_manager();
                sm->accept_salesman();
                employeeCount++;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice ! " << endl;
                break;
            }
            break;
        }
        case 2:
        {
            int managerCount = 0;
            int salesmanCount = 0;
            int salesManagerCount = 0;

            for (int i = 0; i < employeeCount; i++)
            {
                Manager *mptr = dynamic_cast<Manager *>(employees[i]);
                Salesman *sptr = dynamic_cast<Salesman *>(employees[i]);
                sales_manager *smptr = dynamic_cast<sales_manager *>(employees[i]);

                if (mptr)
                {
                    managerCount++;
                }
                else if (sptr)
                {
                    salesmanCount++;
                }
                else if (smptr)
                {
                    salesManagerCount++;
                }
            }
            cout << "Managers: " << managerCount << " Salesmen: " << salesmanCount << " SalesManagers: " << salesManagerCount << endl;
            break;
        }
        case 3:
        {
            for (int i = 0; i < employeeCount; i++)
            {
                Manager *mptr = dynamic_cast<Manager *>(employees[i]);
                if (mptr)
                {
                    mptr->display();
                }
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < employeeCount; i++)
            {
                Salesman *sptr = dynamic_cast<Salesman *>(employees[i]);
                if (sptr)
                {
                    sptr->display();
                }
            }
            break;
        }
        case 5:
        {
            for (int i = 0; i < employeeCount; i++)
            {
                sales_manager *smptr = dynamic_cast<sales_manager *>(employees[i]);
                if (smptr)
                {
                    smptr->display();
                }
            }
            break;
        }
        case 0:
        {
            for (int i = 0; i < employeeCount; i++)
            {
                delete employees[i];
            }
            break;
        }
        default:
            cout << "Invalid choice.!" << endl;
            break;
        }
    }

    return 0;
}