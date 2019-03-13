#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void accmulate(int &sum,TreeNode* root) {
        if(!root) return;
        if(root->right) accmulate(sum,root->right);
        root->val+=sum;
        sum=root->val;
        if(root->left) accmulate(sum,root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        accmulate(sum,root);
        return root;
    }
};
int n,m;
string s,ss;

int main() {

}

