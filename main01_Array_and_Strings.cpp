#include <cppcoding.h>

//1.

//https://leetcode.com/problems/two-sum/description/

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

#include <vector>

class TwoUsm {

public:



    vector<int> twosum(vector<int>& nums, int target) {



        vector<int> rets;



        for(int i=0; i<sizeof (nums)-1; i++ )

        {

            if(nums[i]+nums[i+1]==target)

            {

                rets.push_back(i);

                rets.push_back(i+1);

                return rets;            }

        }



    }

};

int main01(){

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

//    vector<int> nums = new vector<int>(){1,2,3};
    TwoUsm tm;
    vector<int> ret =  tm.twosum(nums, 17);
    return 0;
}
