#include <iostream>

using namespace std;

namespace BinaryTree
{
    template <typename T> class Tree;

    template <typename T>
        class Node
        {
            friend class Tree<T>;
            T elem;
            Node *left;
            Node *right;
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

    template <typename T>
        Tree<T>::Tree()
        {
            root=NULL;
        }

    template <typename T>
        Tree<T>::~Tree()
        {
            while(root!=NULL)
              del(root->elem);
        }

    template <typename T>
        Node<T> * Tree<T>::find(T x)
        {
            Node<T> * p = root;
            while(p!=NULL)
            {
                if(x > p->elem)
                  p = p->right;
                else if(x < p->elem)
                  p = p->left;
                else
                  break;
            }

            return p;
        }

    template <typename T>
        Node<T> * Tree<T>::findMin(Node<T> *p)
        {
            if (p!=NULL)
              while(p->left!=NULL)
              {
                  p=p->left;
              }

            return p;
        }

    template <typename T>
        Node<T> * Tree<T>::findMax(Node<T> *p)
        {
            if (p!=NULL)
              while(p->right!=NULL)
              {
                  p=p->right;
              }

            return p;
        }

    template <typename T>
        void Tree<T>::ins(T x)
        {
            root = ins(root,x);
        }

    template <typename T>
        Node<T> * Tree<T>::ins(Node<T> * t,T x)
        {
            try
            {
                if ( t == NULL)
                {
                    t = new Node<T>;
                    t->elem = x;
                    t->right = t->left = NULL;
                }
                else if(x < t->elem)
                {
                    t->left=ins(t->left,x);
                }
                else if(x > t->elem)
                {
                    t->right=ins(t->right,x);
                }

                return t;
            }
            catch(bad_alloc &e)
            {
                cerr<<"Alloc memory error."<<endl;
                cerr<<e.what()<<endl;
            }

        }

    template <typename T>
        void Tree<T>::del(T x)
        {
            root = del(root,x);
        }

    template <typename T>
        Node<T> * Tree<T>::del(Node<T> * t,T x)
        {
            try
            {
                if ( t == NULL)
                {
                    cerr<<"The tree is empty, can't delete "<<x<<endl;

                    return NULL;
                }
                else if(x < t->elem)
                {
                    t->left=del(t->left,x);
                }
                else if(x > t->elem)
                {
                    t->right=del(t->right,x);
                }
                else if(t->left && t->right) //has two children
                {
                    Node<T> * tmp = findMin(t->right);
                    t->elem = tmp->elem;
                    t->right = del(t->right,t->elem);
                }
                else //has one or zero children
                {
                    Node<T> * tmp = t;
                    if(t->left == NULL) //also handles 0 children
                    {
                        t = t->right;
                    }
                    else if(t->right == NULL)
                    {
                        t = t->left;
                    }

                    cout<<"Delete:"<<tmp->elem<<endl;
                    delete tmp;

                }

                return t;
            }
            catch(bad_alloc &e)
            {
                cerr<<"Alloc memory error."<<endl;
                cerr<<e.what()<<endl;
            }

        }

    template <typename T>
        void Tree<T>::printTree()
        {
            print(root);
        }

    template <typename T>
        void Tree<T>::print(Node<T> *t)
        {
            if(t!=NULL)
            {
                print(t->left);
                cout<<t->elem<<",";
                print(t->right);
            }
        }

};

