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
#define ST first
#define ND second

#define IF_SUM_MATCH( x )         if(x==X_win || x==XT_win ) \
                                      return x_won; \
                                    else if (x==O_win || x==OT_win) \
                                      return o_won;

#define X 88
#define T 84
#define O 79
#define dot 46

#define X_win   352
#define XT_win  348
#define O_win   316
#define OT_win  321

enum tick_tack_result{
    x_won = 0,
    o_won = 1,
    draw = 3,
    not_complete = 4,
};

enum tick_tack_result tick_tack_game(VI board);
VI get_board_from_input();

int main(){
    int tT;
    scanf("%d", &tT);

    REP(i, tT){
        cout << "Case #"<<i+1<<": ";
        enum tick_tack_result r =  tick_tack_game(get_board_from_input());

        switch(r){
            case(x_won) : cout << "X won\n\r"; break;
            case(o_won) : cout << "O won\n\r"; break;
            case(draw) : cout << "Draw\n\r"; break;
            case(not_complete) : cout << "Game has not completed\n\r"; break;
        }
    }

    return 0l;
}

VI get_board_from_input()
{
    string s;
    VI r;

    REP(x, 4) {
        cin >> s;
        REP(y, 4)
            r.PB(s[y]);
    }

    return r;
}

enum tick_tack_result tick_tack_game(VI b)
{
    //FOR each column
    FOR(i, 0, 3){
        int sum = (b[i]+b[i+4]+b[i+8]+b[i+12]);

        IF_SUM_MATCH( sum );
    }

    //FOR each row
    for(int i=0; i<16; i+=4){
        int sum = (b[i]+b[i+1]+b[i+2]+b[i+3]);

        IF_SUM_MATCH( sum );
    }
    //diagonals
    int sum_d1 = b[0] + b[4+1] + b[8+2] + b[15];
        IF_SUM_MATCH( sum_d1 );
    int sum_d2 = b[12] + b[6] + b[8+1] + b[3];
        IF_SUM_MATCH( sum_d2 );

    //Else check if is empty place:
    FOREACH(i, b) if(*i == dot) return not_complete;
    //last option no winner
    return draw;
}