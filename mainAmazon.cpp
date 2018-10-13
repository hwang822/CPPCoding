// CPPCoding.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" // for windows version
#include "cppcoding.h"
#include <map>
#include <iostream>
#include <string>

#include <algorithm>

using namespace std;
 

/*
Interview Prep Call: Upon a successful assessment we will then schedule a “prep call” as to better prepare you for your interview.
 
The onsite interview: The last leg of the process is the interview itself. You will meet with four seasoned Amazonians to discuss your experience, demonstrate coding, and system design expertise. Our interviews are held in the AM and PM so you will have a opportunity to schedule a time frame that works best for you.
 
I have also prepared the below links that will help you be successful on the assessment.
Programing interview prep https://www.youtube.com/watch?v=il_t1WVLNxk&list=PLqM7alHXFySGqCvcwfqqMrteqWukz9ZoE 
Amazon’s YouTube Channel - https://www.youtube.com/user/InsideAmazonVideos/videos -
CS Dojo YouTube channel is helpful for brushing up on Maps, Trees, Tables, and Algorithms. - https://www.youtube.com/channel/UCxX9wt5FWQUAAz4UrysqK9A -
Algorithms and Data Structures for interview preparation - https://www.youtube.com/watch?v=BchPukWb0CU 
 
*/
/*
//Question: Given a Binary, how will you find the vertical Sum of Binary Tree?

             1 (0)                 //For example, for this Binary tree it has 5 ferical lines. 
           /  	 \				    	For line 3 the sum will be: 1 +  5 + 7 = 13
	(-1) 2        3 (1)
		/  \     /  \
 (-2) 4  (0)5  7(0)  6 (2)

Using Horizontal Distance to define vertcial tree. root node is 0, left chird decrease 1, right child increase 1
using map (hash table put same HD node together.
			
we need to check the Horizontal Distances (HD) from root for all nodes

The idea is simple
HD for root is 0
for right child we will +1 (add 1) to HD
for left child we will -1 (subtract 1) from HD

We can easily maintain a hash map for horizontal distance corresponding to each vertical line.
Then, we can travese the binary tree and update our hash map.

start from root with HD 0 and add value of root to value of indxe 0 in map.

if we go left then decrease HD by 1 and update corresponding index's value in map.

if we go right then increase HD by 1 and update correspoinding index's value in map.

After travelsal we will have following map

	Horizontal Distance        Sum
	      -2					4
		  -1					2
		  0						13
		  1						3
		  2						6
*/
/*
struct Node {
	int key;
	Node *left, *right;
	Node(int i)
	{
		key = i;
		left = NULL;
		right = NULL;
	}

};
*/
void VerticalSumofBinaryTree1(Node *root, int key, map<int, int> &m)
{
	//Given a Binary Tree, find vertical sum of the nodes that are in 
	// same vertical line.Print all sums through different vertical lines.
	// using HD as key and the nodes summary of samee HD nodes as values

	if(root==NULL)
		return;
	
	if(m.find(key)!=m.end())
		m[key] = m[key]+root->key;
	else
		m.insert(pair<int, int>(key, root->key));
	VerticalSumofBinaryTree1(root->left, key-1, m);
	VerticalSumofBinaryTree1(root->right, key+1, m);
}

void VerticalSumofBinaryTree(Node *root, int key, map<int, int> &m)
{
   if ( root != NULL ){  // (Otherwise, there's nothing to print.)
	  cout << root->key << "("<< key << ")" << " ";	  

	  if(m.find(key)!=m.end())  // check hash table has same HD key, if no, add new one, if yes add on sum
		  m[key] = m[key] + root->key; // summary value
	  else
		  m.insert(pair<int,int>(key, root->key));   //add new value
  	  VerticalSumofBinaryTree( root->left, key-1, m);    // Print items in left subtree.	  
      VerticalSumofBinaryTree( root->right, key+1, m);   // Print items in right subtree.
   }

}

//Question: Given Binary tree, how will you find its maximum width?
//Solution1: Using hash map to story level (key) node number


//Question: How is map internally sotred
// Map in C++ STL is implemented using a self balancing binary search tree
//(typically Red Black Tree).
//This implementation ensures O(Log n) thime complexity for serach, insert and delete operations

//Question: N sutdients in a class play a game against each other where each
//studient plays against all other sudents in the class,
//find the toal number of matches to b connducted.
//Desing a suitable data structure ofr arrangeing hte sutdents an a line where each student would have
//lost the match with the student in front of him



// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
using namespace std;
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <vector>
class FindNodeDistanceatBST{
	int point;
	
	vector<int> path;
public:
	FindNodeDistanceatBST()
	{
		point = 0;
	}

    void createBST(int *values, int n, int index)
    {
        if(values==NULL)
            return;
        path.push_back(values[index]);
        if(index<n)
        {
            index++;
            if(values[index]>values[index-1])
            {
                createBST(values, n, index);
            }
            else
            {
                createBST(values, n, index);
            }
        }
        return;
    }

	int GetNextNode()
	{
		if(point>=path.size())
			point = 0;
		return path.at(point++);
	}
};

// FUNCTION SIGNATURE ENDS

//#0 Interview questions, how to find binary tree of this array tow nodes distance.  


// Function to insert nodes in level order 

Node* InsertNode(Node* node, int value)
{
	if (node == NULL)
		return new Node(value);

	if (value > node->key)
		node->right = InsertNode(node->right, value);
	else if (value < node->key)
		node->left = InsertNode(node->left, value);

	return node;
}

Node* CreateBSTfromArray(int valuse[],	int n)
{
	//	int values[6] = {5, 6, 3, 1, 2, 4};

	//          5
	//	  	  /  \
	//       3    6
	//	    /  \
	//     1    4 
	//      \
    //       2

	Node* root = NULL;

	for (int i=0; i < n; i++)
	{
		root = InsertNode(root, valuse[i]);
	}
	return root;
}

Node* CreateBTfromArray(int arr[],
	int i, int n)
{

	//	int values[6] = {5, 6, 3, 1, 2, 4};

	//          5
	//	  	  /  \
	//       6    3
	//	    / \  /
	//     1  2 4
	    
	Node* temp = NULL;
	// Base case for recursion 
	if (i < n)
	{
		temp = new Node(arr[i]); //add new nodes.
		// recursively create new nodes for left and right childs.

		// insert left child 
		temp->left = CreateBTfromArray(arr, 2 * i + 1, n);

		// insert right child 
		temp->right = CreateBTfromArray(arr, 2 * i + 2, n);
	}
	return temp;
}

int hasTwoItems(Node *root, int x, int y)
{
	if (root)
	{
		int count = 0;
		if ((root->key == x) || (root->key == y))
			count ++;

		return count + hasTwoItems(root->left, x, y) +
			hasTwoItems(root->right, x, y);
	}
	return 0;
}

bool hasItem(Node *root, int x)
{
	if (!root)
		return false;
	if (root->key == x)
		return true;
	if (hasItem(root->left, x) || hasItem(root->right, x))
		return true;
	else
		return false;
}

// Returns true if there is a path from root 
// to the given node. It also populates  
// 'arr' with the given path 
bool hasPath(Node *root, vector<int>& arr, int x)
{
	// if root is NULL 
	// there is no path 
	if (!root)
		return false;

	// push the node's value in 'arr' 
	arr.push_back(root->key);  //add path for this nodes. if no path at child nodes, remove this path

	// if it is the required node 
	// return true 
	if (root->key == x)
		return true;

	// else check whether the required node lies 
	// in the left subtree or right subtree of  
	// the current node 
	if (hasPath(root->left, arr, x) ||
		hasPath(root->right, arr, x))
		return true;

	// required node does not lie either in the  
	// left or right subtree of the current node 
	// Thus, remove current node's value from  
	// 'arr'and then return false     
	arr.pop_back(); 
	return false;
}
// Function to print tree nodes in 
// InOrder fashion 
void InOrder(Node* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->key << " ";
		InOrder(root->right);
	}
	return;
}

// PreOrder fashion 
void PreOrder(Node* root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
	return;
}

// PostOrder fashion 
void PostOrder(Node* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->key << " ";
	}
	return;
}

int btDistnace(int values[], int n1, int node1, int node2)
{
	Node* root = NULL;
	//int values[6] = { 5, 6, 3, 1, 2, 4 };
	root = CreateBTfromArray(values, 0, n1);
	//	int values[6] = {5, 6, 3, 1, 2, 4};

	//          5
	//	  	  /  \
	//       6    3
	//	    / \  /
	//     1  2 4

	
	InOrder(root);
	//1, 6, 2 ,5, 4, 3
	cout << endl;
	PreOrder(root);
	//5,6,1,2,3,4
	cout << endl;

	PostOrder(root);
	//1,2,6,4,3,5
	cout << endl;

	root = CreateBSTfromArray(values, n1);

	//	int values[6] = {5, 6, 3, 1, 2, 4};

	//          5
	//	  	  /  \
	//       3    6
	//	    /  \
	//     1    4 
	//      \
    //       2

	InOrder(root);
	cout << endl;
	// 1, 2 ,3, 4, 5, 6
	PreOrder(root);
	cout << endl;
	// 1, 2 ,3, 4, 5, 6
	PostOrder(root);
	cout << endl;
	// 1, 2 ,3, 4, 5, 6

	cout << "has 5: " << hasItem(root, 5) << endl;
	cout << "has 10: " << hasItem(root, 10) << endl;

	cout << "has 5 & 2: " << hasTwoItems(root, 5, 2) << endl;
	cout << "has 2 & 4: " << hasTwoItems(root, 2, 4) << endl;
	cout << "has 10 & 4: " << hasTwoItems(root, 10, 4) << endl;
	cout << "has 5 & 5: " << hasTwoItems(root, 10, 4) << endl;
	cout << "has 10 & -1: " << hasTwoItems(root, 10, -1) << endl;

	// vector to store the path
	vector<int> path1;
	vector<int> path2;
	int distance = 0;
	int sharedpath = 0;
	if (hasPath(root, path1, node1) && hasPath(root, path2, node2))
	{
		distance = path1.size() + path2.size();
		int minDis = min(path1.size(), path2.size());

		for (int index = 0; index < minDis - 1; index++)
		{
			if (path1[index] != path2[index])
				break;
			sharedpath++;
		}
	}


	distance = distance - sharedpath * 2;
	return distance;
}

/*
 * Main Contains Menu
 */



int mainAmazon()
{

	//#0 Interview questions, how to find binary tree of this array tow nodes distance.  

	int values[6] = {5, 6, 3, 1, 2, 4};
	int n1 = sizeof(values)/ sizeof(values[0]);
	int node1 = 2, node2 = 4;

	// build binar tree from data array.  first item is root then left, right winth index = 2i+1
//	          5
//			/   \
//		   6     3
//        /\    /
//       1	2  4 
	
	int idis = btDistnace(values, n1, node1, node2);
	cout << "\nAmazton Interview Test: \n" << idis << endl;

//	idis = bstDistance(values, n1, node1, node2);
//	cout << "\nAmazton Interview Test (bstDistnace): \n" << idis << endl;

	//#1
	cout << "\n#1 VerticalSumofBinaryTree:\n";
	map<int, int> m;

	Node *n = new Node(1);
	n->left = new Node(2);
	n->right = new Node(3);
	n->left->left = new Node(4);
	n->left->right = new Node(5);
	n->right->left = new Node(7);
	n->right->right = new Node(6);
    
	//Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

	//      1               0
	//     /  \           /   \
	//    2    3         -1    1
	//   / \   / \      / \   /  \
    //  4_   5  7  6  -2   0  0   2

/*
We need to check the Horizontal Distances from root for all nodes. 
If two nodes have the same Horizontal Distance (HD), then they are on same vertical line. 
The idea of HD is simple. HD for root is 0, a right edge (edge connecting to right subtree) 
is considered as +1 horizontal distance and a left edge is considered as -1 horizontal distance. 
For example, in the above tree, HD for Node 4 is at -2, HD for Node 2 is -1, 
//HD for 5 and 6 is 0 and HD for node 7 is +2.
*/
	//VerticalSumofBinaryTree(n, 0, m);
	VerticalSumofBinaryTree1(n, 0, m);
	cout <<"\n";
	int max  = 0;
	for(auto elem : m)
	{
		if(max<elem.second)
			max=elem.second;
	   cout << elem.first << " " << elem.second << "\n";
	}
	cout << "MixSum: " << " " << max << "\n";

	cout << "\n#2 FindBinaryTreeMaximumWidth:\n";
	m.clear();
	return 0;
}

// https://www.youtube.com/watch?v=BchPukWb0CU
// Algorithmas and data structures for interview preparation

