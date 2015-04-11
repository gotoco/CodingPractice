#include <iostream>

/**
* \file similar.cpp 
* \brief
*
* \author maciek
* \date 11.04.15
*/
struct Similars {

    int maxsim(int L, int R)
    {
        int l_d [10];
        int r_d [10];

        for(int i=0; i<10; i++){
            l_d[i] = 0; r_d[i] = 0;
        }

        int ll = L;
        while(ll > 0){
            int d = ll%10;
            l_d[d]++;
            ll/= 10;
        }
        int rr = R;
        while(rr > 0){
            int d = rr%10;
            r_d[d]++;
            rr/= 10;
        }

        int result=0;

        for(int i=0; i<10; i++){
            if(l_d[i]>0 && r_d[i]>0)
                result++;
        }
        return result;
    }

};

int main(){

    struct Similars s;

    std::cout << s.maxsim(1, 10);

}