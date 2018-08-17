#include <cppcoding.h>

//11.1 Mistake Find the mistake(s) in the following code:

//11.2 Radnom Crashers:

// 1. "Random Mariable". The application may user rundom variable or number
// it is not fixed value for every exectuion of the program.

// 2. Uninitialized variables.
// 3. Memory Leak: the programe may run out of memory. Or heap overflow or corruption of data on the stack.
// 4. External dependencise:


int main11(){

    unsigned int i; //imossible <0;
    //for(int i=100; i>=0; i--)
    for(int i=100; i>0; i--)
        printf("%u\n",i);

    return 0;
}
