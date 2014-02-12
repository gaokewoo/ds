#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "alg/Sort.hh"

using namespace std;

const int DATA_NUM = 100000;
const int NEG_POS_DATA_NUM = 30;

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

    Sort st;
    st.doSort(arr, NEG_POS_DATA_NUM);

    delete[] arr;
}

int main()
{
    genGneralData();
    testGeneralData();

    genNegPosData();
    testNegPosData();

    return 0;
}
