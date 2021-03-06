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
void print(long long x) {
    while (x) {
        printf("%lld", x % 2);
        x /= 2;
    }
}

bool check(long long x) {
    for (int i = 2; i <= 10; i++) {
        bool ok = false;
        for (int j = 2; j <= 100; j++) {
            long long x1 = x;
            int v = 0;
            while (x1 > 0) {
                v = (v * i + x1 % 2) % j;
                x1 /= 2;
            }
            if (!v) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    print(x);
    for (int i = 2; i <= 10; i++) {
        bool ok = false;
        for (int j = 2; j <= 1000; j++) {
            long long x1 = x;
            int v = 0;
            while (x1 > 0) {
                v = (v * i + x1 % 2) % j;
                x1 /= 2;
            }
            if (!v) {
                printf(" %d", j);
                ok = true;
                break;
            }
        }
    }
    printf("\n");
    return true;
}

int main() {
    freopen("in",  "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);
    printf("Case #1:\n");
    int N, J;
    scanf("%*d%d%d", &N, &J);

    sol(N, J);
}

_ilv sol(int N, int J)
{
    for (long long i = (1LL << (N - 1)) + 1; cnt < J ;i += 2) {
         if (check(i))
             cnt += 1;
     }
}
