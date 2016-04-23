//no comment needed
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include <map>
#include <climits>
using namespace std;

//Two of the most frequently used typical of long names, make life easier
typedef vector<int> VI;
typedef long long LL;

/* HEADERS */

/* Loops */
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

/* Shortcuts for vectors most common use cases*/
#define PB push_back
#define POP pop_back
#define ST first
#define ND second
#define RM( v, x )  v.erase(v.begin() + x)
#define PF( v, x )  v.insert(v.begin(), x);
#define FIND(v, x)  find(v.begin(), v.end(), x)
#define Vit         std::vector<int>::iterator

/* some other usefull methods */
#define INF     INT_MAX/2-256
#define _il     inline
#define _ili    inline int
#define _ilv    inline void

#define IN      "sample.in"
#define OUT     "sample.out"
#define ERR     "sample.err"

_ilv sol(int tc, int N, int J);
//debug print
void print_v(VI v){
fprintf(stderr, "vec:: ");
    FOREACH(it, v)
        fprintf(stderr, "%d, ", *it);
fprintf(stderr, "\n");
}

int main(){
    //sample
    freopen(IN,  "r", stdin);
    freopen(OUT, "w", stdout);
    freopen(ERR, "w", stderr);

    int TT; cin >> TT;

    REP(tt, TT){
        int N, J;// and more
        cin >> N; cin >> J;

        sol(tt+1, N, J); //run sol
    }

    return 0;
}

long long convertBinaryToBase(int x, int base) {
    if (x == 0)
        return 0;
    return base * convertBinaryToBase(x / 2, base) + (x % 2);
}

long long findFactor(long long k) {
    for (long long d = 2; d * d <= k; d++)
        if (k % d == 0)
            return d;
    return 0;
}

_ilv sol(int tc, int N, int J)
{
    //do work
    printf("Case #%d: \n", tc);
    for (long long i = (1 << N-1) + 1; J > 0; i += 2) {
        vector<long long> factors;
        for (int base = 2; base <= 10; base++) {
            long long x = convertBinaryToBase(i, base);
            long long factor = findFactor(x);
            if (!factor)
                break;
            factors.push_back(factor);
        }
        if (factors.size() < 9)
            continue;

        cout << convertBinaryToBase(i, 10);
        for (long long factor : factors)
            cout << " " << factor;
        cout << endl;
        J -= 1;
    }

}
