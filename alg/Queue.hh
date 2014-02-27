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
