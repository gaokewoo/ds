#include <iostream>

using namespace std;

template <typename T> class List;

template <typename T>
class Node
{
    friend class List<T>;
    Node(const T &t):elem(t),next(0){}
    T elem;
    Node *next;
};

template <typename T>
class List
{
    public:
        List();
        ~List();
       void makeEmpty();
       bool isEmpty();
       bool isLast(Node<T> *p);
       Node<T> *find(T x);
       void del(T x);
       Node<T> *findPrev(T x);
       void insert(T x, Node<T> *p);
       void delList();
       T retrieve(Node<T> *p);

    private:
       Node<T> *head;
       Node<T> *tail;
};

template<typename T>
List<T>::List()
{

}

template<typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::makeEmpty()
{

    cout<<"I'm empty."<<endl;
}

template<typename T>
bool List<T>::isEmpty()
{

    return false;
}

template<typename T>
bool List<T>::isLast(Node<T> *p)
{

    return false;
}

template<typename T>
Node<T> * List<T>::find(T x)
{

    return NULL;
}

template<typename T>
void List<T>::del(T x)
{

}

template<typename T>
Node<T> * List<T>::findPrev(T x)
{

    return NULL;
}

template<typename T>
void List<T>::insert(T x, Node<T> *p)
{

}

template<typename T>
void List<T>::delList()
{

}

template<typename T>
T List<T>::retrieve(Node<T> *p)
{

    return T(1);
}


