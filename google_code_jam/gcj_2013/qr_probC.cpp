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

//Try to use inline wherever is possible
#define _IL     inline

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
#define RV( x ) std::reverse(x.begin(), x.end())

#define INF 99999999

vector< vector<char> > fairs;
void gen_faints(void);
void gen_25(void); //not fast enaught
void gen_50(void);
_IL void print_v(vector<char> el);

/* Is A < B?
    -\ret >0 ? B > A
    -\ret <0 ? A > B
    -\ret =0 ? A = B
*/
_IL int cmp(const vector<char> & a, const vector<char> & b) {
    if (a.size() != b.size()) {
        return b.size() - a.size();
    }
    for (int i=0; i<a.size(); ++i) {
        if (a[i] != b[i]) {
            return b[i] - a[i];
        }
    }
    return 0;
}

_IL int find_p(vector<char> el) {
    int s = 0, e = fairs.size(), p;
    while( s <= e){
        p = (e+s)/2;
        if(cmp(el, fairs[p]) > 0 )
            e = p - 1;
        else
            s = p + 1;
    }
    return e;
}

inline void print_v(vector<char> el){
    for (std::vector<char>::const_iterator i = el.begin(); i != el.end(); ++i)
        fprintf(stderr, "%u", *i);
}

int d_search(vector<char> el){
    int i=0;
    while(cmp(fairs[i], el) >= 0){
        i++;
    }
    return i;
}

char _A[102], _B[102];
_IL int dothat()
{
    scanf(" %s %s", _A, _B);
    vector<char> AA, BB;
    for (int i=0; _A[i] != NULL; ++i) {
        AA.PB(_A[i]-'0');
    }

    for (int i=0; _B[i] != NULL; ++i) {
        BB.PB(_B[i]-'0');
    }

    int j=AA.size() - 1;
    while(AA[j] == 0) {
        AA[j] = 9;
        --j;
    }
    --AA[j];

    int s = find_p(AA);
    int e = find_p(BB);

//    int d_s = d_search(AA);
//    int d_e = d_search(BB);

return (e-s);
}

int main(){
    freopen("C-large-practice-2.in", "r", stdin);
    freopen("out", "w", stdout);
    freopen("err", "w", stderr);

    int TT; cin >> TT;

    gen_faints();

    REP(tt, TT){
        int s = dothat();
        printf("Case #%d: %d\n", tt+1, s);
    }

    return 0;
}

/**
 * Check if it is palindrome?
 * -1 : no palindrome
 * 1 : is palindrome
 */
_IL int isP( LL n){
    static int _f[1000];
    int size = 0;
    while(n > 0){
        _f[size++] = n%10;
        n /= 10;
    }
    int ans = 1;
    for(int i=0; i<size/2; i++)
        if(_f[i] != _f[size-i-1]){
            ans = -1;
            break;
        }
    return ans;
}

_IL vector<char> j2v(LL j){
    vector<char> result;
    while(j >0){
        result.PB( uint8_t(j%10) );
        j /= 10;
    }
    RV(result);
    return result;
}

_IL int sol(LL A, LL B)
{
    int ans = 0;
    LL i=0, I=0;
    i = (int) sqrt(A);
    if(i*i <A) i++;
    I = (int) sqrt(B);
    if(I*I <B) I++;

    for(int j=i; j<=I; j++){
        if(isP(j) == 1){
            if(isP((LL)j*j) == 1 and (LL)j*j <= B){
                LL j2 = (LL)j*j;
                ans ++;
                fairs.PB( j2v(j2));
            }
        }
    }

    return ans;
}

void gen_faints(void)
{
    //sol(1, 1152921504606846975);
    gen_50();
}

_IL int inc_v_b3(vector<char> &v)
{
    int s = v.size()-1; int c = 1;
    while(c > 0){
        if(s < 0){
            v.insert(v.begin(), 1);
            c--;
        }
        else if(v[s] < 2){
            v[s]++;
            c--;
        } else {
            v[s] = 0;
            s--;
        }
    }
    if(v.size() > 25)
        return 25;

    return 0;
}

_IL vector<char> hugeP2(vector<char> p)
{
    vector<char> result(p.size() * 2, 0);
    for (int i=0; i<p.size(); ++i) {
        for (int j=0; j<p.size(); ++j) {
            result[i+j] += p[i] * p[j];
        }
    }
    while ((result.size() > 1) && (result.back() == 0)) {
        result.pop_back();
    }
    return result;
}

_IL int isP(vector<char> v)
{
    int s=v.size(); //, s = v.size()-1;
    int ans = 1;
    for(int i=0; i< (s+1)/2; ++i){
        if(v[i] > 9) return -1;
        if(v[i] != v[s-i-1]){
            ans = -1;
            break;
      }
    }
  return ans;
}

void fillVec2sum (int pos, vector<char> v, int sum)
{
        if(pos*2 < v.size()-1){
            int i = 0;
            if(pos == 0)
                ++i;
            while(i*i*2 <= sum ){
                v[pos] = v[v.size()-1-pos] = i;
                fillVec2sum(pos+1, v, sum-(i*i*2));
                i++;
            }
        } else if(pos == v.size()/2 && v.size() % 2 != 0){
            int i=0;
            while(i*i <= sum ){
                 v[pos] = i;
                 fillVec2sum(pos+1, v, sum-(i*i*2));
                 i++;
            }
        } else {
            fairs.PB(v); //print_v(v);
            //endl();
        }
}

void gen_50() {

    vector<char> digit(1);
    digit[0] = 0;
    fairs.push_back(digit);
    digit[0] = 1;
    fairs.push_back(digit);
    digit[0] = 2;
    fairs.push_back(digit);
    digit[0] = 3;
    fairs.push_back(digit);

    for (int i=2; i<52; ++i) {
        vector<char> v(i);
        fillVec2sum(0, v, 9);
    }

    for (int i=0; i<fairs.size(); ++i) {
        fairs[i] = hugeP2(fairs[i]);
    }
}

void gen_25(void)
{
fprintf(stderr, "## gen25" );
    //Add 1,4,9  there are sfi (1 char P).
    vector<char> sfi(1);
    sfi[0] = 1;
    fairs.PB(sfi);
    sfi[0] = 4;
    fairs.PB(sfi);
    sfi[0] = 9;
    fairs.PB(sfi);
    vector<char> _r(1);
    _r[0] = 1;

    int d25 = 0;
    //while 25
    while(d25 == 0){
int sum = 0;
for (std::vector<char>::const_iterator i = _r.begin(); i != _r.end(); ++i)
       sum += *i;

if(sum <9){
        //create calculate P^2
        vector<char> p_22 = hugeP2(_r);

        //check if P^2 isP if yes add to list.
        if( (isP(p_22)==1) && (isP(_r)==1) ){
            fairs.PB(p_22);
        }
}
        //increase _r
        d25 = inc_v_b3(_r);
    }
}
