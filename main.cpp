#include <iostream>

using namespace std;


#include <cppcoding.h>
#include <vector>>
#include <unordered_map>
#include <unordered_set>
vector<int> Vector(vector<int>& num){

    vector<int> res;
    for(int i=0; i<num.size(); i++){
        res.push_back(num[i]);
    }

    return res;
}

bool isUniqueChars(string str)
{
    for(int i=0; i< str.length(); i++)
        if(!(str.find(str[i])>=0))
            return false;
    return true;
/*
    unordered_map<int, char> mapList;

    for(int i=0; i<str.length(); i++){
        auto key = mapList.find(str[i]);
        if(key != mapList.end())
            return false;
        else
            mapList.insert(str[i], str[i]);
    }
*/

}

bool binarySearchRescursive(int a[], int x, int low, int high){

    if(low > high) return false;

    int mid = (low + high) /2;

    if (a[mid] < x){

        return binarySearchRescursive(a, x, mid+1, high);

    } else if ( a[mid] > x ){

        return binarySearchRescursive(a, x, low, mid-1);

    } else {
        cout << "found item at " << mid << endl;
        return true;
    }

}

const int M = 4;
const int N = 5;
bool RoadMap1(bool map[M][N], int M, int N, int m, int n){
    if((m<0)||(m>M)||(n<0)||(n>N)){
        return false;
    }
    if((m==M-1)&&(n==N-1))
        return true;

    if(map[m][n] == true)
        return false;
    else
        map[m][n] = true;

    if(RoadMap1(map, M, N, m+1, n)==false)
        RoadMap1(map, M, N, m, n+1);
}

int* MoveZeors(int nums[]){
    vector<int> nzero;
    for(int i=0; i<sizeof(nums)/sizeof(nums[0]); i++){
        if(nums[i]!=0)
            nzero.push_back(nums[i]);

    }
    return &nzero[0];
}

#include <algorithm>
#include <string>
bool isPermutationString(string str){

    int ihalf = sizeof(str)/2;
    string s1 = str;
    reverse(s1.begin(), s1.end());
    s1 = s1.substr(0, ihalf);
    string s2 = str.substr(0, ihalf);
    if(s1==s2)
        return true;
    else
        return false;
}

int MaximumSizeSubarraySumEqualsN(int nums[], int sum){

    for(int i=sizeof(nums)/sizeof(nums[0]); i>=1; i--){
        int curr = 0;
        for(int j=i-1; j>1;j--){
            curr = curr + nums[j];
            if(curr == sum)
               return j;
        }
    }
    return 0;
}

void findFibSubset1(int arr[], int n){
    int size = (sizeof(arr)/sizeof(arr[0]-1));

    int a = 0, b = 1, c;
    unordered_set<int> FisSet;
    FisSet.insert(a);
    FisSet.insert(b);

    for(int i = 0; i < size; i++){
        c = a + b;
        a = b;
        b = c;
        FisSet.insert(b);
    }

    for(int i=0; i<n; i++){
        if(FisSet.find(arr[i])!=FisSet.end())
            cout << arr[i] << endl;
    }
    return;
}


int main()
{
    mainfacebook();

//    mainleetcode();
    main01();
//    main02();
//    main03();
//    main04();
//    main05();
//    main06();
//    main07();
//    main08();
//    main09();
//    main10();
//    main11();
//    main12();

    return 0;
}

