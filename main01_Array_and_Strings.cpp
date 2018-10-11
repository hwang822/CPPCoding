#include "stdafx.h" // for windows version
#include "cppcoding.h"

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
            if(nums[i]+nums[i+1]==target){
                rets.push_back(i);
                rets.push_back(i+1);

                return rets;            }
        }
    }
};

//1.1 Is Unique

bool isUniqueChars1(string str){
/*
    if(str.length()>128) return false;
    bool *char_set = new bool[128];
    memset(char_set, false, 128);

    char chr = str[0];
    int ichr = str[0];


    for(int i = 0; i < str.length(); i++){
        int var = str.at(i);
        if(char_set[var]==true)
            return false;
        char_set[var] = true;
    }
*/
    return true;
}

//1.2 Check Permutation
string sort(string s){
    //s.sort(s.begin(), s.end);
    return s;
}

bool permutation(string s, string t){
    if(s.length()!=t.length())
        return false;
    //if(sort(s).equals(sort(s)))
    //    return true;
}

//1.3 URLify

void replaceSpaces(char str[], int length){
    int spaceCount = 0, newLength, i;
    for(i=0; i<length; i++){
        if(str[i]==' '){
            spaceCount++;
        }
    }

    newLength = length + spaceCount*2;
    str[newLength] = '\0';

   for(i=length-1; i>=0; i--){
       if(str[i]==' '){
           str[newLength-1] = '0';
           str[newLength-2] = '2';
           str[newLength-3] = '%';
           newLength = newLength-3;
       } else {
           str[newLength-1] = str[i];
           newLength = newLength-1;
       }

   }
   return;
}

//1.8. Zero Martrix Write an algorithm such that if an elemetn in an MxN matrix is 0

const int rows = 8;
const int cols = 9;
void setZeros(int matrix[rows][cols]){

    int minRow = 0, maxRow = 0, minCol = 0, maxCol = 0;

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(matrix[i][j]==0){
                if(minRow==0)
                    minRow = i;
                maxRow = i;
                if(j < minCol)
                    minCol = j;
                if(j > maxCol)
                    maxCol = j;
            }

        }
    }

    for(int i = minRow; i<=maxRow; i++){
        for(int j = minCol; j<=maxCol; j++){
            matrix[i][j]=0;
        }
    }

}



int main01(){

//    replaceSpaces("h  en ry        ", 8);
    cout << permutation("henry", "yrneh");

    bool ret = isUniqueChars1("henrywang");
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );

//    vector<int> nums = new vector<int>(){1,2,3};
    TwoUsm tm;
    vector<int> ret1 =  tm.twosum(nums, 17);
    return 0;
}


//1.9 string rotation:
