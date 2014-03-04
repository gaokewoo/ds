#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "alg/BinaryTree.hh"
#include "alg/AVLTree.hh"

using namespace std;

class TreeTest:public testing::Test
{
    protected:

        virtual void SetUp()
        {
            arr = new int[DATA_NUM];
            ifstream in_file;
            in_file.open("../data/data.txt",ios::in);
            for(int k=0; !in_file.eof() && k<DATA_NUM; k++)
            {
                int j;
                in_file>>j;
                arr[k]=j;
            }
            in_file.close();

            arr_not_dup = new int[1000];
            in_file.open("../data/data3.txt",ios::in);
            for(int k=0; !in_file.eof() && k<1000; k++)
            {
                int j;
                in_file>>j;
                arr_not_dup[k]=j;
            }
            in_file.close();
        }

        virtual void TearDown()
        {
            delete [] arr;
            arr=NULL;
        }


    protected:
        enum {DATA_NUM = 100000};
        int * arr;
        int * arr_not_dup;
};

TEST_F(TreeTest,testBinaryTree) 
{
    using namespace BinaryTree;

    Tree<int> my_tree;

    for(int k=0; k<DATA_NUM; k++)
    {
        my_tree.ins(arr[k]);
    }
    //my_tree.printTree();

    for(int k=0; k<1000; k++)
    {
        my_tree.del(arr_not_dup[k]);
    }

}

TEST_F(TreeTest,testAVLTree) 
{
    using namespace AVLTree;

    Tree<int> my_tree;

    for(int k=0; k<DATA_NUM; k++)
    {
        my_tree.ins(arr[k]);
    }
    //my_tree.printTree();

    for(int k=0; k<1000; k++)
    {
        my_tree.del(arr_not_dup[k]);
    }

}

