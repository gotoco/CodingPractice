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

struct m2{
    unsigned int mm;
    int v; //visited?
};


m2 space [10][10];

bool is_possible(int x_s, int y_s);

inline void cleanup_space(){
    FOR(x, 0, 9)
        FOR(y, 0, 9){
            space[y][x].mm = 0;
            space[y][x].v = 0;
        }

}

inline void prepare_lawn(int x_s, int y_s){
    FOR(y, 0, y_s-1){
        FOR(x, 0, x_s-1){
            int x_x; cin >> x_x;
            space[y][x].mm = x_x;
        }

    }

}

int main()
{
    int T;
    cin >> T;

    REP(c, T){
        int xx, yy;
        cin >> yy; cin >> xx; cleanup_space();

        prepare_lawn(xx, yy);

        cout << "Case #" << c+1 << ": ";
        if(is_possible(xx, yy))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

#define IS_IN_BOUNDS(X, Y, XX, YY)      X>=0 && X<XX && Y>=0 && Y<YY
#define IS_NOT_VISITED(X, Y)            space[Y][X].v == 0
#define VISIT(X, Y)                     space[Y][X].v = 1
#define IS_SMALLER(X1, Y1, X2, Y2)       space[Y1][X1].mm >= space[Y2][X2].mm

#define y_  first
#define x_  second

inline void straight_x(int x_i, int y_i, int xx, int yy){

    VISIT(x_i, y_i);
    for(int i=1; i<xx; i++){
        if(IS_SMALLER(i, y_i, i-1, y_i)){
            VISIT(i, y_i);
        } else {
            break;
        }
    }
}

inline void straight_y(int x_i, int y_i, int xx, int yy){

    VISIT(x_i, y_i);
    for(int i=1; i<yy; i++){
        if(IS_SMALLER(x_i, i, x_i, i-1)){
            VISIT(x_i, i);
        } else {
            break;
        }
    }
}
inline void b_straight_y(int x_i, int y_i, int xx, int yy){

    VISIT(x_i, y_i);
    for(int i=yy-1; i>0; i--){
        if(IS_SMALLER(x_i, i, x_i, i+1)){
            VISIT(x_i, i);
        } else {
            break;
        }
    }
}

inline void b_straight_x(int x_i, int y_i, int xx, int yy){

    VISIT(x_i, y_i);
    for(int i=xx-1; i>0; i--){
        if(IS_SMALLER(i, y_i, i+1, y_i)){
            VISIT(i, y_i);
        } else {
            break;
        }
    }
}

inline int count_visited(int xx, int yy){
    int count=0;
    for(int y=0; y<yy; y++)
        for(int x=0; x<xx; x++)
            count+=space[y][x].v;

    return count;
}

bool is_possible(int x_s, int y_s)
{
    //make bsf or overflow water algorithm on board
    //x dim
    for(int i=0; i<x_s; i++){
        straight_x(i, 0, x_s, y_s);
        b_straight_x(i, y_s, x_s, y_s);
    }

    for(int i=0; i<y_s; i++){
        straight_y(0, i, x_s, y_s);
        b_straight_y(x_s, i, x_s, y_s);
    }
    int cnt = count_visited(x_s, y_s);
    if(cnt < x_s*y_s)
        return false;
    else
        return true;
}