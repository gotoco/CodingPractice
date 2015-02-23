#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#define INF 9999999
using namespace std;

string createMask(string device, string flow, unsigned int & flips);
string applyMask(string flow, string mask);

int main2();
int solution();

int main() {

    solution();
}

int solution()
{
    int T, prob=1;
    cin >> T;
    for (int i=T; i>0; i--) {
        unsigned int globalmin = INF;
        cout << "Case #" << prob++ << ": ";

        unsigned int N, L;
        cin >> N >> L;
        vector<string> os(N), ds(N);
        for (int i = 0; i < N; i++) cin >> os[i];
        for (int i = 0; i < N; i++) cin >> ds[i];

        string device_0 = ds[0];

        for(int i=0; i<N; i++){
            unsigned int flips = 0;
            string mask_x = createMask(device_0, os[i], flips);
            std::set<string> fliped_outlets;

            for(int f=0; f<N; f++){
                if(f==i) continue;
                string masked = applyMask(os[f], mask_x);
                fliped_outlets.insert(masked);
            }
            bool cover_all = true;
            for(int d=1; d<N; d++){
                if(fliped_outlets.count(ds[d])==0){
                    cover_all= false; break;
                }
            }

            if(cover_all){
                globalmin = std::min(flips, globalmin);
            }

        }

        if(globalmin == INF) cout << "NOT POSSIBLE " << endl;
        else cout << globalmin << endl;
    }
}

string createMask(string device, string flow, unsigned int & flips)
{
    char * mask = (char*)malloc(device.length()+1);
    unsigned long n = device.length();

    for(int i=0; i<n; i++){
        if(device[i]==flow[i]){
            mask[i]='*';
        } else if(device[i]=='0'){
            mask[i] = '0';
            flips++;
        } else {
            mask[i] = '1';
            flips++;
        }
    }
    mask[n] = '\0';
    string result = string(mask);
    free((void*) mask);
    return result;
}

string applyMask(string flow, string mask)
{
    char * buffer = (char*)malloc(flow.length());
    unsigned long n = flow.length();

    for(int i=0; i<n; i++){
        if(mask[i] == '1'){
            if(flow [i] == '1')
                buffer[i] = '0';
            else buffer[i] = '1';
        } else if(mask[i] == '0'){
            if(flow [i] == '1')
                buffer[i] = '0';
            else buffer[i] = '1';
        } else {
            buffer[i] = flow [i];
        }
    }
    mask[n] = '\0';
    string result = string(buffer);
    free((void*) buffer);
    return result;
}

int main2() {
    int T, prob=1;
    for (cin >> T; T--;) {
        cout << "Case #" << prob++ << ": ";

        int N, L;
        cin >> N >> L;
        vector<string> os(N), ds(N);
        for (int i = 0; i < N; i++) cin >> os[i];
        for (int i = 0; i < N; i++) cin >> ds[i];
        int ret = 1000000;
        sort(ds.begin(), ds.end());
        for (int i = 0; i < N; i++) {
            vector<string> v = os;
            int cur = 0;
            for (int j = 0; j < L; j++) if (v[0][j] != ds[i][j]) {
                    for (int k = 0; k < N; k++) v[k][j] ^= 1;
                    cur++;
                }
            if (cur >= ret) continue;
            sort(v.begin(), v.end());
            if (v == ds) ret = cur;
        }

        if (ret == 1000000) {
            cout << "NOT POSSIBLE";
        } else {
            cout << ret;
        }
        cout << endl;
    }
}