#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
int mnax(int a,int b){return a>b?a:b;}

int maxDepth(TreeNode* root) {
    int maxDepth(TreeNode* root) {
        return root!=NULL?1+max(maxDepth(root->left),maxDepth(root->right)):0;
    }
}

int main() {
    test(10);
}
