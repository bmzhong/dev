#include "list_queue.h"
#include<iostream>
Char_queue::Char_queue(unsigned int capacity)
{
    head_node.next = nullptr;
    head_node.data = '@';
    Node *p = &head_node;
    for (int i = 0; i < capacity; ++i)
    {
        p->next = new Node;
        p->next->data = ' ';
        p = p->next;
    }
    tail = &head_node;
}
Char_queue::~Char_queue()
{
    Node *p = head_node.next;
    head_node.next = nullptr;
    Node *temp=nullptr;
    std::cout<<"\n\nlinked list queue 析构函数删除的节点顺序：";
    while (p!=nullptr)
    {
        temp = p->next;
        std::cout<<p->data<<" "; 
        delete p;
        p=temp;
    }
	std::cout<<std::endl;
    tail = &head_node;
}

bool Char_queue::empty() const
{
    return tail == &head_node;
}

bool Char_queue::full() const
{
    return false;
}

void Char_queue::enqueue(char ch)
{
    tail->next = new Node;
    tail->next->data = ch;
    tail = tail->next;
} //入队

char Char_queue::dequeue()
{

    if (Char_queue::empty())
        return head_node.data;
    Node *p = head_node.next;
    if (tail == p)
        tail = &head_node;
    head_node.next = p->next;
    char ch = p->data;
    delete p;
    return ch;
} //出队

int Char_queue::size()
{
    int k = 0;
    Node* p = &head_node;
    while (p != tail)
    {
        p = p->next;
        ++k;
    }
    return k;
}

char Char_queue::front() const
{
    if(Char_queue::empty())
        return head_node.data;
    return head_node.next->data;
}
