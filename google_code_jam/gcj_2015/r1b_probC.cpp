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

int solution(vector <group> vg);

struct group{
    int p; //position
    int n; //numbers
    int s; //speed
};

int main()
{
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int tests;
    cin >> tests;

    REP(x, tests){
        vector <group> vg;
        int number; cin>>number;
        REP(n, number){
            struct group g;
            cin >> g.p;
            cin >> g.n;
            cin >> g.s;
            vg.PB(g);
        }

        int result = solution(vg);
        cout << "Case #" << x+1 << ": ";
        cout << result << endl;
    }


    return 0;
}

int solution(vector <group> vg)
{

}