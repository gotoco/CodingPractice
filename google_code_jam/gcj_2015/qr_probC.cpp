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

#define _1  1
#define _I  2
#define _J  3
#define _K  4

int const quater[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1,  _I,  _J,  _K,},
        {0, _I, -1,  _K,  -_J,},
        {0, _J, -_K, -1,  _I,},
        {0, _K, _J,  -_I, -1,},
};

struct R {
    int result;
    int contain;  //If sequence contain after reduces ijk -in binary -> 0 0 0
};                  // 1 contain i, 2 contain ij, 3 contain ijk

//cached result for function
R static cache [2][4][5];

inline void clear_cache(){
    for(int i=0; i<2; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<5; k++){
                cache[i][j][k].result = 0;
                cache[i][j][k].contain = -1;
            }

}

R search_and_multiply(int seed, string part, int search);



inline int multiply(int i, int j){

    if(i > 4 || i < -4 || j > 4 || j<-4){
        cout << "## ERR:  i=" << i << "  j=" << j << endl;
        throw std::invalid_argument( "received invalid value value" );
    }


    int sgn;
    sgn = i*j<0 ? -1 : 1;

    int result = quater[abs(i)][abs(j)];

    return sgn * result;
}

inline int transform(char a){
    int r = a-48;

    if(r == 1) return _1;
    else if(a == 'i') return _I;
    else if(a == 'j') return _J;
    else if(a == 'k') return _K;
}

int solution(int l, int x, string s);

int main(){

    int TT; cin >>TT;

    REP(t, TT){
        clear_cache();
        int L; int X;
        cin >> L; cin >> X;

        string sL; cin >> sL;

        int result = solution(L, X, sL);
        cout << "Case #" << t+1<< ": ";
        if(result == 0){
            cout << "NO" <<endl;
        }else {
            cout << "YES" << endl;
        }
    }

}

int solution(int L, int X, string s){

    int result = _1;

    int search = _I;

    REP(x, X){

        R r = search_and_multiply(result, s, search);

        result = r.result;

        if(search==_I){
            if(r.contain & 1<<_I)
                search++;
        }
        if(search==_J ){
            if(r.contain & 1<<_J)
                search++;
        }
        if(search==_K ){
            if(r.contain & 1<<_K){
                search=0;
            }
        }
    }

    if(search==0 && result == _1)
        return 1;

    return 0;
}

R search_and_multiply(int seed, string part, int search)
{
    int sgn = seed < 0 ? 0 : 1;
    if(cache[sgn][abs(seed)][search].result != 0)
        return cache[sgn][abs(seed)][search];

    int result = seed;
    int contain = 0; int target = _I;
    if(search > 1)
        target = search;

    for(int i=0; i<part.size(); i++){
        int next = transform(part[i]);
        result = multiply(result, next);

        if(search >1 && result == target && target <= _K){
            contain += 1<<target;
            target++;
            result = _1;
        }
    }

    cache[sgn][abs(seed)][search].result = result;
    cache[sgn][abs(seed)][search].contain = contain;

    return cache[sgn][abs(seed)][search];
}