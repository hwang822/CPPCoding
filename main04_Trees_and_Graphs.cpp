#include "stdafx.h" // for windows version
#include "cppcoding.h"
#include <string>
#include <Windows.h>
using namespace std;

//Binary Sort Trees


int countNodes(TreeNode *root){


    if(root == NULL)
        return 0;

    else {
        int count = 1;
        count += countNodes(root->left);
        count += countNodes(root->right);
        return count;
    }
}

void preorderPrint(TreeNode *root){
    if(root!=NULL){
        cout << root->sItem << " ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }

}

bool treeContrins(TreeNode *root, string item){
    if(root==NULL){
        return false;
    }
    else if (item == root->sItem) {
        return true;
    }
    else if (item < root->sItem) {
             return treeContrins(root->left, item);
    }
    else{
        return treeContrins(root->right, item);
    }

}

void inorderPrint( TreeNode *root ) {
   if ( root != NULL ){  // (Otherwise, there's nothing to print.)
      inorderPrint( root->left );    // Print items in left subtree.
      cout << root->sItem << " ";     // Print the root item.
      inorderPrint( root->right );   // Print items in right subtree.
   }

} // end inorderPrint()


void treeInsert(TreeNode *root, string newItem){

    if(root == NULL){
        root = new TreeNode(newItem);
        return;
    }
    else if (newItem < root->sItem) {
        treeInsert(root->left, newItem);
    }
    else
        treeInsert(root->right, newItem);
}


// Expression Trees node is opr to return opr(left, right
double getValue(TreeNode *node){

    if((node->sItem != "+")&&(node->sItem != "-")&&(node->sItem != "*")&&(node->sItem != "/")){
        return atoi(node->sItem.c_str());
    }
    else{
        double leftVal = getValue(node->left);
        double rightVal = getValue(node->right);

        if(node->sItem == "+") return leftVal + rightVal;
        else if(node->sItem == "-") return leftVal - rightVal;
        else if(node->sItem == "*") return leftVal * rightVal;
        else if(node->sItem == "/") return leftVal / rightVal;
    }
}


//4.1 Route Between Nodes


bool search(TreeNode *start, TreeNode *end){

    if((start==NULL)||(end==NULL))
        return false;
    if(start==end)
    {
        cout << "connected!" << endl;
        return true;
    }
    if(search(start, start->left))
        return false;
    if(search(start, start->right))
        return false;
}

//4.2 Minimal Tree:
//TreeNode* createMinmalBST(int array[]){
//    return createMinmalBST(array, 0, sizeof(array)/sizeof(array[0])-1);}

TreeNode* createMinmalBSTFromUusortedArray(int arr[], int start, int end){
    if(end < start){
        return NULL;
    }

    int mid = (start+end)/2;
    TreeNode *n = new TreeNode(arr[mid]);
    if(arr[mid-1]<=arr[mid])
        n->left = createMinmalBSTFromUusortedArray(arr, start, mid-1);
    else
        n->right = createMinmalBSTFromUusortedArray(arr, mid+1, end);

}


TreeNode* createMinmalBSTFromSortedArray(int arr[], int start, int end){
    if(end < start){
        return NULL;
    }

    int mid = (start+end)/2;
    TreeNode *n = new TreeNode(arr[mid]);
    cout << arr[mid] << " " << endl;
    n->left = createMinmalBSTFromSortedArray(arr, start, mid-1);
    n->right = createMinmalBSTFromSortedArray(arr, mid+1, end);
}

//4.3 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the ndoes at each depth.

//4.4 Check Balanced:
#include <math.h>;

int getHeight(TreeNode *root){
    if(root == NULL) return -1;
    return max(getHeight(root->left), getHeight(root->right))+1;
}

bool isBlanced(TreeNode *root){
    if(root == NULL) return true;

    int heightDiff = abs(getHeight(root->left) - getHeight(root->right));
    if(heightDiff>1)
        return false;
    else
        return isBlanced(root->left) && isBlanced(root->right);
}


//4.5 Vaildate BST: Implement a fucntion to check if a binary three is binary search tree
//bool checkBST(TreeNode *n){
//    return checkBST(n, -1, -1);
//}

bool checkBST(TreeNode *n, int min, int max){
    if(n==NULL)
        return true;

    if((min!=-1)&&(n->iItem<=min)||(max!=-1)&&(n->iItem>=max))
        return false;
    if(!checkBST(n->left, min, n->iItem)||!checkBST(n->right, n->iItem, max))
        return true;
}




int main04(){

    int array[] = {1,4,7,8,9,10,23,45};
    int size5 = sizeof(array)/sizeof(array[0]);
    TreeNode* node = createMinmalBSTFromSortedArray(array, 0, size5-1);

    //createMinmalBSTFromUusortedArray

    return 0;
}
