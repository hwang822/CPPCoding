#include <cppcoding.h>

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
int main02(){

    return 0;
}
