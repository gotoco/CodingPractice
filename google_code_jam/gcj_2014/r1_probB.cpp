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

    void dsf(int e= -1) {
        // The 'd' and 'f' represents go-into and exit times from vertex
        // s is number of father in dfs forest
        VI st(SIZE(g));
        int t=-1, i=0, b=0;
        e == -1 ? e=SIZE(g)-1 : b = e;
        //Set all vertexes as unchecked
        REP(x, SIZE(g)) g[x].d = g[x].f = g[x].s = -1;

        //ForEACH vertexes from [b..e] if vertex was not checked..?
        FOR(s,b,e)
            if(g[s].d == -1){
                st[i++] = s;
                g[s].d = ++t;
                g[s].f = SIZE(g[s]);

                //While stack is not empty..
                while(i){
                    int ss = st[i-1];
                    if(g[ss].f==0){g[ss].f = ++t; --i;} else {
                        ss = g[ss][--g[ss].f].v;
                        if(g[ss].d == -1){
                            g[ss].s = st[i-1];
                            g[ss].f = SIZE(g[ss]);
                            g[st[i++]= ss].d = ++t;
                            //check if it is fullTree member
                            if(g[g[ss].s].ft)
                                g[ss].ft = SIZE(g[ss])-1==0 || SIZE(g[ss])-1==2;
                            else g[ss].ft = false;
                        }
                    }
                }
            }
        if(SIZE(g[e])==2) g[e].ft == true;
    }
};
//Undirected graphs edges required rev field
struct Ve {
    int rev;
};
// fields to store algorithm DFS results
struct Vs {
    int d, f, s;
    bool ft; // is full tree member (has 2 or 0 sons)
};

int algorithm (int e);

int main(){

    int tc = 0; //test cases
    cin >> tc;
    REP(tt,tc) {
        cout << " Case #: " << tt << " ";
        int edges;
        cin >> edges;
        int sol = algorithm(edges);

        cout << sol;
    }

}

Graph<Vs, Ve> constructGraph(int n)
{
    Graph<Vs, Ve> g(n);
    int a,b,e;
    REP(x,n-1) {
        cin >> b >> e;
        g.EdgeU(b-1, e-1);
    }
    return g;
}

int algorithm(int n)
{
    Graph<Vs, Ve> tree = constructGraph(n);

    tree.dsf(0);

    REP(x, SIZE(tree.g)){
        cout << "vertex: " << x << " in-to 'g': " << tree.g[x].d << " exit 'f': " << tree.g[x].f << " dsf father: " << tree.g[x].s << " is FT member? : " << tree.g[x].ft << endl;
    }

    return tree.g.size();
}