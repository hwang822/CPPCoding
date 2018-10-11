#include "stdafx.h" // for windows version
#include "cppcoding.h"
#include <math.h>
bool primeNaive(int n){
    if(n==2)
        return false;
    for(int i = 2; i < n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool primeSlightyBetter(int n){
    if(n<2)
        return false;
    int sqrt = (int)sqrtl(n);
    for(int i=2; i<=sqrt; i++){
        if(n%i==0) return false;
    }
    return true;
}
//6.1 The Heavy Pill: 20 botters of pills. 19 bottles have
//1.0 gram and only one have 1.1gram. select havey one only using
//one time scal

bool heavyPill(double pills[], int n, double sum){
    if(n==0){
        return false;
    }
    else
    {
        sum = sum - pills[n-1];
        if(sum < 1.0*(n-1)){
          cout <<"heavy pill at " << n-1 << endl;
          return false;
        }
        if(heavyPill(pills, n-1, sum))
          return true;
    }
    return false;

}


//6.7 count famils G and B

double runNFamiles(int n){
	return 0;
}

int* runOneFamily(){
    int boys = 0;
    int girls = 0;

    int genders[] = {girls, boys};
    return genders;
}




int main06(){
    double pills[] = {1.0,1.0,1.0,1.0,1.0,1.0,1.1,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
    double ret= heavyPill(pills, 20, 20*1.0);
    cout << primeNaive(84) << endl;
    cout << primeSlightyBetter(84) << endl;
    return 0;
}
