// CPPCoding.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" // for windows version
#include "cppcoding.h"
#include <map>
#include <iostream>
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
//Question: Given a Binary, how will you find the vertical Sumb of Binary Tree?

             1 (0)                 //For example, for this Binary tree it has 5 ferical lines. 
           /  	 \				    	For line 3 the sum will be: 1 +  5 + 7 = 13
	(-1) 2        3 (1)
		/  \     /  \
 (-2) 4     5(0)     6 (2)
               /
			7(0)

we nned to check the Horizontal Distances (HD) from root for all nodes

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

	Horizontal Distance           Sum
	      -2					4
		  -1					2
		  0						13
		  1						3
		  2						6
*/

void VerticalSumofBinaryTree(Node *root, int key, map<int, int> &m)
{
   if ( root != NULL ){  // (Otherwise, there's nothing to print.)
	  cout << root->key << "("<< key << ")" << " ";	  

	  if(m.find(key)!=m.end())
		  m[key] = m[key] + root->key;
	  else
		  m.insert(pair<char,int>(key, root->key));
  	  VerticalSumofBinaryTree( root->left, key-1, m);    // Print items in left subtree.	  
      VerticalSumofBinaryTree( root->right, key+1, m);   // Print items in right subtree.
   }

}

//Question: Given Binary tree, how will you find its maximum width?
//Solution1: Using hash map to story level (key) node number

void FindBinaryTreeMaximumWidth(Node *root, int key, std::map<int, int> &m)
{
   if ( root != NULL ){  // (Otherwise, there's nothing to print.)
	    

	  if(m.find(key)!=m.end())
		  m[key] =  m[key]++;
	  else
		  m.insert(pair<char,int>(key, 1));
  	  FindBinaryTreeMaximumWidth( root->left, key+1, m);    // Print items in left subtree.	  
      FindBinaryTreeMaximumWidth( root->right, key+1, m);   // Print items in right subtree.
	  cout << root->key << "("<< key << ")" << " ";	
   }

	return;
}

//Question: How is map internally sotred
// Map in C++ STL is implemented using a self balancing binary search tree
//(typically Red Black Tree).
//This implementation ensures O(Log n) thime complexity for serach, insert and delete operations

//Question: N sutdients in a class play a game against each other where each
//studient plays against all other sudents in the class,
//find the toal number of matches to b connducted.
//Desing a suitable data structure ofr arrangeing hte sutdents an a line where each student would have
//lost the match with the student in front of him



/*
 * Main Contains Menu
 */
int mainAmazon()
{
	//#1
	cout<< "\nAmazton Interview Test\n";
	cout << "\n#1 VerticalSumofBinaryTree:\n";
	map<int, int> m;

	Node *n = new Node(1);
	n->left = new Node(2);
	n->right = new Node(3);
	n->left->left = new Node(4);
	n->left->right = new Node(5);
	n->right->left = new Node(7);
	n->right->right = new Node(6);
    
	
	VerticalSumofBinaryTree(n, 0, m);
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
	FindBinaryTreeMaximumWidth(n, 0, m);
	cout <<"\n";
	max  = 0;
	for(auto elem : m)
	{
		if(max<elem.second)
			max=elem.second;
	    cout << elem.first << " " << elem.second << "\n";
	}
	cout << "Mixwidth: " << " " << max << "\n";
	return 0;
}

// https://www.youtube.com/watch?v=BchPukWb0CU
// Algorithmas and data structures for interview preparation

