#ifndef CPPCODING_H
#define CPPCODING_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

enum State { Univisited, Visited, Visting};

struct Node{
    int key;
    Node *left, *right;
    Node(int i)
	{
        key = i;
        left = NULL;
        right = NULL;
    }

};

struct TreeNode{
    int iItem;
    State state;
    string sItem;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string str){
        sItem = str;
        left = NULL;
        right = NULL;
    }
    TreeNode(int i){
        iItem = i;
        left = NULL;
        right = NULL;
    }

};



int main01();
int main02();
int main03();
int main04();
int main05();
int main06();
int main07();
int main08();
int main09();
int main10();
int main11();
int main12();
int mainleetcode();
int mainfacebook();
int mainAmazon();
#endif // CPPCODING_H
