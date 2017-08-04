#include <iostream>
#include <vector>
using namespace std;

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

//2.
//Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of list, which contains the least-significant digit.
//https://leetcode.com/problems/add-two-numbers/solution/

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class AddList {
public:
/*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummyHead = new ListNode(0);
        ListNode p = l1, q = l2, curr = dummyHead;
        int carry = 0;
        while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }

    return dummyHead.next;
*/
};

int main()
{
    vector<int> vv;
    vv ={2, 7, 11, 15};
    TwoUsm sol;
    vector<int> vr;
    vr = sol.twosum(vv, 9);

    cout << "Hello World!" << endl;
    return 0;
}
