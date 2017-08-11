#include <cppcoding.h>

//1.

//https://leetcode.com/problems/two-sum/description/

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.



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

    return 0;
}
