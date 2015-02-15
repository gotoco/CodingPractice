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

using namespace std;

int main() {
    int cas;
    scanf("%d", &cas);
    for (int ii=0; ii<cas; ii++) {
        double c, f, x, t=0.0, s=2.0;
        scanf("%lf%lf%lf", &c, &f, &x);

        double t_x = x/s;
        double t_0 = 0;

        for(int i=0; i<=x/c+1; i++){
            double s_n = s+f;
            t_0 +=c/s;
            double t_n = t_0 + x/s_n;

            if(t_x < t_n ){
                printf ("Case #%d: %.7f\n", ii+1, t_x);
                break;
            }
            t_x = t_n;
            s = s_n;
        }
    }
    return 0;
}