#include <iostream>

using namespace std;

namespace StackList
{

    template <typename T> class Stack;

    template<typename T>
        class Node
        {
            friend class Stack<T>;
            T elem;
            Node *next;
        };

    template<typename T>
        class Stack
        {
            public:
                Stack();
                ~Stack();
                bool isEmpty();
                void makeEmpty();
                void push(T x);
                T top();
                T pop();

            private:
                Node<T> *s;
        };

    template<typename T>
        Stack<T>::Stack()try:s(new Node<T>)
        {
            s->next=NULL;
        }
    catch(bad_alloc &e)
    {
        cerr<<"Stack alloc Node error."<<endl;
        cerr<<"Error info:"<<e.what()<<endl;
    }

    template<typename T>
        bool Stack<T>::isEmpty()
        {
            return s->next == NULL;
        }

    template<typename T>
        T Stack<T>::pop()
        {
            T e;
            try
            {
                Node<T> *p = s->next;
                s->next = p->next;
                if(p != NULL)
                {
                    e = p->elem;
                    delete p;
                }
                else
                {
                    cerr<<"Stack is empty."<<endl;

                    throw;
                }
            }
            catch(bad_alloc &e)
            {
                cerr<<"Release Node error."<<endl;
                cerr<<"Error info:"<<e.what()<<endl;
            }

            return e;
        }

    template<typename T>
        void Stack<T>::makeEmpty()
        {
            while(!isEmpty())
            {
                pop();
            }
        }

    template<typename T>
        Stack<T>::~Stack()
        {
            if(!isEmpty())
              makeEmpty();

            try
            {
                delete s;
                s=NULL;
            }
            catch(bad_alloc &e)
            {
                cerr<<"Stack release Node error."<<endl;
                cerr<<"Error info:"<<e.what()<<endl;
            }
        }

    template<typename T>
        void Stack<T>::push(T x)
        {
            try
            {
                Node<T> *p = new Node<T>;
                p->elem = x;
                p->next = s->next;
                s->next = p;
            }
            catch(bad_alloc & e)
            {
                cerr<<"Alloc Node error."<<endl;
                cerr<<"Error info:"<<e.what()<<endl;
            }

        }

    template<typename T>
        T Stack<T>::top()
        {
            return s->next->elem;
        }

};

namespace StackArray
{
    template<typename T>
        class Stack
        {
            public:
                Stack();
                Stack(int size);
                ~Stack();
                bool isEmpty();
                void makeEmpty();
                void push(T x);
                T top();
                T pop();

            private:
                enum{DEFAULT_SIZE=100000};
                int size;
                T *base;
                int index;
        };

    template<typename T>
        Stack<T>::Stack()try:size(DEFAULT_SIZE),base(new T[size]),index(-1)
        {

        }
    catch(bad_alloc &e)
    {
        cerr<<"Stack alloc Node error."<<endl;
        cerr<<"Error info:"<<e.what()<<endl;
    }

    template<typename T>
        Stack<T>::Stack(int size)try:size(size),base(new T[size]),index(-1)
        {

        }
    catch(bad_alloc &e)
    {
        cerr<<"Stack alloc Node error."<<endl;
        cerr<<"Error info:"<<e.what()<<endl;
    }

    template<typename T>
        Stack<T>::~Stack()
        {
            try
            {
                delete [] base;
                base=NULL;
                index=-1;
            }
            catch(bad_alloc &e)
            {
                cerr<<"List destruct error."<<endl;
            }
        }

    template<typename T>
        bool Stack<T>::isEmpty()
        {
            return index==-1;
        }

    template<typename T>
        void Stack<T>::makeEmpty()
        {
            index=-1;
        }

    template<typename T>
        void Stack<T>::push(T x)
        {
           if(index+1 == size)
           {
               cerr<<"The stack is full."<<endl;
           }
           base[++index]=x;
        }

    template<typename T>
        T Stack<T>::top()
        {
            if(index==-1)
            {
                cerr<<"The Stack has no data"<<endl;
            }
            return base[index];
        }

    template<typename T>
        T Stack<T>::pop()
        {
            if(index==-1)
            {
                cerr<<"The Stack has no data"<<endl;
            }

            return base[index--];
        }

};

