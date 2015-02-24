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

template<class V, class E> struct Graph {

    struct Ed : E {
        int v;
        Ed(E p, int w) : E(p), v(w) {}
    };
    struct Ve : V, vector<Ed> {}; // Vertex type (Ve) extends po from V and Egde vector

    // Vertex vector inside graph
    vector<Ve> g;

    Graph(int n=0) : g(n) {}  // Constructor, get arg number of vertexes

    void EdgeU(int b, int e, E d = E()) {  // Add undirectional Edge (two directional edges)
        Ed eg(d,e); eg.rev=SIZE(g[e])+(b==e); g[b].PB(eg);
        eg.rev=SIZE(g[eg.v=b])-1; g[e].PB(eg);
    }
};
// Krawedzie grafu nieskierowanego wymagaja dodatkowego pola int rev
struct Ve {
    int rev;
};
// Wzbogacenie wierzcholkow przechowujace wynik generowany przez algorytm DFS
struct Vs {
    int d, f, s;
};

int main(){

    int tc = 0; //test cases
    cin >> tc;
    REP(tt,tc) {
        cout << " Case #: " << tt << endl;
    }

//    int n, m, s, b, e;
//    // Wczytaj liczbe wierzcholkow, krawedzi oraz numer wierzcholka startowego
//    cin >> n >> m >> s;
//    // Skonstruuj odpowiedni graf
//    Graph<Vs, Ve> g(n);
//    // Dodaj do grafu wszystkie krawedzie
//    REP(x,m) {
//        cin >> b >> e;
//        g.EdgeU(b, e);
//    }
//
//    REP(x, SIZE(g.g)) cout << "Wierzcholek " << x << ": size = " << g.g[x].size() << endl;

}
