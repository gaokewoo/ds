#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "alg/List.hh"

using namespace std;

class ListTest:public testing::Test
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

TEST_F(ListTest,assign) 
{
    List<int> my_list;

    for(int k=0; k<DATA_NUM; k++)
    {
        my_list.insert(arr[k]);
    }

    int sum=0,k=DATA_NUM-1;
    Node<int> *p = my_list.getFirst();
    bool not_equal=false;
    while(p!=NULL)
    {
        sum++; //compute element number
        if(arr[k]!=my_list.retrieve(p)) //compare the list value equal the arr value
        {
            not_equal=true;
            break;
        }

        my_list.del(my_list.retrieve(p));
        p=my_list.getNext(p);
        k--;
    }

    ASSERT_TRUE(not_equal == false);

    EXPECT_EQ(DATA_NUM, sum);
}

