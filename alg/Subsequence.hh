#include <iostream>
#include <sys/time.h>

using namespace std;

class Subsequence
{
    public:
        static int MaxSubsequenceSum1(const int A[], int N); //N^3
        static int MaxSubsequenceSum2(const int A[], int N); //N^2
        static int MaxSubsequenceSum3(const int A[], int left, int right); //NlogN
        static int MaxSubsequenceSum4(const int A[], int N); //N
};

