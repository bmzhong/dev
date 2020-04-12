#include "vector_queue.h"

VChar_queue::VChar_queue(unsigned int _capacity = default_capacity)
{
    queue = new char[_capacity];
    capacity = _capacity;
    head = tail = 0;
}

VChar_queue::~VChar_queue()
{
    delete[] queue;
}

bool VChar_queue::empty() const
{
    return head == tail;
}

char VChar_queue::dequeue()
{
    if (VChar_queue::empty())
        return '@';
    char ch = queue[head];
    head = (head + 1) % capacity;
    return ch;
} //出队

bool VChar_queue::enqueue(char ch)
{
    if (VChar_queue::full())
        return false;
    queue[tail] = ch;
    tail = (tail + 1) % capacity;
    return true;
} //入队

bool VChar_queue::full() const
{
    return head == (tail + 1) % capacity;
}

int VChar_queue::size() const
{
    if (VChar_queue::empty())
        return 0;
    int i = head;
    while ((i % capacity) != tail)
    {
        ++i;
    }
    return i-head;
}

char VChar_queue::front() const
{
    if(VChar_queue::empty())
        return '@';
    return queue[head];
}