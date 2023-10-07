#include <iostream>
using namespace std;

template <class t>
class Stack
{
private:
    t *stack;
    int top;
    int size;

public:
    Stack()
    {
        this->size = 0;
        this->top = -1;
    }
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        stack = new t[size];
    }
    int get_size()
    {
        return this->size;
    }
    int get_top()
    {
        return this->top;
    }
    void push(t element)
    {
        if (top < this->size)
        {
            top++;
            this->stack[top] = element;
        }
        else
            cout << "Stack is full. Cannot insert element." << endl;
    }
    void pop()
    {
        if (this->top > 0)
        {
            this->stack[top] = 0;
            top--;
        }
        else
            cout << "Stack is empty. Cannot pop element." << endl;
    }
    void peek()
    {
        cout << "Peek element is " << stack[this->top] << endl;
    }
    void displayStack()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << "Stack Element at index[" << i << "] = " << this->stack[i] << endl;
        }
    }
    ~Stack()
    {
        delete[] stack;
    }
};
class Box
{
    float length;
    float width;
    float height;

public:
    Box()
    {
    }
    Box(float length, float width, float height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }
    void acceptParameter()
    {
        cout << "Enter length of box: ";
        cin >> this->length;
        cout << "Enter width of box: ";
        cin >> this->width;
        cout << "Enter height of box: ";
        cin >> this->height;
    }
    void displayParameter()
    {
        cout << endl
             << "Length of box is : " << length << endl;
        cout << "Width of box is : " << width << endl;
        cout << "Height of box is : " << height << endl;
    }
};


int main()
{
    Stack<int> s1(3);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.peek();
    s1.displayStack();
    s1.pop();
    s1.pop();
    s1.displayStack();
    s1.peek();

    Stack<char> s2(3);
    s2.push('A');
    s2.push('B');
    s2.push('C');
    s2.peek();
    s2.displayStack();
    s2.pop();
    s2.pop();
    s2.displayStack();
    s2.peek();

    return 0;
}