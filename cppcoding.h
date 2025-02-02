#ifndef CPPCODING_H
#define CPPCODING_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

enum State { Univisited, Visited, Visting};

struct Node {
	int key;
	Node *left = NULL;
	Node *right = NULL;
	Node(int i) {
		key = i;
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
//int main13();
//int mainleetcode();
int mainFacebook();
int mainAmazon();
void mainOther();
#endif // CPPCODING_H
