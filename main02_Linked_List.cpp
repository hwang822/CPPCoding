#include "stdafx.h" // for windows version
#include "cppcoding.h"

//2.

//Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of list, which contains the least-significant digit.

//https://leetcode.com/problems/add-two-numbers/solution/

// Definition for singly-linked list.

class AddList {

public:

    TreeNode* addTwoNumbers(TreeNode* l1, TreeNode* l2)
    {
        TreeNode *dummyHead = new TreeNode(0);

        TreeNode* p = l1;
        TreeNode* q = l2;
        TreeNode* curr = dummyHead;

        int carry = 0;

        while (p != NULL || q != NULL) {
            int x = (p != NULL) ? p->iItem : 0;
            int y = (q != NULL) ? q->iItem : 0;

            int carry = 0;

            int sum = carry + x + y;

            carry = sum / 10;

            curr->left = new TreeNode(sum % 10);
            curr = curr->left;
            if (p != NULL) p = p->left;
            if (q != NULL) q = q->left;
        }

        if (carry > 0) {
            curr->left = new TreeNode(carry);
        }

        return dummyHead->left;
    }

};

//2.1 Remove duplicates from unsorted linked list

void deleteDups(TreeNode*n){
    TreeNode *previous = NULL;
    while(n!=NULL){
/*
        if(contrains(n->iItem)){
            previous->left = n->left;
        } else {
            set.add(n->iItem);
            previous = n;
        }
*/
        n = n->left;
    }
}

// 2.2 print kth to last element of a sigle linked list
int printKthToLast(TreeNode *head, int k){
    if(head = NULL)
        return 0;
    int index = printKthToLast(head->left, k)+1;
    if(index==k){
        cout << k << " th to last node is " + head->iItem << endl;
    }
    return index;
}

// 2.3 delete mdidle node
bool deleteNode(TreeNode *n){
    if(n==NULL || n->left == NULL){\
        return false;
    }
    TreeNode *next = n->left;
    n->iItem = next->iItem;
    n->left = next->left;
    return true;
}

int main02(){

    AddList al;
    TreeNode *ret = al.addTwoNumbers(new TreeNode(10), new TreeNode(20));
    return 0;
}
