#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m;
string s,ss;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int getHeight(TreeNode* root,int& maxHeight){
    if(!root) return 0;
    int left = getHeight(root->left,maxHeight);
    int right = getHeight(root->right,maxHeight);
    maxHeight = max(maxHeight,left+right);
    return 1+max(left,right);
}
int diameterOfBinaryTree(TreeNode* root) {
    int height = 0;
    int res = getHeight(root,height);
    return res;
}

int main() {

}

