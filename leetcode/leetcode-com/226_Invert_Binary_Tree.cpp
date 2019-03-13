#include<iostream>
using namespace std;
TreeNode* invertTree(TreeNode* root) {
        if(root!=NULL){
            TreeNode* tmp=root->left;
            root->left=invertTree(root->right);
            root->right=invertTree(tmp);
        }
        return root;
    }
