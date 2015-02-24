#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Dwa z najczesciej uzywanych typow o dlugich nazwach
// - ich skrocenie jest bardzo istotne
typedef vector<int> VI;
typedef long long LL;

// W programach bardzo rzadko mozna znalezc w pelni zapisana instrukcje petli.
// Zamiast niej wykorzystywane sa trzy nastepujace makra:
// FOR - petla zwiekszajaca zmienna x od b do e wlacznie
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
// FORD - petla zmniejszajaca zmienna x od b do e wlacznie
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
// REP - petla zwiekszajaca zmienna x od 0 do n. Jest ona bardzo czesto
// wykorzystywana do konstruowania i przegladania struktur danych
#define REP(x, n) for(int x = 0; x < (n); ++x)
// Makro VAR(v,n) deklaruje nowa zmienna o nazwie v oraz typie i wartosci
// zmiennej n. Jest ono czesto wykorzystywane podczas operowania na
// iteratorach struktur danych z biblioteki STL, ktorych nazwy typow sa bardzo dlugie
#define VAR(v, n) __typeof(n) v = (n)
// ALL(c) reprezentuje pare iteratorow wskazujacych odpowiednio na pierwszy
// i za ostatni element w strukturach danych STL. Makro to jest bardzo
// przydatne chociazby w przypadku korzystania z funkcji sort, ktora jako
// parametry przyjmuje pare iteratorow reprezentujacych przedzial
// elementow do posortowania
#define ALL(c) (c).begin(), (c).end()
// Ponizsze makro sluzy do wyznaczania rozmiaru struktur danych STL.
// Uzywa sie go w programach, zamiast pisac po prostu x.size() ze wzgledu na to,
// iz wyrazenie x.size() jest typu unsigned int i w przypadku porownywania
// z typem int w procesie kompilacji generowane jest ostrzezenie
#define SIZE(x) ((int)(x).size())
// Bardzo pozyteczne makro sluzace do iterowania po wszystkich elementach
// w strukturach danych STL
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
// Skrot - zamiast pisac push_back podczas wstawiania elementow na koniec
// struktury danych, takiej jak vector, wystarczy napisac PB
#define PB push_back
// Podobnie - zamiast first bedziemy pisali po prostu ST
#define ST first
// a zamiast second - ND
#define ND second

template<class V, class E> struct Graph {

    struct Ed : E {
        int v;
        Ed(E p, int w) : E(p), v(w) {}
    };
    // Typ wierzcholka (Ve) dziedziczy po typie zawierajacym dodatkowe informacje
    // z nim zwiazane (V) oraz po wektorze krawedzi.
    struct Ve : V, vector<Ed> {};
    // Wektor wierzcholkow w grafie
    vector<Ve> g;
    // Konstruktor grafu - przyjmuje jako parametr liczbe wierzcholkow
    Graph(int n=0) : g(n) {}
    // Funkcja dodajaca do grafu nowa krawedz nieskierowana, laczaca wierzcholki b i e oraz zawierajaca dodatkowe informacje okreslone przez zmienna d.
    void EdgeU(int b, int e, E d = E()) {
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

    int n, m, s, b, e;
    // Wczytaj liczbe wierzcholkow, krawedzi oraz numer wierzcholka startowego
    cin >> n >> m >> s;
    // Skonstruuj odpowiedni graf
    Graph<Vs, Ve> g(n);
    // Dodaj do grafu wszystkie krawedzie
    REP(x,m) {
        cin >> b >> e;
        g.EdgeU(b, e);
    }

}
