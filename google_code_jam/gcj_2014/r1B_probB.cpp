#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <strings.h>
#include <math.h>

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

unsigned long dynamic_pp_solution(unsigned int a, unsigned int b, unsigned int k);
unsigned long brute_force(unsigned int a, unsigned int b, unsigned int k);

int main() {


    int tt; cin >> tt;

    REP(c, tt){
        unsigned int a, b, k; cin >> a; cin >> b; cin>>k;
        cout << "Case #" << c+1 << ": " ;

        cout << "  BF : " << brute_force(a, b, k) << endl;

        unsigned long result = dynamic_pp_solution(a, b, k);

        cout << " DP : " << result;


    }

}

unsigned long brute_force(unsigned int a, unsigned int b, unsigned int k)
{
    unsigned int result = 0;
    for(int i=0 ; i<a; i++){
        int row = 0;
        for(int j=0; j<b; j++){
            if((j & i) < k) {
                result++; row++;
            }
        }
        cout << "row " << i << "  : " << row << endl;
    }

    return result;
}

unsigned long dynamic_pp_solution(unsigned int a, unsigned int b, unsigned int k)
{
    unsigned int result = 0;

    if(k > a || k > b) return 0;
    int C, c;
    if(a > b){
        C = a; c = b;
    }else{
        C = b; c = a;
    }

    for(int i=0; i<c; i++){  //iteruje po mniejszej liczbie
        VI va;
        long tmp_result = 0;

        int pow = 0;
        unsigned int ii = i;
        while(ii>0){
            if(ii%2 == 1) va.PB(  std::pow (2, pow) );
            pow++;
            ii /= 2;
        }

        int smaller_than_k_cnt = 0;
        int bigger_than_k_cnt = 0;

        FOREACH(it, va)
            if(*it<k) smaller_than_k_cnt++;
            else bigger_than_k_cnt++;

        if(bigger_than_k_cnt > 0)
            tmp_result += std::pow(2, smaller_than_k_cnt) + std::pow(2, bigger_than_k_cnt);
        else{
            int sum = 0;
            FOREACH(it, va)
                if(*it<k) sum+= *it;

            if(sum >= k) tmp_result += (sum-k+1);
        }

        for(int j=c; j<C; j++)
            if((j & i) >= k)
                tmp_result++;

        result+= tmp_result;
    }

    return a*b-result;
}

//unsigned long dynamic_pp_solution(unsigned int a, unsigned int b, unsigned int k)
//{
//    unsigned int result = 0;
//    VI vi;
//
//    if(k > a || k > b) return 0;
//
//    unsigned int kk = k;
//    int pow = 0;
//    while(kk>0 && std::pow (2, pow) < b){
//        if(kk%2 == 0) vi.PB(  std::pow (2, pow) );
//        pow++;
//        kk /= 2;
//    }
//
//    int pow2 = 0;
//    int tmp = a > b ? a : b;
//    tmp--;
//    int rest = tmp >> pow;
//    while(rest > 0 ){
//        rest /= 2;
//        pow2 ++;
//    }
//
//    int cases = std::pow (2, pow2 + vi.size()) ;
//
//    return (unsigned long)a * b - cases;
//}