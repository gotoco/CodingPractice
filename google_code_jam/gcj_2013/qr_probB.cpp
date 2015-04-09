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


m2 space [100][100];

bool is_possible(int x_s, int y_s);

inline void cleanup_space(){
    FOR(x, 0, 99)
        FOR(y, 0, 99){
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
        cin >> xx; cin >> yy; cleanup_space();

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

#define VISIT(X, Y)                    space[Y][X].v++

#define y_  first
#define x_  second

inline void pour_it_out(int x_i, int y_i, int xx, int yy){

    if(space[y_i][x_i].v)
        return ;

    vector <pair<int, int>> s; //stack
    s.PB(std::make_pair(x_i, y_i));VISIT(x_i, y_i);

    while(!s.empty()){
        pair<int, int> e = s.LT;
        int s_size = s.size();
        int upp_x = e.x_ ; int upp_y = e.y_-1;
        if(IS_IN_BOUNDS(upp_x, upp_y, xx, yy) && IS_NOT_VISITED(upp_x, upp_y) ){
            VISIT(upp_x, upp_y);
            s.PB(std::make_pair(upp_x, upp_y));
        }
        int dow_x = e.x_; int dow_y = e.y_+1;
        if(IS_IN_BOUNDS(dow_x, dow_y, xx, yy) && IS_NOT_VISITED(dow_x, dow_y)){
            VISIT(dow_x, dow_y);
            s.PB(std::make_pair(dow_x, dow_y));
        }
        int l_x = e.x_-1; int l_y = e.y_;
        if(IS_IN_BOUNDS(l_x, l_y, xx, yy) && IS_NOT_VISITED(l_x, l_y)){
            VISIT(l_x, l_y);
            s.PB(std::make_pair(l_x, l_y));
        }
        int r_x = e.x_+1; int r_y = e.y_;
        if(IS_IN_BOUNDS(r_x, r_y, xx, yy) && IS_NOT_VISITED(r_x, r_y)){
            VISIT(r_x, r_y);
            s.PB(std::make_pair(r_x, r_y));
        }

        if(s_size == s.size())
            s.pop_back();
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
        pour_it_out(i, 0, x_s, y_s);
        pour_it_out(i, y_s-1, x_s, y_s);
    }

    for(int i=1; i<y_s; i++){
        pour_it_out(0, i, x_s, y_s);
        pour_it_out(x_s-1, i, x_s, y_s);
    }
int cnt = count_visited(x_s, y_s);
    if(cnt < x_s*y_s)
        return false;
    else
        return true;
}