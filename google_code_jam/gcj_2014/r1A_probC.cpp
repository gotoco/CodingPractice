#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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

int magic_classifier(VI vi);

int bayes_classifier(VI vi); // TODO: implement finding bayes classifier

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
int tests;
    cin >> tests;

    REP(x, tests){
        int size; cin >> size;
        VI shuffle;
        REP(n, size){
            int input; cin >> input;
            shuffle.PB(input);
        }

        int good = magic_classifier(shuffle);
        cout << "Case #" << x+1 << ": ";
        if(good)
            cout << "GOOD " << endl;
        else
            cout << "BAD " << endl;

    }


    return 0;
}

int magic_classifier(VI vi)
{
    int result = 0;

    FOR(i, 0, vi.size())
        if(vi[i]<=i)
            result++;

    if(result > 486)
        return 1;
    else
        return 0;
}