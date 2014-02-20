#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "alg/Sort.hh"
#include "alg/Subsequence.hh"
#include "alg/List.hh"
#include "alg/Stack.hh"

using namespace std;

const int DATA_NUM = 100000;
const int NEG_POS_DATA_NUM = 5000;

int * readData(int *arr, int num)
{
    ifstream in_file;
    in_file.open("./data.txt",ios::in);
    for(int k=0; !in_file.eof() && k<num; k++)
    {
        int j;
        in_file>>j;
        arr[k]=j;
    }
    in_file.close();

    return arr;
}

void genGneralData()
{
    ofstream f("./data.txt");

    srand( (unsigned)time( NULL ) ); 
    if(f.good())
    {
        for(int i=0;i<DATA_NUM;i++)
        {
            int j = rand()%1000;
            f<<j<<" ";
        }
    }

    f.close();
}

void testGeneralData()
{
    int *arr=new int[DATA_NUM];
    ifstream in_file;
    in_file.open("./data.txt",ios::in);
    for(int k=0; !in_file.eof() && k<DATA_NUM; k++)
    {
        int j;
        in_file>>j;
        arr[k]=j;
    }
    in_file.close();

    Sort st;
    st.doSort(arr, DATA_NUM);

    delete[] arr;

}

void genNegPosData()
{
    ofstream f("./data2.txt");

    srand( (unsigned)time( NULL ) ); 
    if(f.good())
    {
        for(int i=0;i<NEG_POS_DATA_NUM;i++)
        {
            int j = rand()%1000;
            if(rand()%10%2==0) j=-j;
            f<<j<<" ";
        }
    }

    f.close();

}

void testNegPosData()
{
    int *arr=new int[NEG_POS_DATA_NUM];
    ifstream in_file;
    in_file.open("./data2.txt",ios::in);
    for(int k=0; !in_file.eof() && k<NEG_POS_DATA_NUM; k++)
    {
        int j;
        in_file>>j;
        arr[k]=j;
    }
    in_file.close();

    //N^3
    Subsequence::MaxSubsequenceSum1(arr,NEG_POS_DATA_NUM);
    //N^2
    Subsequence::MaxSubsequenceSum2(arr,NEG_POS_DATA_NUM);

    cout<<"..... MaxSubsequenceSum3 Beg....."<<endl;
    struct timeval t_start,t_end; 

    gettimeofday(&t_start, NULL); 
    long start = ((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000; 

    //NlogN
    int maxSum = Subsequence::MaxSubsequenceSum3(arr,0,NEG_POS_DATA_NUM-1);

    gettimeofday(&t_end, NULL); 
    long end = ((long)t_end.tv_sec)*1000+(long)t_end.tv_usec/1000; 
    cout<<"Totally consume "<<end-start<<" ms"<<endl;
    cout<<"..... MaxSubsequenceSum3 ("<<maxSum<<") End....."<<endl;

    //N
    Subsequence::MaxSubsequenceSum4(arr,NEG_POS_DATA_NUM);
    delete[] arr;
}

void testList()
{
    List<int> my_list;
    
    cout<<"My List is empty:"<<my_list.isEmpty()<<endl;

    int *arr=new int[DATA_NUM];
    readData(arr,DATA_NUM);

    for(int k=0; k<DATA_NUM; k++)
    {
        my_list.insert(arr[k]);
    }

    int sum=0,k=DATA_NUM-1;
    Node<int> *p = my_list.getFirst();
    while(p!=NULL)
    {
        sum++;
        cout<<sum<<":"<<my_list.retrieve(p)<<endl;
        if(arr[k]!=my_list.retrieve(p)) //compare the list value equal the arr value
        {
          cerr<<"arr["<<k<<"]="<<arr[k]<<" list elem="<<my_list.retrieve(p)<<endl;
          break;
        }

        my_list.del(my_list.retrieve(p));
        p=my_list.getNext(p);
        k--;
    }

    cout<<"In sum:"<<sum<<endl;
    
}

int main()
{
    //genGneralData();
    //testGeneralData();

    //genNegPosData();
    //testNegPosData();

    //testList();
    
    using namespace StackList;
    Stack<int> stack;
    stack.isEmpty();

    return 0;
}
