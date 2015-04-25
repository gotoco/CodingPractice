#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <cassert>

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
        {0,  0,  0,   0,   0,  },
        {0,  _1, _I,  _J,  _K, },
        {0, _I, -_1,  _K, -_J, },
        {0, _J, -_K, -_1,  _I, },
        {0, _K, _J,  -_I, -_1, },
};


int multiply(int i, int j){
    if(i > 4 || i < -4 || j > 4 || j<-4){
        cout << "## ERR:  i=" << i << "  j=" << j << endl;
        throw std::invalid_argument( "received invalid value value" );
    }
    int sgn = i*j < 0 ? -1 : 1;
    int result = quater[abs(i)][abs(j)];

    return sgn * result;
}

#define M( X, Y )  multiply(X, Y)

int power(int a, long n){
    if(n==1) return a;
    if(n%2 == 0) return power( M(a, a), n/2);
    else return M(a, power(M(a,a), n-1));
}

inline int transform(char a){
    int r = a-48;
    int sgn = r < 0 ? -1 : 1;
    if(r == 1) return _1;
    else if(a == 'i') return _I * sgn;
    else if(a == 'j') return _J * sgn;
    else if(a == 'k') return _K * sgn;
}
#define T( X )  transform(X)

int solution(long l, long x, string s);

static int get_product(long L, long X, string s);
static int find_i_j(long L, long X, string s);

int main(){

    FILE *fin = freopen("large.in", "r", stdin);
    assert( fin!=NULL );
    FILE *fout = freopen("large.out", "w", stdout);

    string sL;
    int TT; cin >>TT;

    REP(t, TT){
        long L; long X;
        cin >> X; cin >> L;

        cin >> sL;

        int result = solution(L, X, sL);
        cout << "Case #" << t+1<< ": ";
        if(result == 0){
            cout << "NO" <<endl;
        }else {
            cout << "YES" << endl;
        }
        sL.clear();
    }

}

int solution(long L, long X, string s)
{
    int product = get_product(L, X, s);
    if(product != -_1)
        return 0;

    int result = find_i_j(L, X, s);

    return result;
}

int get_product(long L, long X, string s)
{
    int r = _1;
    for(int i=0; i<X; i++){
        r = multiply(r, T(s[i]));
    }

    return power(r, L);
}

int find_i_j(long L, long X, string s)
{
    int tmp = _1;
    int is_i = 0, is_j = 0;
    FOR(l, 0, L-1)
        FOR(x, 0, X-1){
            tmp = multiply(tmp, T(s[x]) );
            if(!is_i and tmp == _I){
                is_i = 1; tmp = _1;
            }
            else if(is_i and !is_j and tmp == _J){
                is_j = 1;
                return 1;
            }
        }

    return is_i and is_j;
}