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

_ilv sol(int tc, int N);
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
        int N;// and more
        cin >> N;

        sol(tt+1, N); //run sol
    }

    return 0;
}

_ili sol_cycle(int N, VI g){
    int v[1002];
    FOR(i, 0, 1001) v[i] = 0;
    int ans = 0;
    FOR(i, 1, N){
        int depth = 0;
        int pv = i;
        REP(j, 2*N){
            if(v[pv] == 0){
                depth++;
                v[pv] = 1;
                pv = g[pv];
            } else if(pv==i){
                ans = max(ans, depth);
                break;
            }
        }
        FOR(i, 0, 1002) v[i] = 0;
    }
    return ans;
}

_ili sol_chain(int N, VI g){
    int v[1002]; int d[1002];
    FOR(i, 0, 1001) v[i] = d[i] = 0;
    int ans = 0;
    FOR(i, 1, N){
            int pv = i;
            FOR(depth,0,2*N){
                    if(g[g[pv]]==pv and depth == 0){
                        d[pv] = max (1, d[pv]);
                        break;
                    }
                    if(g[g[pv]] == pv){
                        d[pv] = max(d[pv], depth+1);
                        break;
                    }
                pv = g[pv];
            }
    }
    for(int i=1; i<=N; i++)
        ans += d[i];

    return ans;
}

_ilv sol(int tc, int N )
{
    //do work
    VI v(N+1);
    FOR(i, 1, N){
        int bff; cin >> bff;
        v[i] = bff;
    }
    print_v(v);
    int ans = 0;
    int ans1 = sol_cycle(N, v);
//    fprintf(stderr, "ans1 -> %d \n", ans1);
    ans = max(ans, ans1 );
    int ans2 = sol_chain(N, v);
//    fprintf(stderr, "ans2 -> %d \n", ans2);
    ans = max(ans, ans2 );

    printf("Case #%d: %d\n", tc, ans);
}
