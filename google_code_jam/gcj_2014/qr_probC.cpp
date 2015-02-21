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
#include <string.h>

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
 //   5 4 7
//    print_map(4, 5, 7, 1);
//    print_map(3, 4, 11, 1);
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
                    ans[j][i]='*';

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
                                if(ans[j][i] != '*') {
                                    ans[j][i] = '*';
                                    mc--;
                                } else{ }

                                if(mc==0 && i==c-2){
                                    ans[j][i] = '.';
                                    ans[j+1][0] = '*';
                                }
                            } else {
                                if(ans[j][i] == 0) ans[j][i] = '.';
                            }
                        }

                for(int i=0; i<c; i++)
                    for(int j=r-3; j<r; j++)
                        {
                            if(mc>0){
                                if(ans[j][i] != '*') {
                                    ans[j][i] = '*';
                                    mc--;
                                } else{ }

                                if(mc==0 && j==r-2){
                                    ans[j][i] = '.';
                                    ans[r-3][i+1] = '*';
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

int main2() {
    int cas, r, c, m, pos, v;
    scanf("%d", &cas);
    for (int ii=0; ii<cas; ii++) {
        scanf("%d%d%d", &r, &c, &m);
        memset(ans, 0, sizeof(ans));
        pos = 1;
        if (r == 1) {
            for(int i=0;i<m;i++)ans[0][i]='*';
            for(int i=m;i<c;i++)ans[0][i]='.';
            ans[0][c-1] = 'c';
        } else if (c==1) {
            for(int i=0;i<m;i++)ans[i][0]='*';
            for(int i=m;i<r;i++)ans[i][0]='.';
            ans[r-1][0] = 'c';
        } else if (m == r * c - 1) {
            for(int i=0; i<r; i++) for(int j=0; j<c; j++)ans[i][j] = i==0&&j==0?'c':'*';
        } else if (r == 2) {
            if (r*c-m == 2 || m%2!=0) pos = 0;
            else{
                for(int i=0; i<r; i++) for(int j=0; j<c; j++)ans[i][j] = j<m/2?'*':'.';
                ans[0][c-1] = 'c';
            }
        } else if (c == 2) {
            if (r*c-m == 2 || m%2!=0) pos = 0;
            else {
                for(int i=0; i<r; i++) for(int j=0; j<c; j++)ans[i][j] = i<m/2?'*':'.';
                ans[r-1][0] = 'c';
            }
        } else {
            v = r*c - m;
            if (v == 2 || v == 3 || v == 5 || v == 7) pos = 0;
            else{
                if (v / c <= 2) {
                    for(int i=0; i<r; i++) for(int j=0; j<c; j++)
                            ans[i][j] = i<3 && j*3+i<v?'.':'*';
                    if (v%3 == 1) {ans[1][v/3] = '.'; ans[2][v/3-1] = '*';}
                    ans[0][0] = 'c';
                } else {
                    for(int i=0; i<r; i++) for(int j=0; j<c; j++)
                            ans[i][j] = i*c+j<v?'.':'*';
                    if (v % c == 1) {
                        ans[v/c][1] = '.'; ans[v/c-1][c-1] = '*';
                    }
                    ans[0][0] = 'c';
                }
            }
        }
        if (pos) {
            printf("Case #%d:\n", ii+1);
            for(int i=0; i<r; i++) puts(ans[i]);
        } else {
            printf("Case #%d:\nImpossible\n", ii+1);

        }
    }
    return 0;
}