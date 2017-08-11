#include <cppcoding.h>

//Binary Sort Trees

struct TreeNode{
    string item;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string str){
        item = str;
        left = NULL;
        right = NULL;
    }
};


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
        cout << root->item << " ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }

}

bool treeContrins(TreeNode *root, string item){
    if(root==NULL){
        return false;
    }
    else if (item == root->item) {
        return true;
    }
    else if (item < root->item) {
             return treeContrins(root->left, item);
    }
    else{
        return treeContrins(root->right, item);
    }

}

void inorderPrint( TreeNode *root ) {
   if ( root != NULL ){  // (Otherwise, there's nothing to print.)
      inorderPrint( root->left );    // Print items in left subtree.
      cout << root->item << " ";     // Print the root item.
      inorderPrint( root->right );   // Print items in right subtree.
   }

} // end inorderPrint()


void treeInsert(TreeNode *root, string newItem){

    if(root == NULL){
        root = new TreeNode(newItem);
        return;
    }
    else if (newItem < root->item) {
        treeInsert(root->left, newItem);
    }
    else
        treeInsert(root->right, newItem);
}


// Expression Trees node is opr to return opr(left, right
double getValue(TreeNode *node){

    if((node->item != "+")&&(node->item != "-")&&(node->item != "*")&&(node->item != "/")){
        return atoi(node->item.c_str());
    }
    else{
        double leftVal = getValue(node->left);
        double rightVal = getValue(node->right);

        if(node->item == "+") return leftVal + rightVal;
        else if(node->item == "-") return leftVal - rightVal;
        else if(node->item == "*") return leftVal * rightVal;
        else if(node->item == "/") return leftVal / rightVal;
    }
}



int main04(){

    return 0;
}
