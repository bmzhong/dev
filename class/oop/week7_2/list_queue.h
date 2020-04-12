class Char_queue
{

public:
    Char_queue(unsigned int capacity = 0);

    ~Char_queue();

    bool empty() const;

    char dequeue(); //出队

    void enqueue(char); //入队

    bool full() const;

    int size() ;

    char front() const;

private:
    struct Node
    {

        Node *next;

        char data;
    };

    Node head_node; //头结点，队头，单链表

    Node *tail; //尾指针，队尾
};