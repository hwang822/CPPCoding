
#include "stdafx.h"
#include "cppcoding.h"
//#include <cppcoding.h>
#include <unordered_set>
// Facebook remote interviewer by zhouhui at 8/18/2017, 12PM CTS.
// 1. create inorder travel in a given binary tree.
// 2. create function to TreeNode* = getNextNode(TreeNode* root)

#include <vector>>
class FBInterViewTest{

    vector<TreeNode*> tree;
    int point;
public:
    FBInterViewTest(){
        point = 0;
    }
    void InorderTravelTree(TreeNode* node){

        if (node == NULL)
            return;
        /* first recur on left child */
        InorderTravelTree(node->left);
        /* then print the data of node */
        printf("%d ", node->sItem);
        tree.push_back(node);
        /* now recur on right child */
        InorderTravelTree(node->right);
    }

    TreeNode* getNextNode(){
        if(point==tree.size())
            return NULL;
        else {
            return tree.at(point++);
        }
    }
};





// move from (0,0) to (M,N) node with some balcked nodes.

const int M = 4;
const int N = 5;
bool RoadMap(bool map[M][N], int M, int N, int m, int n){

    if((m>=M)||(n>=N)){
        cout << "(" << m << "," << n << ") out of range." << endl;
        return false;
    }

    if ((m==M-1)&&(n==N-1)) {
        cout << "(" << m << "," << n << ") ended" << endl;
        return true;
    }

    if(map[m][n]==true){
        cout << "(" << m << "," << n << ") visted or blacked" << endl;
        return false;
    }
    else
    {
        cout << "(" << m << "," << n << ") visted" << endl;
        map[m][n]=true;
    }

    //this way need travel only one path with tree branchs

    bool found = false;
    if(m<M-1)
        found = RoadMap(map, M, N, m+1, n);
    if(!found){
        if(n<N-1)
            found = RoadMap(map, M, N, m, n+1);
    }
    return found;
}

//283. Move Zeroes
int* MoveZeroes(int nmus[], int size){
    int iIndex = 0;        
    for(int i = 0; i<size; i++){
        if(nmus[i]!=0){
            nmus[iIndex++] = nmus[i];
        }
    }
    for(int i = iIndex; i<size; i++){
        nmus[i] = 0;
    }
    return 0;
}

//325 Maximum Size Subarray Sum Equals n
int MaximumSizeSubarraySumEqualsN(int nums[], int size, int n){

    int maxSize = 0;
    int curr;
    for(int i=0; i<size; i++){
        curr = nums[i];
        if (curr==n) return 1;
        for(int j=i+1; j<size; j++){
            curr = curr + nums[j];
            if(curr==n)
                if(maxSize<(j-i+1))
                    maxSize=j-i+1;
        }
    }

}

//GeeksForGeeks.org facebook

//1. Inplace rotate square matrix by 90 degrees | Set 1
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

void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

void Inplacerotatesquarematrixby90degrees(int mat[][N]){
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++)
    {
        // Consider elements in group of 4 in
        // current square
        for (int y = x; y < N-x-1; y++)
        {
            // store current cell in temp variable
            int temp = mat[x][y];

            // move values from right to top
            mat[x][y] = mat[y][N-1-x];

            // move values from bottom to right
            mat[y][N-1-x] = mat[N-1-x][N-1-y];

            // move values from left to bottom
            mat[N-1-x][N-1-y] = mat[N-1-y][x];

            // assign temp to left
            mat[N-1-y][x] = temp;
        }
    }
    displayMatrix(mat);
}

//2. Largest subset whose all elements are Fibonacci numbers
// 先将 通过算式 产生的 keys 存放在 hash tabe 如 fis, max, coustant, combing vause. 然后再从 nums compare hash table

#include <algorithm>
#include <unordered_set>

void findFibSubset(int arr[], int n){

    // Find maximum element in arr[]
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

    // Npw iterate through all numbers and
    // quickly check for Fibonacci using
    // hash.
    for (int i=0; i<n; i++)
        if (hash.find(arr[i]) != hash.end())
            printf("%d ", arr[i]);

    printf("\n");

}

//3. Largest Rectangular Area in a Histogram

int LargestRectangularAreaInAHistogram(int bars[], int size){
    int maxArea = 0;
    if(size<2)
        return maxArea;
    int max = *std::max_element(bars, bars+size);
    int area = 0;
    for(int i = max; i>=1; i-- ){
        area = 0;
        for(int j=0; j<size; j++){
            if(bars[j]>=i){
                area = area + i;
                if(area > maxArea)
                    maxArea = area;
            }
            else
                area = 0;
        }
    }
    return maxArea;
}

//4 Look-and-Say Sequence.  n’th term in generated by reading (n-1)’th term.
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
            sReg = "1";
        else if(j==2)
            sReg = "11";
        else
            sReg = getString(sReg);
    }
    return sReg;
}

//5.  Program to convert Roman Numerals to Numbers
// This function returns value of a Roman symbol
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

// Returns decimal value of roman numaral
int romanToDecimal(string &str)
{
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

//6. Smallest subarray with sum greater than a given value

int SmallestSubarrayWithSumGreaterThanAGivenValue(int nums[], int n){

    int smallest = n+1;
    int curr;
    for(int i=0; i<n; i++){
        curr = nums[i];
        if (curr>n) return 1;
        for(int j=i+1; j<n; j++){
            curr = curr + nums[j];
            if(curr>n)
                if(smallest>(j-i+1))
                    smallest=j-i+1;
        }
    }

    return smallest;
}

//7. Greedy Algorithms

//8. Find Subarray with given sum

int FindSubarrayWithGivenSum(int nums[], int size, int n){
    int curr = 0;
    for(int i=0; i<size; i++){
        curr = nums[i];
        for(int j=i+1; j<size; j++){
            if(curr==n){
                printf("find item equal sum at %d and %d", i, j);
                return 1;
            }
            if((curr > n) || (j == size))
                break; //no more forward
            curr = curr + nums[j];

        }
    }
    printf("No subarry found");
    return 0;
}

//9 Convert Ternary Expression to a Binary Tree
/*
struct Node{
    string item;
    Node *left;
    Node *right;
    Node(char data){
        item = data;
        left = NULL;
        right = NULL;};
};
*/
void printTree(Node *root){
    if(!root)
        return;

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

    if((i<TExpr.length())&&(TExpr.at(i)=='?'))
        root->left = ConvertTernaryExpressionToABinaryTree(TExpr, i+1);
    else if (i<TExpr.length())
        root->right = ConvertTernaryExpressionToABinaryTree(TExpr, i+1);
    return root;
}

//10 Find All Triplets with zero sum

void FindAllTripletsWithZeroSum(int nums[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                if(nums[i] + nums[j] + nums[k]==0)
                    printf("sum zeor at %i, %i, %i\n", nums[i], nums[j], nums[k]);
            }
        }
    }
}

//11 Converting Decimal Number Lying Between 1 to 3999 to Roman Numberals

//12. Find Minimum Depth of a Binary Tree
//#include<bits/stdc++.h>
/*
struct NODE{
    int data;
    NODE *left;
    NODE *right;
};
*/

int FindMinimumDepthOfABinaryTree(Node *root){

    if(root==NULL)
        return 0;

    if((!root->left) && (!root->right))
        return 1;

    if(!root->left)
        return FindMinimumDepthOfABinaryTree(root->right) + 1;

    if(!root->right)
        return FindMinimumDepthOfABinaryTree(root->left) + 1;
//this way need travel all tree branch
    return min(FindMinimumDepthOfABinaryTree(root->left),
               FindMinimumDepthOfABinaryTree(root->right)) + 1;

}

//13. Find if string is K-Palindrome or not

bool isKPal(string str, int k){
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

//14 Multiply Large Numbers represented as Strings
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

//14 Median in a stream of intergers (running intergers)

#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int MedianInAStreamOfIntergers(int nums[], int size){

    //sort number {5, 15, 1, 3, 2, 8, 7, 9, 10,  6, 11, 4}
    //            {1, 2,  3, 4, 5, 6, 7, 8,  9, 10, 11, 15} => (6+7)/2 = 6

    // push data nums heap to make the data sorted queue
    vector<int> v(nums,nums+size);
    make_heap (v.begin(),v.end());
    cout << "initial max heap   : " << v.front() << '\n';

    if(size%2)
        return(size/2+1);
    else
        return ((nums[size/2]+nums[size/2-1])/2);
    for (unsigned i=0; i<v.size(); i++)
      cout << ' ' << v[i];
    cout << '\n';


}

//15 Boggle
const int N1 = 3;
bool Boggle(char boggle[N1][N1], char *dictionary[], int size){

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

//16 Count Possible Decodings of a given Digit Sequence.
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

// 17 Check The sum of 2 elements in an array equal to X
// first make array to hash table to make the data softed for small to big.

bool findSum(int B[], int X, int n){
    int i = 0;
    int j = n-1;

    while(i<j){
        int x = B[i] + B[j];
        if(x == X)
            return true;
        if(x > X )
            j--;
        if(x < X)
            i++;

    }
    return false;


}

// 18 find [0,1] string maximum value uing + or *.
// "012340" => (0 + 1 + 2)*3*(4+0) = 35
int calcMaxValue(string str){
    int res = str[0] - '0';
    for(int i=1; i<str.length();i++){
        if((str[i]=='0') || (str[i]=='1') || (str[i-1]=='0') || (str[i-1]=='1'))
            res += str[i] - '0';
        else
            res *= str[i] - '0';
    }
    return res;
}


int mainFacebook(){
    string str3 = "012340";
    cout << "Max number of " + str3 << " is " << calcMaxValue(str3) << endl;

    int A1[] = {1, 5, 4, 4, 3, 8};

    findSum(A1, 8, 6);

    char digits[] = "1234";
    int n2 = strlen(digits);
    cout << " count is " << countDecoding(digits, n2) << endl;

    char *dictionary[] = {"GEEKS", "FOR", "QUIZ", "GEE"};
    int size1 = 4;

    char boggle[N1][N1]   = {{'G','I','Z'},
                    {'U','E','K'},
                    {'Q','S','E'}};

    Boggle(boggle, dictionary, size1);

    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(A)/sizeof(A[0]);

    cout << "Mdeian = " << MedianInAStreamOfIntergers(A, size) << endl;

    string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
    //string str1 = "123";
    //string str2 = "45";


    cout << MultiplyLargeNumbersRepresentedAsStrings(str1, str2);

    cout << isKPal("abcdecba", 1) << endl;
    cout << isKPal("abcdeca", 2) << endl;
    cout << isKPal("acdcb", 1) << endl;

    bool map[M][N] = {{false,false,false,false,false},{false,false,false,false,false},
                      {false,false,false,false,false},{false,false,false,false,false}};
    map[3][0] = true;
    RoadMap(map, 4, 5, 0, 0);
  //  Node *root
    Node *root = new Node(0);
    root->left  = new Node(1);
    root->right = new Node(3);
    root->left->left  = new Node(4);
    root->left->right  = new Node(5);
    cout << "min tree depth = " << FindMinimumDepthOfABinaryTree(root) <<endl;

    int arr1[] = {0, -1, 2, -3, 1};
    FindAllTripletsWithZeroSum(arr1, sizeof(arr1)/sizeof(arr1[0]));

    string expression = "a?b?c:d:e";
    root = ConvertTernaryExpressionToABinaryTree(expression, 0);
    printTree(root);


    printTree(root);
    int arrs[] = {15, 2, 4, 8, 9, 5, 10, 23};

    FindSubarrayWithGivenSum(arrs, sizeof(arrs)/sizeof(arrs[0]), 23);

    string str ="MCMIV";
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl;
    printf(" gerenatd %s \n", Look_and_Say_Sequence(5));

    int bar[] = {6, 2, 5, 4, 5, 1, 6};
    printf("Max Area %d\n", LargestRectangularAreaInAHistogram(bar, sizeof(bar)/sizeof(bar[0])));

    int arr[] = {4, 2, 8, 5, 20, 1, 40, 13, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    findFibSubset(arr, n);

    int mat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Inplacerotatesquarematrixby90degrees(mat);

    int nums[] = {0,1,0,3,12};
    MoveZeroes(nums, sizeof(nums)/sizeof(int));
    int nums1[] = {1,-1,5,-2,3};
    MaximumSizeSubarraySumEqualsN(nums1, sizeof(nums1)/sizeof(int), 3);
    return 0;
}
