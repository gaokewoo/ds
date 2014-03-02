#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "alg/BinaryTree.hh"

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
        }

        virtual void TearDown()
        {
            delete [] arr;
            arr=NULL;
        }


    protected:
        enum {DATA_NUM = 100000};
        int * arr;
};

TEST_F(TreeTest,testBinaryTree) 
{
    using namespace BinaryTree;

    Tree<int> my_tree;

    for(int k=0; k<DATA_NUM; k++)
    {
        my_tree.ins(arr[k]);
    }

    for(int k=0; k<DATA_NUM; k++)
    {
        my_tree.del(arr[k]);
    }

}

