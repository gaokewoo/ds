#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    ofstream f("./data.txt");

    srand( (unsigned)time( NULL ) ); 
    if(f.good())
    {
        for(int i=0;i<100000;i++)
        {
            int j = rand()%1000;
            f<<j<<" ";
        }
    }

    f.close();


    //ifstream in_file;
    //in_file.open("./data.txt",ios::in);
    //while(!in_file.eof())
    //{
    //    int j;
    //    in_file>>j;
    //    cout<<j<<endl;
    //}
    //in_file.close();

    return 0;
}
