#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <strings.h>

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

int omar_play(vector<string> s);

int main() {

    int tt; cin >> tt;

    REP(c, tt){
        vector<string> s; string tmp;
        int N; cin >> N;
        REP(n, N) {
            cin >> tmp; s.PB(tmp);
        }

        int result = omar_play(s);
        cout << "Case #" << c+1 << ": ";
        if(result < 0){
            cout<< "Fegla Won" << endl;
        } else {
            cout << result << endl;
        }
    }

}

vector<int> calculate_median(vector<string> s, char * pattern, int pattern_length)
{
    vector<int> result;
    int ** freq_map = (int **)calloc(sizeof(int *), s.size());
    for(int i=0; i<s.size(); i++)
        freq_map[i] = (int*)calloc(sizeof(int), pattern_length);

    for(int n=0; n<s.size(); n++){
        string t = s[n];
        int ii = 0;
        for(int i=0; i<pattern_length; i++){
            int cnt = 0;
            while(t[ii] == pattern[i]){
                ii++;
                cnt++;
            }

            freq_map[n][i] +=cnt;
        }
    }
    static int x [100];
    for(int i=0; i<pattern_length; i++){
        for(int n=0; n<s.size(); n++){
            x[n] = freq_map[n][i];
        }
        sort(x, x+s.size());

        if(s.size()%2 )
            result.PB(x[s.size()/2]);
        else
            result.PB(  (x[s.size()/2]+x[s.size()/2 - 1])/2 );

        for(int j=0; j<100; j++) x[j] = 0;
    }
    for(int i=0; i<s.size(); i++)
        free(freq_map[i]);
    free(freq_map);
    return result;
}

int omar_play(vector<string> s)
{
    string fs = s[0];
    char *pattern = (char *) calloc (fs.size(), sizeof(char*));
    unsigned int * pattern_cnt = (unsigned int *) calloc(fs.size(), sizeof(unsigned int*));
    pattern[0] = fs[0]; int index=0;
    FOR(i, 1, fs.size()){
        if(pattern[index] != fs[i]) {
            pattern[index++ +1] = fs[i];
        }
    }
    vector<int> median = calculate_median(s, pattern, index);
    int result3 = 0;
    int N = index;
    for(int i=0; i<s.size(); i++){
        string c = s[i];
        int ii = 0;
        for(int x=0; x<N; x++){
            if(c[ii] != pattern[x]){
                return -1; //
            }
            int cnt = 0;
            while(c[ii] == pattern[x]){
                ii++;
                cnt++;
            }
            pattern_cnt[x] +=cnt;
        }

        if(ii != c.size())
            return -1;
    }

    for(int i=0; i<s.size(); i++){
        string c = s[i];
        int ii = 0;
        for(int x=0; x<N; x++){
            int occ = 0;
            while(c[ii] == pattern[x]){
                ii++;
                occ++;
            }
            result3 += std::abs(median[x]-occ );
        }
    }

    free(pattern);
    free(pattern_cnt);

    return result3;
}