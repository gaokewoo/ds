#include <iostream>

using namespace std;

namespace QueueList
{
    template<typename T> class Queue;

    template<typename T>
        class Node
        {
            friend class Queue<T>;
            T elem;
            Node *next;
        };

    template<typename T>
        class Queue
        {
            public:
                Queue();
                ~Queue();
                bool isEmpty();
                void makeEmpty();
                void enQueue(T x);
                T deQueue();

            private:
                Node<T> *head;
                Node<T> *tail;

        };

    template<typename T>
        Queue<T>::Queue() try:head(new Node<T>),tail(head)
        {
        }
    catch(bad_alloc &e)
    {
        cerr<<"Queue alloc node error."<<endl;
        cerr<<"Error info:"<<e.what()<<endl;
    }

    template<typename T>
        Queue<T>::~Queue()
        {
            if(head->next!=NULL)
              makeEmpty();

            delete head;
            head=tail=NULL; 
        }

    template<typename T>
        bool Queue<T>::isEmpty()
        {
            return head->next == NULL;
        }

    template<typename T>
        void Queue<T>::makeEmpty()
        {
            while(head->next != NULL)
            {
                Node<T> *tmp=head->next;
                head=tmp->next;
                delete tmp;
            }

            tail=head;
        }

    template<typename T>
        void Queue<T>::enQueue(T x)
        {
            Node<T> *tmp = new Node<T>;

            tmp->elem=x;
            tmp->next=NULL;

            tail->next=tmp;
            tail=tmp;
        }

    template<typename T>
        T Queue<T>::deQueue()
        {
            T e;
            if(!isEmpty())
            {
                Node<T> *tmp=head->next;
                head->next=tmp->next;

                e=tmp->elem;
                delete tmp;
            }

            if(head->next == NULL) tail=head;

            return e;
        }
};

namespace QueueArray
{
    template <typename T> class Queue;

    template <typename T>
        class Queue
        {
            public:
                Queue();
                Queue(int size);
                ~Queue();
                bool isEmpty();
                bool isFull();
                int getCapacity();
                void makeEmpty();
                void enQueue(T x);
                T deQueue();

            private:
                enum { DEFAULT_SIZE = 512 };
                int size;
                int capacity;
                T *queue;
                int head;
                int tail;
        };

    template <typename T>
        Queue<T>::Queue()
        {
            try
            {
                queue = new T[DEFAULT_SIZE];

                head = 0;
                tail = -1;
                this->size = DEFAULT_SIZE;
                this->capacity = 0;
            }
            catch(bad_alloc &e)
            {
                cerr<<"Alloc memroy error."<<endl;
                cerr<<e.what()<<endl;
            }

        }

    template <typename T>
        Queue<T>::Queue(int size)
        {
            try
            {
                queue = new T[size];

                head = 0;
                tail = -1;
                this->size = size;
                this->capacity = 0;
            }
            catch(bad_alloc &e)
            {
                cerr<<"Alloc memroy error."<<endl;
                cerr<<e.what()<<endl;
            }

        }

    template <typename T>
        Queue<T>::~Queue()
        {
            try
            {
                delete [] queue;
            }
            catch(bad_alloc &e)
            {
                cerr<<"Release memroy error."<<endl;
                cerr<<e.what()<<endl;
            }

        }

    template <typename T>
        bool Queue<T>::isEmpty()
        {
            return capacity == 0;
        }

    template <typename T>
        bool Queue<T>::isFull()
        {
            return capacity == size;
        }

    template <typename T>
        int Queue<T>::getCapacity()
        {
            return capacity;
        }

    template <typename T>
        void Queue<T>::makeEmpty()
        {
            capacity = 0;
            head = 0;
            tail = -1;
        }

    template <typename T>
        void Queue<T>::enQueue(T x)
        {
            if(!isFull())
            {
                if(++tail == size)
                  tail = 0;
                queue[tail] = x;
                capacity++;
            }
            else
              cerr<<"The queue is full."<<endl;
        }

    template <typename T>
        T Queue<T>::deQueue()
        {
            T e;
            if(!isEmpty())
            {
                e = queue[head];
                if(--head == -1)
                  head = size-1;
                capacity--;
            }
            else
            {
                cerr<<"The queue is empty."<<endl;
            }

            return e;
        }

};

