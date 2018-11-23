#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m;
string s,ss;
bool isMirror(TreeNode* l,TreeNode* r){
   if(l==null && r==null) return true;
   if(l==null || r==null) return false;
   return l->val==r->val 
       && isMirror(l->left,r->right)
       && isMirror(l->right,r->left);
}
bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
int main() {

}

