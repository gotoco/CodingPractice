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

typedef struct node {
    node * left;
    node * right;
    int val;
} root;


void  fullBinaryTree(int tc);
int recursiveSearch(root * root);

int main(){

    int N;
    scanf("%d", &N);
    REP(tc, N)
        fullBinaryTree(tc+1);

}

void fullBinaryTree(int tc)
{
    int N;
    scanf("%d", &N);
    node * nodes = (node*)calloc(N+1, sizeof(node));
    REP(l, N-1){
        int n1, n2;
        scanf("%d", &n1); scanf("%d", &n2);
        nodes[n1].val = n1;
        nodes[n2].val = n2;

        if(n1<n2){
            if(nodes[n1].left==NULL)
                nodes[n1].left = &nodes[n2];
            else
                nodes[n1].right = &nodes[n2];

        } else {
            if(nodes[n2].left==NULL)
                nodes[n2].left = &nodes[n1];
            else
                nodes[n2].right = &nodes[n1];
        }
    }
    node * root = &nodes[1];
    int result = recursiveSearch(root);

    printf("Case #%d: %d \n\r", tc, result);
    free(nodes);
}

int recursiveSearch(root * root)
{
    if(root->left == NULL && root->right == NULL) return 0;
    if(root->left != NULL && root->right != NULL){
         return ( recursiveSearch(root->left) + recursiveSearch(root->right) );
    }
    else
        return 1;
}

