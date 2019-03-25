#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
/*
 * i just forgot it is a BST 
 * its right must greater than middle than left
 * look .better
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void getElements(int a[],int &count,TreeNode* copy){
        while(copy){
            a[count++]=copy->val;
            if(copy->left) getElements(a,count,copy->left);
            if(copy->right) getElements(a,count,copy->right);

        } 
    }
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* copy = root;
       
        int count=0;
        int a[1005]={-1};
        getElements(a,count,copy);
        int res[1005]={0};
        sort(a,a+1005);
        for(int i=0;i<count-1;++i){
            int sum=0;
            if(a[i+1]>a[i]){
                for(int j=i;j<count-1;++j)
                    sum+=a[j];
                if(res[a[i]]==0) res[a[i]]=sum;
            }

        }
        
    }
};
int n,m;
string s,ss;

int main() {

}

