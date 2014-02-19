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
       void insert(T x);
       void delList();
       Node<T> *getFirst();
       Node<T> *getNext(Node<T> *p);
       T retrieve(Node<T> *p);

    private:
       Node<T> *list;
};

template<typename T>
List<T>::List()try:list(new Node<T>(0))
{
    list->next=NULL;
    cout<<"List constructor."<<endl;
}
catch(bad_alloc & err)
{
    cerr<<"List alloc Node error."<<endl;
    cerr<<"Error info:"<<err.what()<<endl;
}

template<typename T>
List<T>::~List()
{
    try
    {
        makeEmpty();
        delete list;
        list=NULL;
        cout<<"List destructor."<<endl;
    }
    catch(...)
    {
        cerr<<"List destruct error."<<endl;
    }
}

template<typename T>
void List<T>::makeEmpty()
{
    delList();
    cout<<"I'm empty."<<endl;
}

template<typename T>
bool List<T>::isEmpty()
{
    return list->next == NULL;
}

template<typename T>
bool List<T>::isLast(Node<T> *p)
{
    return p->next == NULL;
}

template<typename T>
Node<T> * List<T>::findPrev(T x)
{
    Node<T> *p;
    p=list;
    while(p->next!=NULL && p->next->elem != x)
    {
        p=p->next;
    }

    return p;
}

template<typename T>
Node<T> * List<T>::find(T x)
{
    Node<T> *p = findPrev(x);

    return p->next;
}

template<typename T>
void List<T>::del(T x)
{
    Node<T> *p = findPrev(x);
    if(p!=NULL)
    {
        Node<T> *tmp = p->next;
        p->next=tmp->next;
        delete tmp;
    }
}

template<typename T>
void List<T>::insert(T x, Node<T> *p)
{
    try
    {
        Node<T> *tmp = new Node<T>(0);
        tmp->elem=x;
        tmp->next=p->next;
        p->next=tmp;
    }
    catch(bad_alloc & err)
    {
        cerr<<"insert error."<<endl;
        throw;
    }
}

template<typename T>
void List<T>::insert(T x)
{
    insert(x,list);
}

template<typename T>
void List<T>::delList()
{
    while(list->next != NULL)
    {
        Node<T> *tmp = list->next;
        del(tmp->elem);
    }
}

template<typename T>
Node<T>* List<T>::getFirst()
{
    return list->next;
}

template<typename T>
Node<T>* List<T>::getNext(Node<T> *p)
{
    return p=p->next;
}

template<typename T>
T List<T>::retrieve(Node<T> *p)
{
    return p->elem;
}

