#include <fstream>
#include "gtest/gtest.h"
#include "alg/Queue.hh"

class QueueTest:public testing::Test
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

TEST_F(QueueTest,testQueueList)
{
    using namespace QueueList;
    Queue<int> my_queue;

    for(int k=0; k<DATA_NUM; k++)
    {
        my_queue.enQueue(arr[k]);
    }

    int sum=0,k=0;
    bool not_equal=false;
    while(!my_queue.isEmpty())
    {
        sum++; //compute element number
        int e = my_queue.deQueue();
        if(arr[k]!=e)
        {
            not_equal=true;
            break;
        }

        k++;
    }

    ASSERT_TRUE(not_equal == false);

    EXPECT_EQ(DATA_NUM, sum);
}

TEST_F(QueueTest,testQueueArray_Construct)
{
    using namespace QueueArray;
    Queue<int> my_queue;

    int cap = my_queue.getCapacity();

    EXPECT_EQ(cap, 0);

    bool isFull = my_queue.isFull();

    EXPECT_FALSE(isFull);

    bool isEmpty = my_queue.isEmpty();

    EXPECT_TRUE(isEmpty);
}

TEST_F(QueueTest,testQueueArray_enQueue)
{
    using namespace QueueArray;
    Queue<int> my_queue(3);

    my_queue.enQueue(1);
    my_queue.enQueue(2);
    my_queue.enQueue(3);

    int cap = my_queue.getCapacity();

    EXPECT_EQ(cap, 3);

    bool isFull = my_queue.isFull();

    EXPECT_TRUE(isFull);

    bool isEmpty = my_queue.isEmpty();

    EXPECT_FALSE(isEmpty);
}

TEST_F(QueueTest,testQueueArray_deQueue)
{
    using namespace QueueArray;
    Queue<int> my_queue(3);

    my_queue.enQueue(1);
    my_queue.deQueue();
    my_queue.enQueue(2);
    my_queue.deQueue();
    my_queue.enQueue(3);
    my_queue.deQueue();
    my_queue.enQueue(4);
    int e = my_queue.deQueue();
    EXPECT_EQ(e, 4);

    int cap = my_queue.getCapacity();

    EXPECT_EQ(cap, 0);

    bool isFull = my_queue.isFull();

    EXPECT_FALSE(isFull);

    bool isEmpty = my_queue.isEmpty();

    EXPECT_TRUE(isEmpty);
}

