#include "stdafx.h" // for windows version
#include "cppcoding.h"


//3.1 Three in One: use a signle array to implement three stacks.

class FixedMultiStack {
private:
    int numberofStatic = 3;
    int stackCapacity;
    int *values;
    int *sizes;

public:
    void FixeMultiStack(int stackSize){
        stackCapacity = stackSize;
        values = new int[stackSize*numberofStatic];
        sizes = new int[numberofStatic];
    }

    /* Push value onot stack */
    void push(int stackNum, int value){
        if(!isFull(stackNum)){
            sizes[stackNum]++;
            values[IndexOfTop(stackNum)] = value;
        }
    }

    int pop(int stackNum){
        if(!isEmpty(stackNum)){
            int value = values[IndexOfTop(stackNum)];
            values[IndexOfTop(stackNum)] = 0;
            sizes[stackNum]--;
            return value;
        }
    }

    int peek(int stackNum){
        if(!isEmpty(stackNum)){
            return values[IndexOfTop(stackNum)];
        }
    }

    bool isEmpty(int stackNum){
        return sizes[stackNum]==0;
    }

    bool isFull(int stackNum){
        return sizes[stackNum]==stackCapacity;
    }

    int IndexOfTop(int stackNum){
        int c = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return stackNum + size -1;
    }


};


//3.4 Queue via stacks

int main03(){

    return 0;
}
