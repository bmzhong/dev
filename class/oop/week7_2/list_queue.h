class Char_queue
{

public:
    Char_queue(unsigned int capacity = 0);

    ~Char_queue();

    bool empty() const;

    char dequeue(); //����

    void enqueue(char); //���

    bool full() const;

    int size() ;

    char front() const;

private:
    struct Node
    {

        Node *next;

        char data;
    };

    Node head_node; //ͷ��㣬��ͷ��������

    Node *tail; //βָ�룬��β
};