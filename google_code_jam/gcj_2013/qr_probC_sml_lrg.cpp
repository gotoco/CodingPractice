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

//Try to use inline wherever is possible
#define _IL     inline

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

#define INF 99999999

_IL int sol(LL a, LL b);

int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);

    int TT; cin >> TT;

    REP(tt, TT){
        LL A, B;
        cin >> A; cin >> B;
        int s = sol(A, B);
        printf("Case #%d: %d\n", tt+1, s);
    }

    return 0;
}

/**
 * Check if it is palindrome?
 * -1 : no palindrome
 * 1 : is palindrome
 */
#define cache_s   294967296
static int _c[cache_s];

_IL int isP( LL n){
if( (n<cache_s) and (_c[(int)n] != 0) )
    return _c[(int)n];

    static int _f[1000];
    int size = 0;
    while(n > 0){
        _f[size++] = n%10;
        n /= 10;
    }
    int ans = 1;
    for(int i=0; i<size/2; i++)
        if(_f[i] != _f[size-i-1]){
            ans = -1;
            break;
        }
if(n<cache_s)
    _c[(int)n] = ans;

    return ans;
}

_IL int sol(LL A, LL B)
{
int ans = 0;

    LL i=0, I=0;
    i = (int) sqrt(A);
    if(i*i <A) i++;
    I = (int) sqrt(B);
    if(I*I <B) I++;

    for(int j=i; j<=I; j++){
        if(isP(j) == 1){
//cout << "## j isP " << j << endl;
            if(isP((LL)j*j) == 1 and (LL)j*j <= B){
//cout << "### j2 isP " << j*j << endl;
                ans ++;
//cout << "# sol++ = " << ans << endl;
            }
        }
    }

    return ans;
}
