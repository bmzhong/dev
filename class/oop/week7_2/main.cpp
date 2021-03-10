#include <iostream>
#include "list_queue.cpp"
#include "vector_queue.cpp"
using namespace std;
int main()
{
    Char_queue queue;
    cout << "linked list queue: " << endl;
    cout << "size: " << queue.size() << endl;
    cout << "empty?: " << queue.empty() << endl;
    cout << "输入五个字符：";
    for (int i = 0; i < 5; ++i)
    {
        char ch;
        cin >> ch;
        queue.enqueue(ch);
    }
    cout << "empty?: " << queue.empty() << endl;
    cout << "size: " << queue.size() << endl;
    cout << "dequeue 1: " << queue.dequeue() << endl;
    cout << "dequeue 2: " << queue.dequeue() << endl;
    cout << "front: " << queue.front() << endl;

    VChar_queue vqueue;
    cout << "\n\nvector queue: " << endl;
    cout << "size: " << vqueue.size() << endl;
    cout << "empty?: " << vqueue.empty() << endl;
    cout << "输入五个字符：";
    for (int i = 0; i < 5; ++i)
    {
        char ch;
        cin >> ch;
        vqueue.enqueue(ch);
    }
    cout << "empty?: " << vqueue.empty() << endl;
    cout << "size: " << vqueue.size() << endl;
    cout << "dequeue 1: " << vqueue.dequeue() << endl;
    cout << "dequeue 2: " << vqueue.dequeue() << endl;
    cout << "front: " << vqueue.front() << endl;
    return 0;
}
