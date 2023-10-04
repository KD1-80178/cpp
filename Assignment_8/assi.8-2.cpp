#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int top = -1;

public:
    Stack() : size(5)
    {
        this->arr = new int[size];
    }

    Stack(int size) : size(size)
    {
        this->arr = new int[size];
    }

    Stack(Stack &st)
    {
        cout << "Inside Copy Constructor" << endl;
        this->arr = new int[st.size];
        this->size = st.size;
        this->top = st.top;
        for (int i = 0; i <= this->top; i++)
        {
            this->arr[i] = st.arr[i];
        }
    }

    void push(int ele)
    {
        this->top++;
        this->arr[top] = ele;
    }

    int pop()
    {
        return this->arr[top--];
    }

    int peek()
    {
        return this->arr[top];
    }

    bool isEmpty()
    {
        if (this->top == -1)
            ;
        return true;
        return false;
    }

    bool isFull()
    {
        if (this->top == this->size)
            return true;
        return false;
    }

    void print()
    {
        cout << "Stack: \t";
        for (int i = 0; i <= this->top; i++)
            cout << this->arr[i] << "\t";
        cout << endl;
    }

    void operator=(Stack &st)
    {
        cout << endl;
        cout << "Assignment Operator Overloading" << endl;
        this->size = st.size;
        this->top = st.top;
        for (int i = 0; i <= this->top; i++)
        {
            this->arr[i] = st.arr[i];
        }
    }

    ~Stack()
    {
        delete[] this->arr;
    }
};

int main()
{
    Stack st1(3);
    st1.push(10);
    st1.push(20);
    cout << "Stack top: \t" << st1.peek() << endl;
    st1.push(30);
    st1.print();
    st1.push(40);
    cout << "Poped Element: \t" << st1.pop() << endl;
    st1.push(50);
    st1.print();
    cout << endl;

    Stack st2 = st1;
    st2.print();

    Stack st3;
    st3 = st1;
    st3.print();

    return 0;
}