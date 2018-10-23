#include<iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* pre (TreeNode* t1,TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        t1->val+=t2->val;
        t1->left=pre(t1->left,t2->left);
        t1->right=pre(t1->right,t2->right);
        return t1;

    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* result= t1;
        result=pre(t1,t2);
        return result;
    }
    void show(TreeNode* t) {
        if(t) {
            cout<<t->val;
            show(t->left);
            show(t->right);
        }
    }
};
int main() {
    TreeNode* t = new TreeNode(1);
    t->left=new TreeNode(3);
    t->right=new TreeNode(2);
    t->left->left=new TreeNode(5);

    TreeNode* tt=new TreeNode(2);
    t->left=new TreeNode(1);
    t->right=new TreeNode(3);
    t->left->right=new TreeNode(4);
    t->right->right=new TreeNode(7);
    Solution* s = new Solution();
    TreeNode* r=s->mergeTrees(t,tt);
    s->show(r);


}
