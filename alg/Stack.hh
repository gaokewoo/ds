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
        void pop();

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
bool Stack<T>::isEmpty()
{
    cout<<"I'm empty"<<endl;
    return true;
}

template<typename T>
void Stack<T>::makeEmpty()
{

}

template<typename T>
void Stack<T>::push(T x)
{

}

template<typename T>
T Stack<T>::top()
{
    return T(0);
}

template<typename T>
void Stack<T>::pop()
{

}

}
