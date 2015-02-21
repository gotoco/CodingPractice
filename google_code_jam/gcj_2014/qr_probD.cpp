#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
//std::vector<char> path;
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

using namespace std;

pair <double, int> a[123456];

double ken [1010];
double naomi [1010];


int war(double ke [], double na [], int n);
int deceitfulWar(double ke [], double na [], int n);

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    int tt;
    scanf("%d", &tt);
    for (int qq = 1; qq <= tt; qq++) {
        printf("Case #%d: ", qq);

        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            scanf("%lf",  &naomi[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%lf",  &ken[i]);
        }

        int warResult = war(ken, naomi, n);
        int dwarResult = deceitfulWar(ken, naomi, n);

        printf("%d %d\n",  dwarResult, warResult);

    }
}

int war(double ke [], double na [], int n)
{
    sort(ke, ke+n);
    sort(na, na+n);

     int kr=1;
     int nr=1;
     int warResult = 0;
    for(int i=0; i<n; i++){
        if(ken[n-kr] > naomi[n-nr]){
            kr++;
            nr++;
        } else {
            nr++;
            warResult++;
        }
    }

    return warResult;
}

int deceitfulWar(double ke [], double na [], int n)
{
    sort(ke, ke+n);
    sort(na, na+n);
    int newN = n;
     int kr=1;
     int n_start = 1;
     int n_end = n;
     int dWarResult = 0;

    int i=0;

    while(i<n && n_start <= n_end){

        if(ken[newN-kr] > naomi[newN-n_start]){
            kr++;
            n_end--;
        } else {
            n_start++;
            kr++;
            dWarResult++;
        }
    }

    return dWarResult;
}