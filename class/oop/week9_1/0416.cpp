#include <iostream>
using namespace std;
class Queue
{
private:
    static unsigned const default_capacity = 4;

    int *queue; //循环队列

    unsigned int head, tail;

    unsigned int capacity;

public:
    Queue() : capacity(default_capacity), head(0), tail(0)
    {
        queue = new int[capacity];
    }

    ~Queue()
    {
        delete[] queue;
    }

    Queue(const Queue &q);

    Queue &operator=(const Queue &q);

    friend Queue operator+(int num, Queue q);

    friend Queue operator+(Queue q, int num);

    friend int operator--(Queue &q);

    friend ostream &operator<<(ostream &, const Queue &);

    bool empty() const;

    bool full() const;
};

Queue & Queue::operator=(const Queue &q)
{
    capacity = q.capacity;
    head = q.head;
    tail = q.tail;
    queue = new int[capacity];
    for (int i = 0; i < capacity; ++i)
    {
        queue[i] = q.queue[i];
    }
    return *this;
}

Queue::Queue(const Queue &q)
{
    capacity = q.capacity;
    head = q.head;
    tail = q.tail;
    queue = new int[capacity];
    for (int i = 0; i < capacity; ++i)
    {
        queue[i] = q.queue[i];
    }
}

bool Queue::empty() const
{
    return head == tail;
}

int operator--(Queue &q)
{
    try
    {
        if (q.empty())
            throw 0;
        int num = q.queue[q.head];
        q.head = (q.head + 1) % q.capacity;
        return num;
    }
    catch (int)
    {
        std::cerr << "The queue is empty!" << '\n';
        return 0;
    }

} //出队

Queue operator+(int num, Queue q)
{
    try
    {
        if (q.full())
            throw 0;
        q.queue[q.tail] = num;
        q.tail = (q.tail + 1) % q.capacity;
        return q;
    }
    catch (int)
    {
        std::cerr << "The queue is full!" << '\n';
        return q;
    }
} //入队

Queue operator+(Queue q, int num)
{
    try
    {
        if (q.full())
            throw 0;
        q.queue[q.tail] = num;
        q.tail = (q.tail + 1) % q.capacity;
        return q;
    }
    catch (int)
    {
        std::cerr << "The queue is full!" << '\n';
        return q;
    }
}
bool Queue::full() const
{
    return head == (tail + 1) % capacity;
}

ostream &operator<<(ostream &os, const Queue &q)
{
    int i = q.head;
    while ((i % q.capacity) != q.tail)
    {
        os << q.queue[i] << " ";
        ++i;
    }
    os << endl;
    return os;
}
int main()
{

    Queue q;
    Queue p;
    --q; // Display：The queue is empty!

    q = q + 5 + 6 + 3;

    cout << q; // Display：5   6   3

    cout << --q << endl; // Display：5

    cout << q; // Display：6   3

    q = 9 + q;

    cout << q; // Display：6   3   9

    q = 2 + q; // Display：The queue is full!

    cout << q; // Display：6   3   9

    return 0;
}
