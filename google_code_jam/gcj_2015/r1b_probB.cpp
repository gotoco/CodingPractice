#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <time.h>

using namespace std;

//Two of the most frequently used typical of long names, make life easier
typedef vector<int> VI;
typedef long long LL;

/* HEADERS */
// FOR - loop increasing 'x' from 'b' to 'e' inclusive
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
// FORD - loop decreasing 'x' from 'b' to 'e' inclusive
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
// REP - loop increasing 'x' from '0' to 'n'. Used to search and build DS
#define REP(x, n) for(int x = 0; x < (n); ++x)
// Clone long type of 'n'
#define VAR(v, n) __typeof(n) v = (n)
// ALL(c) represents the pair of iterators, indicating begin-end elements in the STL DS
#define ALL(c) (c).begin(), (c).end()
//Macro to get size of STL DS, used to avoid compilation warrning with int and uint comp
#define SIZE(x) ((int)(x).size())
// Very profitable macro aimed to iterate through all elements of STL DS
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
/* Shortcuts */
#define PB push_back
#define POP pop_back
#define ST first
#define ND second

int solution(int R, int C, int N);

int main()
{
    int tests;
    cin >> tests;

    REP(x, tests){

        int R, C, N; cin>>R; cin>>C; cin>>N;
        int result = solution(R, C, N);

        cout << "Case #" << x+1 << ": ";
        cout << result << endl;
    }


    return 0;
}

int solution(int R, int C, int N)
{
    int rc = R * C;

    if(N <= rc/2)
        return 0;

    int ** A = (int **)malloc(sizeof(int *)* R); //grid
    //FIRST DIM IS R
    for(int i=0; i<R; i++){
        A[i] = (int *)malloc(sizeof(int) * C);
    }

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            A[i][j] = 1;

    int result = 4*rc  - 2*(R - 2) - 2*(C - 2);
    int f = rc - N;

    if(R==2 || C==2){
        result -= f*2;
        return result;
    }

    for(int i=1; i <R-1; i++){
        for(int j=1; j<C-1; j++){
            if(A[i-1][j-1]==1 &&
                A[i+1][j+1]==1 &&
                A[i-1][j+1]==1 &&
                    A[i+1][j-1]==1){
                result -= 4;
                A[i][j] = 0;
            }
        }
    }


    for(int i=0; i<R; i++)
        free(A[i]);

    free(A);

    return result;
}