#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "alg/Sort.hh"

using namespace std;

int main()
{
    const int DATA_NUM = 100000;
    //ofstream f("./data.txt");

    //srand( (unsigned)time( NULL ) ); 
    //if(f.good())
    //{
    //    for(int i=0;i<DATA_NUM;i++)
    //    {
    //        int j = rand()%1000;
    //        f<<j<<" ";
    //    }
    //}

    //f.close();


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
    st.doSort(arr);

    delete[] arr;

    return 0;
}
