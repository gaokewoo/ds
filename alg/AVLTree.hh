#include <iostream>

using namespace std;

namespace AVLTree
{
    template <typename T> class Tree;

    template <typename T>
        class Node
        {
            friend class Tree<T>;
            T elem;
            int height;
            Node<T> *left;
            Node<T> *right;
        };

    template <typename T>
        class Tree
        {
            public:
                Tree();
                ~Tree();
                Node<T> * find(T x);
                Node<T> * findMin(Node<T> *p);
                Node<T> * findMax(Node<T> *p);
                void ins(T x);
                Node<T> * ins(Node<T> * t,T x);
                void del(T x);
                Node<T> * del(Node<T> * t,T x);
                T retrieve(Node<T> * p);
                void printTree();
                void print(Node<T> *t);

            private:
                Node<T> *root;
        };

}
