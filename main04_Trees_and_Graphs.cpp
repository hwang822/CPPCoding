#include "stdafx.h" // for windows version
#include "cppcoding.h"
#include <string>
#include <list>
#include <Windows.h>
using namespace std;

//Binary Sort Trees


int countNodes(Node *root){


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

bool treeContains(Node *root, int item){
    if(root==NULL){
        return false;
    }
    else if (item == root->key) {
        return true;
    }
    else  {
        return treeContains(root->left, item) || treeContains(root->right, item);
    }

}

void inorderPrint( Node *root ) {
   if ( root != NULL ){  // (Otherwise, there's nothing to print.)
      inorderPrint( root->left );    // Print items in left subtree.
      cout << root->key << " ";     // Print the root item.
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


//4.1 Route Between Nodes.

int hasRoute(Node *root, int x, int y)
{
	if (root)
	{
		int count = 0;
		if ((root->key == x) || (root->key == y))
			count++;

		return count + hasRoute(root->left, x, y) +
			hasRoute(root->right, x, y);
	}
	return 0;
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

//4.2 Minmal Tree: Given a sorted (increasing order) array with unique interger elements, create BST with minimal height.
Node* createMinmalBSTFromSortedArray(int arr[], int start, int end){
    if(end < start){
        return NULL;
    }

    int mid = (start+end)/2;
    Node *n = new Node(arr[mid]);
    cout << arr[mid] << " " << endl;
    n->left = createMinmalBSTFromSortedArray(arr, start, mid-1);
    n->right = createMinmalBSTFromSortedArray(arr, mid+1, end);
}

//4.3 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the ndoes at each depth.
void getDepthArray(int* depths, int depth)
{
	for (int index = 0; index < depth; index++)
	{
		printf("%d ", depths[index]);
	}
	printf("\n");
}

void ListofDepthsRecur(Node* root, int *depths, int depth)
{
	if (!root)
		return;
	// append this node to the path array
	depths[depth] = root->key;
	depth++;
	if (root->left == NULL && root->right == NULL)
	{
		getDepthArray(depths, depth);
	}
	else
	{
		ListofDepthsRecur(root->left, depths, depth);
		ListofDepthsRecur(root->right, depths, depth);
	}
}


void ListofDepths(Node* root)
{
	int depth[1000];
	ListofDepthsRecur(root, depth, 0);
}


//4.4 Check Balanced:
#include <math.h>;

int getHeight(Node *root){
    if(root == NULL) return -1;
    return max(getHeight(root->left), getHeight(root->right))+1;
}

bool isBlanced(Node *root){    // a blanced tree is the heights of the two subtrees of any nodes never differ by more than one.
    if(root == NULL) return true;

    int heightDiff = abs(getHeight(root->left) - getHeight(root->right));
    if(heightDiff>1)
        return false;
    else
        return isBlanced(root->left) && isBlanced(root->right);
}


//4.5 Vaildate BST: Implement a fucntion to check if a binary three is binary search tree

bool checkBST(Node *n, int min, int max){
    if(n==NULL)
        return true;

    if((min!= NULL)&&(n->key<=min)||(max!= NULL)&&(n->key >=max))
        return false;
    if(!checkBST(n->left, min, n->key)||!checkBST(n->right, n->key, max))
        return true;
}

Node* CreateBTFromArray(int* values, int i, int n)
{
	Node* root = NULL;
	if (i<n)
	{ 
		root = new Node(values[i]);
		root->left = CreateBTFromArray(values, i*2+1, n);
		root->right = CreateBTFromArray(values, i * 2 + 2, n);
	}
	return root;
}


int main04(){

    int values[] = {1,4,7,8,9,10,23,45};
    int size = sizeof(values)/sizeof(values[0]);
	cout << endl;
	//          1
	//        /   \
	//       4     7
	//     /  \   /  \
	//    8    9 10  23
	//   /
	// 45

	Node* root = CreateBTFromArray(values, 0, size);
	inorderPrint(root);
	cout << endl;
	//4.1 Route Between Nodes.
	cout << "Route Between Nodes 4, 23 : " << hasRoute(root, 4, 23);

	//4.2 Minmal Tree: Given a sorted (increasing order) array with unique interger elements, create BST with minimal height.
    Node* node = createMinmalBSTFromSortedArray(values, 0, size-1);
	cout << "Minmal Tree : " << endl;
	inorderPrint(root);
	cout << endl;

	//4.3 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the ndoes at each depth.
	cout << "List of Depths: " << endl;
	ListofDepths(root);
    
	//4.4 Check Blanced:
	cout << "Check Blanced: " << isBlanced(root) << endl;

	//4.5 Vaildate BST: Implement a fucntion to check if a binary three is binary search tree
	cout << "Vaildate BST: " << checkBST(root, NULL, NULL) << endl;

	// Count nodes
	cout << "Count nodes of tree: " << countNodes(root) << endl;

	// Tree Contains value?
	cout << "Tree contain 4 ? " << treeContains(root, 4);


    return 0;
}
