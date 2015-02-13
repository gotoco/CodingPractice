/*
Given an array A of N integers, we draw N discs in a 2D plane such that the I-th disc is centered on (0,I)
and has a radius of A[I].
We say that the J-th disc and K-th disc intersect if J ≠ K and J-th and K-th discs have at least one common point.
Write a function:
int solution(int A[], int N);
that, given an array A describing N discs as explained above, returns the number of pairs of intersecting discs. For example, given N=6 and:
A[0] = 1  A[1] = 5  A[2] = 2
A[3] = 1  A[4] = 4  A[5] = 0
intersecting discs appear in eleven pairs of elements:
0 and 1,
0 and 2,
0 and 4,
1 and 2,
1 and 3,
1 and 4,
1 and 5,
2 and 3,
2 and 4,
3 and 4,
4 and 5.
so the function should return 11.
The function should return −1 if the number of intersecting pairs exceeds 10,000,000.
Assume that:
N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2147483647].
Complexity:
expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
 */
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);
int example();

int main() {
    example();
    return 0;
}

int example(){
    std::vector<int> v = {1, 5, 2, 1, 4, 0};
                   //r = {0, 1, 0, 0, 2, 2
                   //l = {3, 0, 1, 0, 0, 0
    // 1: R-3 , C-3
    // 2: R-



    cout << "Solution for example should return 11 : " << solution(v);

    return 0;
}

int solution(vector<int> &A) {
    unsigned int N = A.size();

    unsigned int * left = (unsigned int *)calloc(N, sizeof(unsigned int));
    unsigned int * right = (unsigned int *)calloc(N, sizeof(unsigned int));
    long total = 0;

    for(int i=0; i<N; i++){
        left[max(0, i-A[i])]++;
        right[(int)min((long)(N-1), (long)(i+A[i]) )]++;
    }
    long cnt = 0;
    for(int i=0; i<N; i++){

        if(left[i]>0){
            total+=left[i]*cnt;
            total+=left[i]*(left[i]-1)/2;
            cnt+=left[i];
        }

        cnt-=right[i];

        if (total > 1e7) {
            return -1;
        }
    }

    return (int)total;
}
