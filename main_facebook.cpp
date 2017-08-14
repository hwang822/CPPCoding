#include <cppcoding.h>

//283. Move Zeroes
int* MoveZeroes(int nmus[], int size){
    int iIndex = 0;        
    for(int i = 0; i<size; i++){
        if(nmus[i]!=0){
            nmus[iIndex++] = nmus[i];
        }
    }
    for(int i = iIndex; i<size; i++){
        nmus[i] = 0;
    }

}

//325 Maximum Size Subarray Sum Equals n
int MaximumSizeSubarraySumEqualsN(int nums[], int size, int n){

    int left = 0;
    int right = 0;
    for(int j=size; j>0; j--){
        for(int k = 0; k<=size-j; k++){
            int total = 0;
            for(int i=k; i<k+j; i++){
                total = total + nums[i];
            }
            if(total==n)
                return j;
        }
    }
}

int mainfacebook(){
    int nums[] = {0,1,0,3,12};
    MoveZeroes(nums, sizeof(nums)/sizeof(int));
    int nums1[] = {1,-1,5,-2,3};
    MaximumSizeSubarraySumEqualsN(nums1, sizeof(nums1)/sizeof(int), 3);

}
