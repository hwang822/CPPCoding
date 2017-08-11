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



int main08(){

    return 0;
}
