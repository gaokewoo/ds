#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "alg/Stack.hh"

using namespace std;

class StackTest:public testing::Test
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

TEST_F(StackTest,testStackList) 
{
    using namespace StackList;

    Stack<int> my_stack;

    for(int k=0; k<DATA_NUM; k++)
    {
        my_stack.push(arr[k]);
    }

    int sum=0,k=DATA_NUM-1;
    bool not_equal=false;
    while(!my_stack.isEmpty())
    {
        sum++; //compute element number
        if(arr[k]!=my_stack.pop()) //compare the list value equal the arr value
        {
            not_equal=true;
            break;
        }

        k--;
    }

    ASSERT_TRUE(not_equal == false);

    EXPECT_EQ(DATA_NUM, sum);
}

TEST_F(StackTest,testStackArray) 
{
    using namespace StackArray;

    Stack<int> my_stack;

    for(int k=0; k<DATA_NUM; k++)
    {
        my_stack.push(arr[k]);
    }

    int sum=0,k=DATA_NUM-1;
    bool not_equal=false;
    while(!my_stack.isEmpty())
    {
        sum++; //compute element number
        int e = my_stack.pop();
        if(arr[k]!=e) //compare the list value equal the arr value
        {
            cerr<<"Expect:"<<arr[k]<<" Actual:"<<e<<endl;
            not_equal=true;
            break;
        }

        k--;
    }

    ASSERT_TRUE(not_equal == false);

    EXPECT_EQ(DATA_NUM, sum);
}

