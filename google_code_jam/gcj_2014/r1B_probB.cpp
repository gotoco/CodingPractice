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
#define ST first
#define ND second

unsigned long dynamic_pp_solution(unsigned int a, unsigned int b, unsigned int k);
unsigned long brute_force(unsigned int a, unsigned int b, unsigned int k);

long count_pairs(long i, long lessA, long lessB, long lessK, long A, long B, long K);
int xSize = sizeof(long);
int ySize = sizeof(long);
int offset( int x, int y, int z ) { return ( z * xSize * ySize ) + ( y * xSize ) + x ; }

int main() {


    int tt; cin >> tt;

    REP(c, tt){

        unsigned int a, b, k; cin >> a; cin >> b; cin>>k;
        cout << "Case #" << c+1 << ": " ;

        long t1 = time(NULL) ;
        unsigned long result = dynamic_pp_solution(a, b, k);


        long t2 = time(NULL) ;

        cout
                << " dt = " << t2-t1 << "  r:  "
                <<result << endl;

    }

}

unsigned long brute_force(unsigned int a, unsigned int b, unsigned int k)
{
    unsigned int result = 0;
    for(int i=0 ; i<a; i++){
        int row = 0;
        for(int j=0; j<b; j++){
            if((j & i) < k) {
                result++; row++;
            }
        }
    }

    return result;
}
long dp_cache[32][2][2][2];

void clear_cache(){
    for(int i=0; i<32; i++){
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                for(int l=0; l<2; l++)
                    dp_cache[i][j][k][l] = -1;
    }
}

unsigned long dynamic_pp_solution(unsigned int a, unsigned int b, unsigned int k)
{
    unsigned int max = std::max(a, b);
    max = std::max(max, k);

    long i_bytes = 0;
    int kk = max;
    while(kk > 0){
        kk /= 2; i_bytes++;
    }
    clear_cache();

    return count_pairs(i_bytes, 0, 0, 0, a, b, k);
}

inline long getBit(long num, long i) { return (num >> i) & 1; }

long count_pairs(long i, long lessA, long lessB, long lessK, long A, long B, long K)
{
    if(i == -1)
        return (lessA && lessB && lessK);

//    if(dp_cache[i][lessA][lessB][lessK] != -1)
//        return dp_cache[i][lessA][lessB][lessK];

    long count = 0;
    long maxA = lessA || getBit(A, i) == 1;
    long maxB = lessB || getBit(B, i) == 1;
    long maxK = lessK || getBit(K, i) == 1;

    //use calue 0 for a, b and k with is always possible
    count = count_pairs(i-1, maxA, maxB, maxK, A, B, K);

    if(maxA){
        count += count_pairs(i-1, lessA, maxB, maxK, A, B, K);
    }

    if(maxB){
        count += count_pairs(i-1, maxA, lessB, maxK, A, B, K);
    }

    if(maxK && maxA && maxB){
        count += count_pairs(i-1, lessA, lessB, lessK, A, B, K);
    }

    dp_cache[i][lessA][lessB][lessK] = count;

    return count;
}