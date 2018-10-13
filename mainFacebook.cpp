
#include "stdafx.h"
#include "cppcoding.h"
//#include <cppcoding.h>
#include <unordered_set>
#include <vector>
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <string>

//source GeeksForgeeks
//https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/

//Tree

//#1 InorderTravelTree and GetNextNode

// Facebook remote interviewer by zhouhui at 8/18/2017, 12PM CTS.
// 1. create inorder travel in a given binary tree.
// 2. create function to TreeNode* = getNextNode(TreeNode* root)

// soulution

//(a) Inorder (Left, Root, Right) : 4 2 5 1 3
//(b) Preorder (Root, Left, Right) : 1 2 4 5 3
//(c) Postorder (Left, Right, Root) : 4 5 2 3 1
// Breadth First or Level Order Traversal : 1 2 3 4 5

//             1
//		     /   \
//         2       3
//        / \
//      4    5
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
class FindNextNodeatBT{
	int point;
	vector<Node *> path;
public:
	FindNextNodeatBT()
	{
		point = 0;
	}

	void CreateInorderTavel(Node *root)
	{
		if(root==NULL)
			return;		
		CreateInorderTavel(root->left);
		path.push_back(root);
		CreateInorderTavel(root->right);
		return;
	}
	Node* GetNextNode()
	{
		if(point>=path.size())
			point = 0;
		return path.at(point++);
	}
};

class FBInterViewTest{
private:
    vector<Node*> lineoftreenode; //using vector in order as array for index to get item at(index)
    int point;
public:
    FBInterViewTest(){		
        point = 0;
    }
    void InorderTravelTree(Node* node){
		// first create travel nodes in the line then vist next of point and update point move forward.  
        if (node == NULL)
            return;
        /* first recur on left child */
        InorderTravelTree(node->left);
        /* then print the data of node */
        printf("Node: %d \n", node->key);
		// put nodes to the line at travel order.
        lineoftreenode.push_back(node);
        /* now recur on right child */
        InorderTravelTree(node->right);
    }

    Node* getNextNode(){
        if(point==lineoftreenode.size())
            return NULL;
        else {
			Node *next = lineoftreenode.at(point++); //get next travel nodes from line
			printf("Next Node: %d \n", next->key);
            return next;
        }
    }
};

//2. Find Minimum Depth of a Binary Tree
int FindMaxSummaryBranchOfABinaryTree(Node *root){
	if((root->right==NULL)&&(root->left==NULL))
		return root->key;
	if(root->right==NULL)
		return FindMaxSummaryBranchOfABinaryTree(root->left) + root->key;
	if(root->left==NULL)
		return FindMaxSummaryBranchOfABinaryTree(root->right) + root->key;
	return max(FindMaxSummaryBranchOfABinaryTree(root->left) + root->key,
		FindMaxSummaryBranchOfABinaryTree(root->right) + root->key);
}

int FindMinimumDepthOfABinaryTree(Node *root){

	// called on root = NULL, empty tree level = 0
    if(root==NULL)
        return 0;

	// Base case : Left Node, no chird, level = 1
    if((!root->left) && (!root->right))
        return 1;

	// if left subtree is NULL, rcure for right subtree, level = 1 pluse child level
    if(!root->left)
        return FindMinimumDepthOfABinaryTree(root->right) + 1;

	// if rgit subtree is NULL, recure for  the left subtree
    if(!root->right)
        return FindMinimumDepthOfABinaryTree(root->left) + 1;

	//this way need travel all tree branch
	// for both subtree is not NULL, secure left and right subtree and sleect min of both level
    return min(FindMinimumDepthOfABinaryTree(root->left),
               FindMinimumDepthOfABinaryTree(root->right)) + 1;

}

//#3 Convert Ternary Expression to a Binary Tree
void printTree(Node *root){
    if(!root)
        return;
	// using recursing
    cout<<root->key<<" ";
    printTree(root->left);
    printTree(root->right);

}


Node* ConvertTernaryExpressionToABinaryTree(string TExpr, int i)
{
    if(i>=TExpr.length())
        return NULL;

    Node* root = new Node(TExpr.at(i));
    i++;
	//a?b?c:d:e"
	//i=0 Node(a)
	// i=1 ?
	//  i=2 Node(b)
	//	 i=3 ? Node(c)
    //     Node(b)->left = Node(c)  
	//     Node(b)->right = Node(d)
	//     Node(a)->left = Node(b)
	//     Node(a)->right = Node(e)

    if((i<TExpr.length())&&(TExpr.at(i)=='?'))
        root->left = ConvertTernaryExpressionToABinaryTree(TExpr, i+1);
    else if (i<TExpr.length())
        root->right = ConvertTernaryExpressionToABinaryTree(TExpr, i+1);
    return root;
}

//Array

//#4
// move from (0,0) to (M,N) node with some balcked nodes.

const int M = 4;
const int N = 5;
bool RoadMap(bool map[M][N], int M, int N, int m, int n){

    if((m>=M)||(n>=N)){
        cout << "(" << m << "," << n << ") out of range." << endl;
        return false; // get out of (M, N) 
    }

    if ((m==M-1)&&(n==N-1)) {
        cout << "(" << m << "," << n << ") ended" << endl;
        return true; // get arrive (M, N) 
    }

    if(map[m][n]==true){
        cout << "(" << m << "," << n << ") visted or blacked" << endl;
        return false; //(m, n) empty
    }
    else
    {
        cout << "(" << m << "," << n << ") visted" << endl;
        map[m][n]=true; // (m, n) visted no need come back
    }

    bool found = false;
    if(m<M-1)
        found = RoadMap(map, M, N, m+1, n);  // get next setp at H move
    if(!found){
        if(n<N-1)
            found = RoadMap(map, M, N, m, n+1); // get next setp at V move
    }
    return found;
}

//#5 Remove Zeroes
// {0,1,0,3,12} => {1,3,12,0,0}

int* RemoveZeroes(int nmus[], int size){

	cout << "before \n ";
    for(int i = 0; i<size; i++){        
        cout  << " " << nmus[i];        
    }
	cout << "\n ";
    int iIndex = 0; //iIndex for the no zero of array       
    for(int i = 0; i<size; i++){
        if(nmus[i]!=0){
            nmus[iIndex++] = nmus[i];
        }
    }
    for(int i = iIndex; i<size; i++){
        nmus[i] = 0;
    }
	cout << "after \n ";
    for(int i = 0; i<size; i++){        
        cout  << " " << nmus[i];        
    }
	cout << "\n ";

    return 0;
}

//#6 Maximum Size Subarray Sum Equals n
int MaximumSizeSubarraySumEqualsN(int nums[], int size, int n){

    int maxSize = 0;
    int curr;
    for(int start=0; start<size; start++){
        curr = nums[start];
        if (curr==n) return 1;
        for(int end=start+1; end<size; end++){
            curr = curr + nums[end];
            if(curr==n)
                if(maxSize<(end-start+1))
                    maxSize=end-start+1;
        }
		if(maxSize!=0)
			return maxSize; //alread get maxisze and it is will get smaller sub size
    }
	return maxSize;

}

//#7 Inplace rotate square matrix by 90 degrees | Set 1
//对称array, 从两段向里， x=0->N-1-x, y=0->N-1-y. 4角对称 y=x, NxN  (x,x) .. (N-1-x, x)            (0,0)   .. (N-1, 0)
//                                                               .           .                  .           .
//                                                               .           .                  .           .
//                                                              (x,N-1-x) .. (N-1-x, N-1-x)    (0,N-1) .. (N-1, N-1)
/*Input
 1  2  3
 4  5  6
 7  8  9

Output:
 3  6  9
 2  5  8
 1  4  7 */

//
//y=x, divid half to
// x: 0->N/2
// y: x->N-1-x
// (x,y) <-- (y, N-1-x)
//   ^            |
//   |            |
//   |            v
// (N-1-y,x) <-- (N-1-y, N-1-x)

//const int N = 4;

void displayMatrix(int mat[M][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

void Inplacerotatesquarematrixby90degrees1(int mat[][M]){
	displayMatrix(mat);
    int mat1[M][M] =
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
	
	for(int x = 0; x < M ; x++)
	{
		int start = x;
		for(int y = 0; y < M ; y++)
		{
			mat1[M-y-1][start] = mat[x][y];
		}
	}
	displayMatrix(mat1);
}

void Inplacerotatesquarematrixby90degrees(int mat[][M]){
    // Consider all squares one by one
	displayMatrix(mat);
    for (int x = 0; x < M / 2; x++)
    {
        // Consider elements in group of 4 in
        // current square
        for (int y = x; y < M-x-1; y++)
        {
            // store current cell in temp variable
            int temp = mat[x][y];

            // move values from right to top
            mat[x][y] = mat[y][M-1-x];

            // move values from bottom to right
            mat[y][M-1-x] = mat[M-1-x][M-1-y];

            // move values from left to bottom
            mat[M-1-x][M-1-y] = mat[M-1-y][x];

            // assign temp to left
            mat[M-1-y][x] = temp;
        }
    }
    displayMatrix(mat);
}

//8. Largest subset whose all elements are Fibonacci numbers
// 先将 通过算式 产生的 keys 存放在 hash tabe 如 fis, max, coustant, combing vause. 然后再从 nums compare hash table

void findFibSubset(int arr[], int n){


    // Find maximum Fibonacci element in arr[]
	//The Fibonacci Numbers are the numbers that every number after the first two is the sum of the two preceding ones.

    int max = *std::max_element(arr, arr+n);

    // Generate all Fibonacci numbers till
    // max and store them in hash.
    int a = 0, b = 1;
    unordered_set<int> hash;
    hash.insert(a);
    hash.insert(b);
    while (b < max)
    {
        int c = a + b;
        a = b;
        b = c;
        hash.insert(b);
    }
	cout <<"Fibonacci numbes set: ";
    // Npw iterate through all numbers and
    // quickly check for Fibonacci using
    // hash.
	for(int i=0; i<n; i++)
	{
		if (hash.find(arr[i]) != hash.end())
		{
			printf("%d ", arr[i]);
		}
	}
	cout <<"\n";
}

//#9. Largest Rectangular Area in a Histogram

int LargestRectangularAreaInAHistogram(int bars[], int size){
    int maxArea = 0;
    if(size<2)
        return maxArea;
    int max = *std::max_element(bars, bars+size);
    int area = 0;
    for(int bar = max; bar>=1; bar-- ){
        area = 0;
        for(int index=0; index<size; index++){
            if(bars[index]>=bar){
                area = area + bar;  // conitnue same size area
                if(area > maxArea)
                    maxArea = area;  
            }
            else
                area = 0;  // discontinue same size area 
        }
    }
    return maxArea;
}

//#10. Smallest subarray with sum greater than a given value

int SmallestSubarrayWithSumGreaterThanAGivenValue(int nums[], int size, int n){
	// initialize length of smallest subarray as size+1

    int smallest = size+1;

    //Pick every element as starting point
    for(int start=0; start<size; start++){
		//Initialize sum starting with current start
		int curr = nums[start]; 

		//if first element itself is greater 
        if (curr>n) return 1;
		// try different ending points for current start
        for(int end=start+1; end<size; end++){
			//add last element to current sum
            curr = curr + nums[end];
			//if sum becodes more than n and length of this subbary is smaller than curretn smallest length, update smallest length

            if(curr>n) 
                if(smallest>(end-start+1))
				{
                    smallest=end-start+1;
				}
        }
    }

    return smallest;
}

//#11. Find Subarray with given sum

int FindSubarrayWithGivenSum(int nums[], int size, int n){
    int curr = 0;
    for(int start=0; start<size; start++){
        curr = nums[start];
        for(int end=start+1; end<size; end++){
            if(curr==n){
                printf("find item equal sum between index %d and %d", start, end);
                return 1;
            }
            if((curr > n) || (end == size))
                break; //no more forward
            curr = curr + nums[end];

        }
    }
    printf("No subarry found");
    return 0;
}

//#12 Find All Triplets with zero sum

void FindAllTripletsWithZeroSum(int nums[], int size){

	//pick three items to check sum = 0
//Input : arr[] = {0, -1, 2, -3, 1}
//Output : 0 -1  1 and 2, -3, 1
    for(int i=0; i<size; i++){   
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                if(nums[i] + nums[j] + nums[k]==0)
                    printf("sum zeor at %i, %i, %i\n", nums[i], nums[j], nums[k]);
            }
        }
    }

//Time Complexity : O(n3)
//Auxiliary Space : O(1)

}

void FindAllTripletsWithZeroSumSuingHashtable(int nums[], int size){

	//pick three items to check sum = 0
//Input : arr[] = {0, -1, 2, -3, 1}
//Output : 0 -1  1 and 2, -3, 1    
	for(int i=0; i<size-1; i++){   
		unordered_set<int> s;
        for(int j=i+1; j<size; j++){
			int temp = -(nums[i] + nums[j]);
			if(s.find(temp)!= s.end())
			{   //find previous two number sum in negitive value
				cout<<"sum 0 at "<<temp<<","<<nums[i]<<","<<nums[j]<<endl;  
			}
			else
				s.insert(nums[j]);
        }
    }

//Time Complexity : O(n2)
//Auxiliary Space : O(n)
}

//#13 Check The sum of 2 elements in an array equal to X
// first make array to hash table to make the data softed for small to big.

bool findSum(int B[], int X, int n){
	// compare 8 => 5+3
	// {1, 5, 4, 4, 3, 8} = > {1, 3, 4, 4, 5, 8};
	int *sortArrry = B;
	sort(sortArrry, sortArrry+n);

    int i = 0;
    int j = n-1;

    while(i<j){
        int x = sortArrry[i] + sortArrry[j]; // get sum
        if(x == X)  //found sum eq x
            return true;
        if(x > X )   // sum > X reduce big nubmer at right
            j--;
        if(x < X)
            i++;     // sum < X increase small nubmer at left

    }
    return false;


}

//#14 Median in a stream of intergers (running intergers)


int MedianInAStreamOfIntergers(int nums[], int size){

    //sort number {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4}
    //            {1, 2,  3, 4, 5, 6, 7, 8,  9, 10, 11, 15} => (6+7)/2 = 6
	// size 12 is even number,  select 6, 7 average as median (6+7)/2 = 6.5

	// if{1, 2,  3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 16}
	// size 13 is odd number, select (size+1)/7 = 5th number 7 is median number


    // push data nums heap to make the data sorted queue
	int *sortArray = nums;
	sort(sortArray, sortArray + size);

    //vector<int> v(nums,nums+size);
    //make_heap (v.begin(),v.end());
    //cout << "initial max heap   : " << v.front() << '\n';

    if(size%2)
        return sortArray[(size+1)/2-1]; //odd
    else
        return ((sortArray[size/2-1]+sortArray[size/2])/2); //even number

    for (unsigned i=0; i<size; i++)
      cout << ' ' << sortArray[i];
    cout << '\n';


}


//String

//#15 Returns decimal value of roman numaral
//Program to convert Roman Numerals to Numbers
// This function returns value of a Roman symbol
// This feature of Roman numerals is called subtractive notation. 
// The numbers from 1 to 10 (including subtractive notation for 4 and 9) 
// are expressed in Roman numerals as follows: I, II, III, IV, V, VI, VII, VIII, IX, X
//Symbol value
//	I		1			
//  V		5
//	X		10
//	L		50
//	C		100
//	D		500
//	M		1000

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int romanToDecimal(string &str)
{
	
	//preChr>=postChr add up preChr otherwise add up postChr-preChr
    // Initialize result
    int res = 0;
	
    // Traverse given input
    for (int i=0; i<str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);

        if (i+1 < str.length())
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i+1]);

            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol is greater
                // or equal to the next symbol
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++; // Value of current symbol is
                     // less than the next symbol
            }
        }
        else
        {
            res = res + s1;
            i++;
        }
    }
    return res;
}



//#16 Converting Decimal Number Lying Between 1 to 3999 to Roman Numberals

string intToRoman(int num) 
{   

     // storing roman values of digits from 0-9 
     // when placed at different places
     string m[] = {"", "M", "MM", "MMM"};

     string c[] = {"", "C", "CC", "CCC", "CD", "D", 
                        "DC", "DCC", "DCCC", "CM"};
     string x[] = {"", "X", "XX", "XXX", "XL", "L", 
                        "LX", "LXX", "LXXX", "XC"};
     string i[] = {"", "I", "II", "III", "IV", "V", 
                        "VI", "VII", "VIII", "IX"};

     // Converting to roman
     string thousands = m[num/1000];
     string hundereds = c[(num%1000)/100];
     string tens =  x[(num%100)/10];
     string ones = i[num%10];

	 string ans = "";
	 

	 ans = thousands + hundereds + tens + ones;
	 
     return ans;
}

//#17 Look-and-Say Sequence.  n’th iterm in generated by reading (n-1)’ith term.
#include <string>

string getString(string sSeg){
    string sTemp = "";
    int iCount = 0;
    int i = 0;
    char prv;
    for(i=0; i<sSeg.length();i++){
        if(i==0)
        {
            prv = sSeg[i];
            iCount++;
        }
        else
        {
            if(prv!=sSeg.at(i)){
               sTemp = sTemp + to_string(iCount) + prv;
               iCount = 1;
               prv = sSeg.at(i);
            }
            else {
                iCount++;
            }
         }
    }
    sTemp = sTemp + to_string(iCount) + prv;
	
    return sTemp;
}

string Look_and_Say_Sequence(int n){

    string sReg = "";
    int iCount = 0;
    for(int j=1; j<=n; j++){
        if(j==1)
		{
            sReg = "1";  //1=>1		    
			cout << "[0]count of 1 at empty pre => "<< sReg<< "\n ";
		}
        else if(j==2)
		{
            sReg = "11"; //2=>11
			cout << "[1](count of 1 at pre 1 => "<< sReg<< "\n ";
		}
        else
		{
			string pre = sReg;
            sReg = getString(sReg);		
			cout << "(count of 1 at pre) + "<<pre<<" => " << sReg <<"\n";
		}
    }
    return sReg;
}



//#18. Find if string is K-Palindrome or not
/*
Input : String - abcdecba, k = 1
Output : Yes
String can become palindrome by remo-
-ving 1 character i.e. either d or e)


Input  : String - abcdeca, K = 2
Output : Yes
Can become palindrome by removing
2 characters b and e.

Input : String - acdcb, K = 1
Output : No
String can not become palindrome by
removing only one character.
*/

bool isKPal1(string str, int k){
	string revstr = str;
	int mid = str.length()/2;
	string left = "";
	string right = "";
	reverse(revstr.begin(), revstr.end());
	left = str.substr(0, mid);
	right = revstr.substr(0, mid);
	while(mid>0)
	{
		if(left==right)
			return true;
		else if (k>0)
		{
			k--;
		}
		else
		{
			return true;
		}
		mid--;
		left = left.substr(0, mid);
		right = right.substr(0, mid);

	}


	return false;
}


bool isKPal(string str, int k){
	isKPal1(str, k);
    int n = str.length();
    string revstr = str;
    reverse(revstr.begin(), revstr.end());
    string left =  "";
    string right = "";

    int mid = n/2;

    left = str.substr(0, mid);
    right = revstr.substr(0, mid);

    while(mid>0)
    {
        if(left==right)
            return true;
        else
            if(k>0)
               k--;
            else
               return true;
        mid--;
        left = left.substr(0,mid);
        right = right.substr(0,mid);

    }
    return false;
}

//#19 Multiply Large Numbers represented as Strings
/*
Input : num1 = 4154  
        num2 = 51454
Output : 213739916 

Input :  num1 = 654154154151454545415415454  
         num2 = 63516561563156316545145146514654 
Output : 41549622603955309777243716069997997007620439937711509062916
string MultiplyLargeNumbersRepresentedAsStrings1(string num1, string num2){
	//coded by mysefl
	
			4154
         x 51454
		----------
		  4154x4
        4154x50
	  4154x400
    4154x1000
+ 4154x50000
-----------------



*/

string MultiplyLargeNumbersRepresentedAsStrings1(string num1, string num2){


	
	
	string strres = "";
	int num2size = num2.size();
	int num1size = num1.size();
	int resultsize = num1size+num2size;

    if (resultsize == 0)
       return "0";
	char *result = new char[resultsize];
	memset(result,'0',resultsize);
	int num = 1;
	int index = resultsize-1;
	int adj = 0;
	for(int i = num2size-1; i>=0; i--)
	{		
		index = resultsize-1 - adj;
		int mutip = num2[i]-'0';
		int carry = 0;		
		for(int j = num1size-1; j>=0; j--)
	    {			
			int premutip = num1[j]-'0';
			int res = premutip*mutip;			
			
			res = res + carry;

			if(res>10)
			{
				carry = res/10;			
				res = res-carry*10;
			}
			else
				carry = 0;
			int addon = res + (result[index]-'0');
			int addcarry  = 0;
			addcarry = addon/10;
			addon = addon - addcarry*10;
			result[index] = char(addon+'0');
			addcarry = addcarry + (result[index-1]-'0');
			result[index-1] = char(addcarry + '0');
			index--;
		}
		result[index] = char(carry + '0');
		adj++;
	}
	strres = string(result).substr(0,num2size+num1size);
	if(strres.at(0)=='0')
		strres.replace(0,1,"");
	
	
	return strres;
}

string MultiplyLargeNumbersRepresentedAsStrings(string num1, string num2){
    // Multiplies str1 and str2, and prints result.
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";

    // generate the result string
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;

}

//#20 Boggle

/*
Find all possible words that can be formed by a sequence of adjacent characters
Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS
         QUIZ
*/

const int N1 = 3;

bool Boggle1(char boggle1[N1][N1], char *dictionary[], int size){
	unordered_set<char> chars;  //Code by my self

	for(int i= 0; i<N1;i++)
		for(int j= 0; j<N1;j++)
		{
			chars.insert(boggle1[i][j]);
		}

	for(int i = 0; i<size; i++)
	{		
		bool nofound = false;
		string name = dictionary[i];
		for(int j=0; j<name.size(); j++)
		{
			char chr = name[j];
			if(chars.find(chr)==chars.end())
			{
				nofound = true;
				break;
			}
		}
		if(nofound==false)
			cout<<name<<endl;

	}
    return true;
}

bool Boggle(char boggle[N1][N1], char *dictionary[], int size){
	Boggle1(boggle, dictionary, size);

    bool visted[3][3];

    for(int i = 0; i<size; i++){
        string sDir = dictionary[i];
        bool found = false;
        for(int j=0; j<sDir.length();j++){
            char chr = sDir[j];
            found = false;
            memset(visted, false, sizeof(bool)*N1*N1);
            for(int k = 0; k<N1; k++){
                for(int l = 0; l<N1; l++){
                    if((boggle[k][l]==chr)&&(visted[k][l]==false)){
                        visted[k][l] = true;
                        found = true;
                        break;
                    }
                }
                if(found == true)
                    break;
            }
            if(found == false)
               break;
        }
        if(found == true)
            cout << sDir << " found in boggle." << endl;

    }
    return true;
}


//#21 Count Possible Decodings of a given Digit Sequence.
int countDecoding(char *digits, int n){
    if(n==0 ||n==1)
        return 1;
    int count = 0;
    if(digits[n-1] > '0')
        count = countDecoding(digits,n-1);
    if(digits[n-2] == '1'|| (digits[n-2]=='2' && digits[n-1] < '7' ))
        count += countDecoding(digits, n-2);
    return count;
}

int countDecoding1(char *digits, int n){
	//"1234"  1-26 for A-Z  design by myself
	int count = 0;
	for(int index = 0; index<n-1; index++)
	{
		int data = (digits[index]-'0')*10 + (digits[index+1]-'0');
		if((data<=26)&&(data>=1))
		{
			count++;
		}
	}
	if(n>=0)
		count++;
	return count;
}


//#22 find [0,1] string maximum value uing + or *.
// "012340" => (0 + 1 + 2)*3*(4+0) = 36
int calcMaxValue(string str){

    int res = str[0] - '0';
    for(int i=1; i<str.length();i++){
        if((str[i]=='0') || (str[i]=='1') || (str[i-1]=='0') || (str[i-1]=='1'))
            res += str[i] - '0';  // if string begin or end with 0 or 1 only for no change value to other
        else                      // the string 0 or 1 will only + with other neigbor.
            res *= str[i] - '0';
    }
    return res;
}


int mainFacebook(){

cout<< "\nFacebook Interview Test\n";
//Tree
//#1

//(a) Inorder (Left, Root, Right) : 4 2 5 1 3
//(b) Preorder (Root, Left, Right) : 1 2 4 5 3
//(c) Postorder (Left, Right, Root) : 4 5 2 3 1
// Breadth First or Level Order Traversal : 1 2 3 4 5

//             1
//		     /   \
//         2       3
//        / \
//      4    5

	cout<< "\n#1 FBInterViewTest: Inorder travel at BT and GoToNext: \n";
    Node *root = new Node(1);
    root->left  = new Node(2);
    root->right = new Node(3);
    root->left->left  = new Node(4);
    root->left->right  = new Node(5);

	FBInterViewTest *fbin = new FBInterViewTest();
	fbin->InorderTravelTree(root);
	fbin->getNextNode();	
	fbin->getNextNode();	
	cout << "Inorder (Left, Root, Right) : 4 2 5 1 3" << endl;

	FindNextNodeatBT *fbin1 = new FindNextNodeatBT();
	fbin1->CreateInorderTavel(root);
	fbin->getNextNode();

//#2. Find Minimum Depth of a Binary Tree

//            1         level = 0
//          /   \
//		  2       3     level = 1
//      /   \
//    4      5          level = 2

	cout << "\n#2 max summary branch of BT = " << FindMaxSummaryBranchOfABinaryTree(root) <<endl; // 5 + 2 + 1 = 8
	cout << "\n#2 min tree depth = " << FindMinimumDepthOfABinaryTree(root) <<endl; // level = 2

//#3 Convert Ternary Expression to a Binary Tree
/*
Input :  string expression =   a?b:c 
Output :        a
              /  \
             b    c

Input : expression =  a?b?c:d:e
Output :     a
           /  \
          b    e
        /  \
       c    d	
*/
    string expression = "a?b?c:d:e";

    root = ConvertTernaryExpressionToABinaryTree(expression, 0);
    printTree(root);


//Array

//#4
	cout << "\n#4 RoadMap: (0,0)->(0,1)->->(0,2)->(0,3)[X]->(1,2)->->(1,3))->(1,4)->->(2,4)->(3,4) \n";

	bool map[M][N] = {{false,false,false,false,false},{false,false,false,false,false},
                      {false,false,false,false,false},{false,false,false,false,false}};

	//   * * *   * 
	//   * * * * * 
	//   * * * * *  
	//   * * * * * 

    map[3][0] = true;
    RoadMap(map, 4, 5, 0, 0);


//#5
	int nums[] = {0,1,0,3,12};
	cout << "\n#5 RemoveZeroes: {0,1,0,3,12} => {1,3,12,0,0}\n";    
    RemoveZeroes(nums, sizeof(nums)/sizeof(int));

//#6 	

	//1,-1 = 0
	//1,-1, 5 = 5
	//1,-1, 5, -2 = 3 => size = 4
	//1,-1, 5, -2, 3 = 6
	//do not resize to small

    int msize = MaximumSizeSubarraySumEqualsN(nums, 5, 3);
	cout <<"\n#6 {1,-1,5,-2,3} sum = 3, Max size at [1,-1, 5, -2]: \n" << msize << endl;

//#7
	cout << "\n#7 Run array 90 deg: \n";
    int mat[M][M] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
	//=>
    int mat1[M][M] =
    {
        {4, 8, 12, 16},
        {3, 7, 11, 15},
        {2, 6, 10, 14},
        {1, 5, 9, 13}
    };


    //Inplacerotatesquarematrixby90degrees(mat);
	
	Inplacerotatesquarematrixby90degrees1(mat);


//#8 
	cout<<"\n#8 findFibSubset: {4, 2, 8, 5, 20, 1, 40, 13, 23}\n";
    int arr[] = {4, 2, 8, 5, 20, 1, 40, 13, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    findFibSubset(arr, n);

//#9
    int bar[] = {6, 2, 5, 4, 5, 1, 6};  //=> Max area = 6x1
	printf("\n#9 MaxArea %d\n", LargestRectangularAreaInAHistogram(bar, sizeof(bar)/sizeof(bar[0])));

//10. Smallest subarray with sum greater than a given value
    int arrs[] = {15, 2, 4, 8, 9, 5, 10, 23};
	//[15] 
	cout <<"\n#10 Smallest subarray {15, 2, 4, 8, 9, 5, 10, 23} with sum greater than a given value 50: \n";
	cout << SmallestSubarrayWithSumGreaterThanAGivenValue(arrs, sizeof(arrs)/sizeof(arrs[0]), 50)<<endl;

//11. Find Subarray with given sum
	cout<<"\n#12 Find Subarray {15, 2, 4, 8, 9, 5, 10, 23} with given sum 23: \n";
    FindSubarrayWithGivenSum(arrs, sizeof(arrs)/sizeof(arrs[0]), 23);

//12 Find All Triplets with zero sum
	int arr1[] = {0, -1, 2, -3, 1};

    FindAllTripletsWithZeroSum(arr1, sizeof(arr1)/sizeof(arr1[0]));
	FindAllTripletsWithZeroSumSuingHashtable(arr1, sizeof(arr1)/sizeof(arr1[0]));

//#13
// Check The sum of 2 elements in an array equal to X
// first make array to hash table to make the data softed for small to big.
	cout<<"\n#13 Check The sum of 2 elements in an array equal to X\n";

    int A1[] = {1, 5, 4, 4, 3, 8};
    findSum(A1, 8, 6);

//14
	cout<<"\n#14 Median in Integer stream\n";
    int even[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	int odd[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4, 16};
    int size = sizeof(even)/sizeof(even[0]);
	
    cout << "Mdeian {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4} = " << MedianInAStreamOfIntergers(even, size) << endl;
	size = sizeof(odd)/sizeof(odd[0]);
	cout << "Mdeian {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4, 16} = " << MedianInAStreamOfIntergers(odd, size) << endl;

//string

//#15

    string str ="MCMIV";
	cout << "\n#8 Integer form of Roman Numeral is \n"
//	I		1			
//  V		5
//	X		10
//	L		50
//	C		100
//	D		500
//	M		1000

//convert => preChr>=postChr add up preChr otherwise add up postChr-preChr
// 1000(M>C) + (1000-100)(C<M) + 1000(M>I) +(5-1)(I<V) =>1904
         << romanToDecimal(str) << endl;

//#16 Converting Decimal Number Lying Between 1 to 3999 to Roman Numberals
	cout << "\n#16 3999 to Roman Numberals: " << intToRoman(3999) << "\n";

//#17 (count of pre 1) > count + pre

	//0=>1
	//1=>11
	//2=>2(count 1)=>21
	//3=>1(count 1 of 21)=>121
	//4=>1(count 1 of 121)=>121
	//5=>"111221"

	cout << "\n#17 number 5 gerenatd: ";
    cout << Look_and_Say_Sequence(5) << "\n";

//#18
	cout << "\n#18 IsKPal: " << "\n";
    cout << isKPal("abcdecba", 1) << endl;
    cout << isKPal("abcdeca", 2) << endl;
    cout << isKPal("acdcb", 1) << endl;


//#19
	cout << "\n#19 Big x Big: " << "\n";
    string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
    //string str1 = "123";
    //string str2 = "45";

    cout << MultiplyLargeNumbersRepresentedAsStrings(str1, str2)<<endl;
	cout << MultiplyLargeNumbersRepresentedAsStrings1(str1, str2)<<endl;

//#20
	cout << "\n#20 boggle: " << "\n";
    char *dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
    int size1 = 4;

    char boggle[N1][N1]   = {{'G','I','Z'},
                    {'U','E','K'},
                    {'Q','S','E'}};

    Boggle(boggle, dictionary, size1);

//#21
	cout << "\n#21 count Decoding 1~26 => A~Z: " << "\n";
    char digits[] = "1234";
    int n2 = strlen(digits);
    cout << " count is " << countDecoding(digits, n2) << endl;

//#22
	cout << "\n#22 find [0,1] string maximum value uing + or *" << "\n";
	string str3 = "012340";
    cout << "Max number of " + str3 << " is " << calcMaxValue(str3) << endl;

	int choice;
	//cin>>choice;

    return 0;
}
