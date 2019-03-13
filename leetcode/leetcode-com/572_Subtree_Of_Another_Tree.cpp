#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m;
string s,ss;
// *
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        bool isSubtree(TreeNode* s, TreeNode* t) {
            if(!s) return false;
            if(isSame(s,t)) return true;
            return isSubtree(s->left,t) || isSubtree(s->right,t);
        }
        bool isSame(TreeNode* s, TreeNode* t){

            if (!(s && t)) return s==t;
            return (s->val==t->val)&&isSame(s->left,t->left) && isSame(s->right,t->right);
        }
};
