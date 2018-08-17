#include <cppcoding.h>

//8.1 triple step. n stpes could hop either 1 step, 2 steps, or 3 steps at a time. how many possible ways the child an run up the stairs.\

int countWays(int n){
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    else {
        return countWays(n-1) + countWays(n-2) + countWays(n-3);
    }
}

//8.5 Recursive multiplies of two unsigned value without using *.

int multiplies1(int x){
    int y = 0;
    if(y==0)
        return 0;
    else if(y==1)
        return x;
    else {
        return x; // + multiplies1(x, y-1);
    };
}

int main08(){

    countWays(10);
    int n = 4;
    multiplies1(n);
    return 0;    
}
