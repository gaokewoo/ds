#include <iostream>
#include <sys/time.h>

using namespace std;

int MaxSubsequenceSum1(const int A[], int N)
{
    cout<<"....."<<__func__<<" Beg....."<<endl;
    struct timeval t_start,t_end; 

    gettimeofday(&t_start, NULL); 
    long start = ((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000; 

    int thisSum, maxSum, i, j, k;

    maxSum=0;
    for(i=0;i<N;i++)
      for(j=i;j<N;j++)
      {
          thisSum=0;
          for(k=i;k<j;k++)
          {
              thisSum+=A[k];
          }

          if(thisSum > maxSum)
            maxSum=thisSum;
      }

    gettimeofday(&t_end, NULL); 
    long end = ((long)t_end.tv_sec)*1000+(long)t_end.tv_usec/1000; 
    cout<<"Totally consume "<<end-start<<" ms"<<endl;
    cout<<"....."<<__func__<<" ("<<maxSum<<") End....."<<endl;

    return maxSum;
}

int MaxSubsequenceSum2(const int A[], int N)
{
    cout<<"....."<<__func__<<" Beg....."<<endl;
    struct timeval t_start,t_end; 

    gettimeofday(&t_start, NULL); 
    long start = ((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000; 

    int thisSum, maxSum, i, j;

    maxSum=0;
    for(i=0;i<N;i++)
    {
        thisSum=0;
        for(j=i;j<N;j++)
        {
            thisSum+=A[j];

            if(thisSum > maxSum)
              maxSum=thisSum;
        }
    }

    gettimeofday(&t_end, NULL); 
    long end = ((long)t_end.tv_sec)*1000+(long)t_end.tv_usec/1000; 
    cout<<"Totally consume "<<end-start<<" ms"<<endl;
    cout<<"....."<<__func__<<" ("<<maxSum<<") End....."<<endl;

    return maxSum;
}

int MaxSubsequenceSum3(const int A[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i;

    if(left == right)
    {
      if(A[left]>0)
        return A[left];
      else
        return 0;
    }

    center = (left+right)/2;
    maxLeftSum = MaxSubsequenceSum3(A,left,center);
    maxRightSum = MaxSubsequenceSum3(A,center+1,right);

    maxLeftBorderSum=leftBorderSum=0;
    for(i=center;i>=left;i--)
    {
        leftBorderSum+=A[i];
        if(leftBorderSum>maxLeftBorderSum)
          maxLeftBorderSum=leftBorderSum;
    }

    maxRightBorderSum=rightBorderSum=0;
    for(i=center+1;i<=right;i++)
    {
        rightBorderSum+=A[i];
        if(rightBorderSum>maxRightBorderSum)
          maxRightBorderSum=rightBorderSum;
    }

    int maxSum=0;
    if(maxLeftSum>maxRightSum && maxLeftSum>(maxLeftBorderSum+maxRightBorderSum))
      maxSum=maxLeftSum;
    else if(maxRightSum>maxLeftSum && maxRightSum>(maxLeftBorderSum+maxRightBorderSum))
      maxSum=maxRightSum;
    else
      maxSum=maxLeftBorderSum+maxRightBorderSum;

    return maxSum;
}

int MaxSubsequenceSum4(const int A[], int N)
{
    cout<<"....."<<__func__<<" Beg....."<<endl;
    struct timeval t_start,t_end; 

    gettimeofday(&t_start, NULL); 
    long start = ((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000; 

    int thisSum, maxSum, i;

    thisSum=maxSum=0;
    for(i=0;i<N;i++)
    {
        thisSum+=A[i];

        if(thisSum > maxSum)
          maxSum=thisSum;
        else if(thisSum < 0)
          thisSum=0;
    }

    gettimeofday(&t_end, NULL); 
    long end = ((long)t_end.tv_sec)*1000+(long)t_end.tv_usec/1000; 
    cout<<"Totally consume "<<end-start<<" ms"<<endl;
    cout<<"....."<<__func__<<" ("<<maxSum<<") End....."<<endl;

    return maxSum;
}

