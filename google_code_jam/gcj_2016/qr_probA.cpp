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

/* Shortcuts for vectors*/
#define PB push_back
#define POP pop_back
#define ST first
#define ND second

#define RM( v, x )  v.erase(v.begin() + x)
#define PF( v, x )  v.insert(v.begin(), x);

#define FIND(v, x)  find(v.begin(), v.end(), x)
#define Vit         std::vector<int>::iterator

#define INF 99999999
#define _IL     inline
#define _ili    inline int
#define _ilv    inline void

#define IN     "A-large.in" // "sample.in"
#define OUT     "sample.out"
#define ERR     "sample.err"

_ilv sol(int tc, int N);
_IL VI amnog(int N, int s);

void print_v(VI v){
fprintf(stderr, "vec:: ");
    for(int i=0; i<v.size(); i++)
        fprintf(stderr, "%d, ", v[i]);
fprintf(stderr, "\n");
}

int main(){
    //sample
    freopen(IN,  "r", stdin);
    freopen(OUT, "w", stdout);
    freopen(ERR, "w", stderr);

    int TT; cin >> TT;

    REP(tt, TT){
        int N;
        cin >> N;

        sol(tt+1, N);
    }

    return 0;
}

int _C[10];

_ilv sol(int tc, int N)
{
    FOR(x, 0, 9)
        _C[x] = 0;

    if(N == 0){
        printf("Case #%d: INSOMNIA\n", tc);
        return;
    }

    VI r;
    int n = 1;
    for(int i=1; i<INT_MAX; i++){
        r = amnog(N, i);
        if(r.size() > 0){
            printf("Case #%d: ", tc);
            for(int j=r.size()-1; j>=0; j--)
                printf("%d", r[j]);
            printf("\n");
            return;
        }
    }

    printf("Case #%d: INSOMNIA\n", tc);
}

_IL VI amnog(int N, int s)
{
    VI a;
    int n = N;
    while(n > 0){
        a.PB(n%10);
        n /= 10;
    }
    int r;
    int carry = 0;
    for(int i=0; i<a.size(); i++){
        r = a[i]*s;
        a[i] = r + carry;
        carry = a[i]/10;
        a[i] = a[i]%10;
        _C[ a[i] ]++;
    }
    if(carry > 0){
        while(carry > 0){
            a.PB(carry%10);
            _C[carry%10]++;
            carry /= 10;
        }
    }
    int i=0;
    FOR(x, 0, 9)
        if(_C[x] > 0)
            i++;
    if(i>=10)
        return a;
    VI b;
    return b;
}
