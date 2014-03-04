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

                int height(Node<T> *p);
                int max(int a,int b){ return a>b?a:b; }
                Node<T> * singleRotateWithLeft(Node<T> * k2);
                Node<T> * doubleRotateWithLeft(Node<T> * k3);
                Node<T> * singleRotateWithRight(Node<T> * k2);
                Node<T> * doubleRotateWithRight(Node<T> * k3);

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
                    t->height = 0;
                    t->right = t->left = NULL;
                }
                else if(x < t->elem)
                {
                    t->left=ins(t->left,x);
                    if(height(t->left) - height(t->right) == 2)
                    {
                      if(x < t->left->elem)
                        t = singleRotateWithLeft(t);
                      else
                        t = doubleRotateWithLeft(t);
                    }
                }
                else if(x > t->elem)
                {
                    t->right=ins(t->right,x);
                    if(height(t->right) - height(t->left) == 2)
                    {
                      if(x > t->right->elem)
                        t = singleRotateWithRight(t);
                      else
                        t = doubleRotateWithRight(t);
                    }
                }
                
                t->height = max(height(t->left),height(t->right)) + 1;
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

    template <typename T>
        int Tree<T>::height(Node<T> *p)
        {
            if(p==NULL)
              return -1;
            else
              return p->height;
        }

    template <typename T>
        Node<T> * Tree<T>::singleRotateWithLeft(Node<T> * k2)
        {
            Node<T> * k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;

            k2->height = max(height(k2->left),height(k2->right)) + 1;
            k1->height = max(height(k1->left),height(k1->right)) + 1;

            return k1;
        }
    
    template <typename T>
        Node<T> * Tree<T>::doubleRotateWithLeft(Node<T> * k3)
        {
            k3->left = singleRotateWithRight(k3->left);

            return singleRotateWithLeft(k3);
        }

    template <typename T>
        Node<T> * Tree<T>::singleRotateWithRight(Node<T> * k2)
        {
            Node<T> * k1 = k2->right;
            k2->right= k1->left;
            k1->left= k2;

            k2->height = max(height(k2->left),height(k2->right)) + 1;
            k1->height = max(height(k1->left),height(k1->right)) + 1;

            return k1;
        }

    template <typename T>
        Node<T> * Tree<T>::doubleRotateWithRight(Node<T> * k3)
        {
            k3->right = singleRotateWithLeft(k3->right);

            return singleRotateWithRight(k3);
        }
}
