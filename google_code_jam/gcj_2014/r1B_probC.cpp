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

#define INF 99999999

inline void clr_g(int g[50][50]){
    for(int i=0; i<50; i++)
        for(int j=0; j<50; j++)
            g[i][j]=0;
}

string get_smallest_zip(int g[50][50], VI zips, int N, int M);

int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int TT; cin >> TT;

    REP(tt, TT){
        int g[50][50]; clr_g(g);
        int N, M;
        cin >> N; cin >> M;

        VI vi; int zip;
        REP(n, N){ cin>>zip;
            vi.PB(zip);
        }
        REP(m, M){ int d1, d2; cin >> d1; cin >> d2;
            g[d1-1][d2-1] = 1;
            g[d2-1][d1-1] = 1;
        }

        printf("Case #%d: ", tt+1 );
        cout <<  get_smallest_zip(g, vi, N, M) << endl;

    }

    return 0;
}

#define visit( X )  X+=4
#define is_v( X )   X && 4
#define not_v( X )  X == 1

int not_visited(int g[50][50], int x, int N){
    int r = 1;

    for(int i=0; i<N; i++){
        if(g[x][i] > 1 or g[i][x] > 1){
            r = 0; break;
        }
    }
    return r;
}

string get_smallest_zip(int g[50][50], VI zips, int N, int M)
{
    string r = "";
    int ss=INF;  int start;
    for(int i=0; i<zips.size(); i++){
        if(ss>zips[i]){
            ss=zips[i];
            start=i;
        }
    }
    VI s; s.PB(start);
    r+= to_string(zips[start]);
    while(not s.empty()){
        int top = s.back();
        int small = INF;//search smallest not visited neighbor
        for(int i=0;i<N; i++){
            if( g[top][i] > 0 and not_visited(g, i, N) and small>g[top][i])
                small = i;
        }
        if(small != INF){
            if(not_visited(g, small, N))
                r = r + to_string(zips[small]);
            visit(g[top][small]);
            s.PB(small);
        }else{
            s.POP();
            if(s.empty()) continue;
            visit(g[top][s.back()]);
        }


    }
    return r;
}
