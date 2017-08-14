#include <cppcoding.h>

#include <vector>

//1. Two array items Sum == target.

#include <unordered_map>

int* twoSum_hashmap(int nums[], int size, int n){
    unordered_map<int, int > map;
/*
    for(int i=0; i<size; i++){
        map.insert(nums[i], i);
    }

    for(int i=0; i<size; i++){
        int key = n-nums[i];
        auto comp = map.find(key);
        if(comp!=map.end())
        {
            int ret[2];
            //ret[0] = comp->first;
            //ret[1] = comp->second;
            return ret;
            //return new int[]{comp, i};
        }
    }

//    throw new exception();
    // Time O(n)
*/
    return NULL;
}

int* twoSum(int nums[], int size, int n){
    for(int i=0; i<size; i++)
        for(int j=i+1; j<size; j++){
            if((nums[i] + nums[j])==n)
                return new int[2]{i, j};
        }
    throw new exception();
    // time O(nxn), space O(1)
}

// add two numbers {2, 4, 3} + {5, 6, 4} => {7, 0, 8};
TreeNode* addTwoNumbers(TreeNode *one, TreeNode *two){
    TreeNode *thread = new TreeNode(0);
    TreeNode *curr = thread;
    int carry = 0;
    while((one!=NULL)||(two!=NULL)){
        int res = 0;
        if(one!=NULL){
            res = res + one->iItem;
            one = one->left;
        }
        if(two!=NULL){
            res = res + two->iItem;
            two = two->left;
        }

        res = res + curr->iItem;
        carry = res/10;
        curr->iItem = res;
        curr->left = new TreeNode(res/10);
    }
    return thread;
}


//3. Longest Substring Without Repeating Characters
string LongestSubstringWithoutRepeatingCharacters(string str){

    unordered_map<char, int > map;
    int n = str.length();
    int i=0, j=0, ans = 0;
    while(i<n&&j<n){
        char key = str.at(i);
        auto comp = map.find(key);
        if(comp!=map.end()){
            map.erase(key);
            i++;
        }
        else{
            map.insert({key, i});
            j++;
            if((j-i)>ans)
                ans = j-i;
        }


    }
}

//5. Longest Palindromic Substring
string LongestPalindromicSubstring(string str){
    int size = str.length();
    int longest = 0;
    int leftL = 0, rightL = 0;
    for(int i=0; i<size; i++){
        int left = i;
        int right = i;
        while((left>=0)&&(right<size)){
            if(str.at(left)==str.at(right)){
                if((right-left)>longest){
                    longest = right-left;
                    leftL = left,
                    rightL = right;
                }
                left--;
                right++;
            }
            else
                break;
        }
    }

    return str.substr(leftL, rightL-leftL+1);
}

//11. ContainWithMostWater
int* ContainWithMostWater(int nums[], int size){
    int max = 0, max1 = 0;
    for(int i=0; i<size; i++){
        if(nums[i]>=max)
        {
            max1 = max;
            max = nums[i];
        }
        else if((nums[i]>=max1) && (nums[i]<max))
            max1 = nums[i];
    }
    int water[2] = {max, max1};
    return water;
}

//14. Longest Common Prefix
string LongestCommonPrefix(string str[], int size){

    int length = 0;

    for(int i=0; i<size; i++){
        if(length==0)
            length = str[i].length();
        else if(str[i].length() < length )
        {
            length = str[i].length();
        }
    }

    unordered_map<string, int > map;
    int iIndex =0;
    for(int i=0; i<size; i++){
        for(int j=length; j>0; j--){
            string key = str[i].substr(0,j);
            auto found = map.find(key);
            if(found!=map.end())
                return key;
            //else
            //    map.insert(key, iIndex++);
        }
    }
}

//19. Remove Nth Node Form end of List
TreeNode* RemoveNthNodeFormEndofList(TreeNode *node, int N){
    if(node==NULL)
        return node;
    TreeNode * cur = node;
    TreeNode * removeNode = node;

    int remoteIndex = 0;
    while(cur->left!=NULL)
    {
        if(remoteIndex>=N)
            removeNode=removeNode->left;
        remoteIndex++;
        cur = cur->left;
    }
    if(remoteIndex>=N){
        removeNode->left = removeNode->left->left;
    }
    return node;
}

int mainleetcode(){
    int *iret;
    string sret = "";
    string sPrix[] = {"leets", "leetcode", "leet", "leeds"};
    //sret = LongestCommonPrefix(sPrix);
    int nums[] = {2, 16,2,77,29};
    iret = ContainWithMostWater(nums, 5);
    sret = LongestPalindromicSubstring("babad");
    sret = LongestSubstringWithoutRepeatingCharacters("henrywang");
    iret = twoSum(nums, 5, 31);
   // iret = twoSum_hashmap(nums, 5, 31);
}

