#include "Sort.hh"

void Sort::doSort(int * arr, int dataNum)
{
    cout<<"....."<<__func__<<" Beg....."<<endl;
    time_t t_beg = time(0); 
    for(int i=0;i<dataNum;i++)
    {
        cout<<arr[i]<<endl;
    }
    time_t t_end = time(0); 
    cout<<"Totally consume "<<t_end-t_beg<<" seconds"<<endl;
    cout<<"....."<<__func__<<" End....."<<endl;
}
