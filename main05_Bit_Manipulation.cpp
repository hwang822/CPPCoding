#include "stdafx.h" // for windows version
#include "cppcoding.h"

//5.1 Insertion
int UpdateBits(int n, int m, int i, int j){
    unsigned short seed = 1;
    for(int index = i; index<=j; index++){
        seed = seed * 2;
    }
    seed = seed-1;
    seed = seed << i;
    m = m << i;
    n = n & ~seed;
    n = n | m;
    return n;
}

//5.3 Flip Bit to Win
// input 1775 (or bit: 11011101111) => 8 (or bit: 1000).

int LongestSequence(int n){
    unsigned int n1 = n;
    //n1 = ~n1;
    int iLen =0;
    int zLen = 0;
    while(n1>0){
        if(!(n1 & 1))
            zLen = iLen;
        n1 = n1 >> 1;
        iLen++;
    }
    if(zLen==0)
        zLen = iLen;

    return zLen;
}

//5.6 Next Numbre
void getNext(int &larget, int &samllest, int n){
    unsigned int n1 = n;
    int countOne = 0;
    unsigned int seed = 1;
    int len = 0;
    while(n1>0){
        if(n1&1)
        {
            countOne++;
            seed = seed * 2;
        }
        n1 = n1>>1;
        len++;
    }
    seed--;
    samllest = seed;
    larget = samllest << len-countOne;
}

int main05(){
    int larget = 0, semallest = 0;
    getNext(larget, semallest, 9);
    cout << LongestSequence(1775) << endl;
    cout << UpdateBits(8, 3, 0, 1) << endl;
    return 0;
}

