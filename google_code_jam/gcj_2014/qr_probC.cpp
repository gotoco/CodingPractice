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

char ans[55][55];

void print_map(int c, int r, int m, int ii);

int main() {
    int cas;

    scanf("%d", &cas);
    for (int ii=0; ii<cas; ii++) {
        unsigned int r, c, m;
        scanf("%d%d%d", &r, &c, &m);
        print_map(c, r, m, ii);
 }

//    print_map(10, 1, 8, 1);
//    print_map(1, 10, 8, 1);
//    print_map(2, 10, 16, 1);
//    print_map(10, 2, 16, 1);

    return 0;
}

void print_map(int c, int r, int m, int ii)
{
    int possible = 1;
    memset(ans, 0, sizeof(ans));
    //o case CxR-M = 0
    if(c*r-m==0) {
        possible = 0;
    }

    //1 case: CxR-M = 1
    if(c*r-m==1){
        possible = 1;

        for(int i=0; i<c; i++)
            for(int j=0; j<r; j++)
                    ans[i][j]='*';

        ans[0][0] = 'c';
    }
    //2case R || C == 1
    else if (r == 1 || c == 1 ) {
            possible = 1;

            if(r==1){
                for(int i=0; i<m; i++) ans[0][i] = '*';
                for(int i=m; i<c-1; i++) ans[0][i] = '.';
                ans[0][c-1] = 'c';
            } else if(c==1){
                for(int i=0; i<m; i++) ans[i][0] = '*';
                for(int i=m; i<r-1; i++) ans[i][0] = '.';
                ans[r-1][0]= 'c';
            }
    }
    //3 case RxC-M == 2||3
    else if(r*c-m == 2 || r*c-m == 3){
        possible = 0;
    }
    //4 case R==2 || C==2 possible if M%2
    else if(r==2 || c==2){
        if(m%2 == 0){
                possible = 1;

                if(r==2){

                    for(int j=0; j<m/2; j++)
                        for(int i=0; i<r; i++){
                            ans[i][j] = '*';
                        }
                    for(int j=m/2; j<c; j++)
                        for(int i=0; i<r; i++){
                            ans[i][j] = '.';
                        }

                } else if(c==2){

                    for(int i=0; i<m/2; i++){
                        ans[i][0] = '*';
                        ans[i][1] = '*';
                    }
                    for(int i=m/2; i<r; i++){
                        ans[i][0] = '.';
                        ans[i][1] = '.';
                    }
                }
                ans[r-1][c-1] = 'c';
            }
            else{
                possible = 0;
            }

        }
        //5 case no trivial
        else {
            unsigned int w = c*r - m;
            unsigned int mc = m;
            if(w==2 || w==3 || w==5 || w==7) possible = 0;
            else{

                for(int j=0; j<r-3; j++)
                    for(int i=0; i<c; i++)
                        {
                            if(mc>0){
                                ans[j][i] = '*';
                                mc--;
                            } else {
                                ans[j][i] = '.';
                            }
                        }

                for(int i=0; i<c; i++)
                    for(int j=r-3; j<r; j++)
                        {
                            if(mc>0){
                                ans[j][i] = '*';
                                mc--;
                                if(mc==0 && j==r-2){
                                    ans[j][i] = '.';
                                    ans[r-3][i+1] = 'm';
                                }
                            } else {
                                if(ans[j][i] == 0) ans[j][i] = '.';
                            }
                        }
                    ans[r-1][c-1] = 'c';

            }
        }

    if (possible) {
        printf("Case #%d:\n", ii+1);
        for(int i=0; i<r; i++) puts(ans[i]);
    } else {
        printf("Case #%d:\nImpossible\n", ii+1);
    }
}