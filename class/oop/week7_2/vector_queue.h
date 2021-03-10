class VChar_queue {     

public:

   VChar_queue(unsigned int _capacity);

   ~VChar_queue();

   bool empty() const; 

   char dequeue();                 //出队 

   bool enqueue(char);             //入队 

   bool full() const;

   int size() const;

   char front() const;

private:

   static unsigned const default_capacity = 32;

   char *queue;                   //循环队列

   unsigned int head, tail;           

   unsigned int capacity;

};