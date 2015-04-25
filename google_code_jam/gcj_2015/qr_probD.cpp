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

enum game_winner{
D = 0,
    Richard = 1, //first player choose X-ominoes
    Gabriel = 2, // trying to combine ominoeses
};

game_winner play_game(int X, int R, int C);

int main(){

    int TT;
    cin >> TT;
//    while(1){ int t=0;
    REP(t, TT){


        int x; cin >> x;
        int r; cin >> r;
        int c; cin >> c;
        cout << "Case #" << t+1<< ": ";
        game_winner winner = play_game(x, r, c);

        switch(winner){
            case Richard : cout << "RICHARD" << endl; break;
            case Gabriel : cout << "GABRIEL" << endl; break;
            case D : cout << "D" << endl; break;
        }
    }

}


boolean richard_win(int R, int C, int X)
{
    if(R*C % X != 0) return true;
    if(X >= 7) return true;
    int S = min(R, C);
    int L = max(R, C);

    if(X == 3 and S == 1) return true;
    if(X == 4 and S <= 2) return true;
    if(X == 5 and (S <= 2 or (S==3 and L==5))) return true;
    if(X == 6 and S <= 3) return true;

    return false;
}

game_winner play_game(int X, int R, int C)
{
    //Check Bounds:
    if(C==1 || R ==1){   //one dimm board
        if(X>2) {
            return Richard;
        } else if(X==2){
            if(R*C%2 == 0) return Gabriel;
            else return Richard;
        } else if(X==1){
            return Gabriel;
        }
    }
    if(X > C+R-1){ //case when Richard can choose Xom bigger than board
        return Richard;
    }

    switch(X){
        case 1:{
            return Gabriel; //with single cell Gabriel always win
            break;
        }
        case 2: {

            if(C>1 && R>1){
                if(R*C%2 == 0) return Gabriel;
                else return Richard;
            }
            break;
        }
        case 3: {

            if(C<3 && R<3){
                return Richard;
            } else {
                if(R*C%3 == 0) return Gabriel;
                else return Richard;
            }

            break;
        }
        case 4: {

            if(C<4 && R<4){
                return Richard;
            }
            if(C<3 || R<3){
                return Richard;
            } else {
                if(R*C%4 == 0) return Gabriel;
                else return Richard;
            }

            break;
        }
        default: {
            return Richard;
        }
    }

    return Richard;
}