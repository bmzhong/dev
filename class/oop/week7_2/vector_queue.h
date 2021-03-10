class VChar_queue {     

public:

   VChar_queue(unsigned int _capacity);

   ~VChar_queue();

   bool empty() const; 

   char dequeue();                 //���� 

   bool enqueue(char);             //��� 

   bool full() const;

   int size() const;

   char front() const;

private:

   static unsigned const default_capacity = 32;

   char *queue;                   //ѭ������

   unsigned int head, tail;           

   unsigned int capacity;

};