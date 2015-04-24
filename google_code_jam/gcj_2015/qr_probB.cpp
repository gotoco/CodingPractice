#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <strings.h>
#include <math.h>

//#include <ctime.h>
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
#define ST first()
#define ND second()
#define LT back()

#define P_V_B     1001
#define P_V     1000

unsigned int p_numb [P_V_B];

inline void clean(){
    FOR(i, 0, P_V)
        p_numb[i] = 0;
}

//Get the minimum possible breakfast end time, given
// P[i] is the number of panckes of diner i initially
int f(const vector<int>& P)
{
    const int max_pancakes = *max_element(P.begin(), P.end());
    int ret = max_pancakes;

    for(int x = 1; x < max_pancakes; ++x){
        int total_moves = 0;
        for(const int Pi : P) {
            // (Pi - 1) / x is equivalent to M(Pi),
            // which is ceil(Pi / x) - 1
            total_moves += (Pi - 1) / x;
        }
        ret = min(ret, total_moves + x);
    }
    return ret;
}

int main(){

//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);

    int TT; cin>>TT;

    REP(x, TT){
        clean();
        int plates;
        cin >> plates;
        VI vi;
        REP(i, plates){
            unsigned int c;
            cin >> c;
            p_numb[i]=c;
            vi.PB(c);
        }
//        int t = f(vi);
    std:sort(p_numb, p_numb+plates, std::greater<int>());
    int m = p_numb[0];
    int t = INFINITY;

    FOR(r, 1, m) {
        int move = 0;
        for (int i = 0; i < plates; i++) {
            if (p_numb[i] <= r) break;
            move += std::ceil((double) p_numb[i] / r - 1);
        }
        if (move + r < t)
            t = move + r;
    }
        cout << "Case #" <<  x+  1 <<": ";
        cout << t << endl;
    }

}


