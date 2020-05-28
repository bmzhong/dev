#include <iostream>
using namespace std;

template <class T>
class stack
{
private:
    T *base;
    int top;
    int capacity;

public:
    stack();

    ~stack();

    bool empty() const;

    bool full() const;

    void pop();

    void push(T t);

    int getSize() const;

    T getTop() const;
};

template <class T>
stack<T>::stack()
{
    base = new T[10];
    top = -1;
    capacity = 10;
}

template <class T>
stack<T>::~stack()
{
    delete[] base;
}

template <class T>
bool stack<T>::empty() const
{
    return top == -1;
}

template <class T>
bool stack<T>::full() const
{
    return top + 1 >= capacity;
}

template <class T>
void stack<T>::pop()
{
    if (!stack<T>::empty())
    {
        --top;
    }
}

template <class T>
void stack<T>::push(T t)
{
    if (stack<T>::full())
    {
        T *temp = new T[capacity + 10];
        for (int i = 0; i <= top; ++i)
        {
            temp[i] = base[i];
        }
        delete[] base;
        base = temp;
        capacity += 10;
    }
    base[++top]=t;
}

template <class T>
int stack<T>::getSize() const
{
    return top+1;
}

template <class T>
T stack<T>::getTop() const
{
    if (stack<T>::empty())
    {
        cout << "stack empty!" << endl;
        exit(1);
    }
    return base[top];
}

int main()
{
    stack<double> s1;
    for (int i = 0; i < 12; ++i)
    {
        s1.push(i + 0.14);
    }
    s1.pop();
    cout << s1.getTop() << endl;
    cout << s1.getSize() << endl;

    stack<int> s2;
    for (int i = 0; i < 22; ++i)
    {
        s2.push(i);
    }
    cout << s2.getTop() << endl;
    cout << s2.getSize() << endl;
    for (int i = 0; i < 3; ++i)
    {
        s2.pop();
    }
    cout << s2.getTop() << endl;
    cout << s2.getSize() << endl;
    system("pause");
    return 0;
}
