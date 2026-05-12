#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode (int data){
        val=data;
        left=right=NULL;
    }
    
};

int maxdown(TreeNode* root, int &maxi){
    if(root==NULL){
        return 0;
    }

    int left=max(0, maxdown(root->left, maxi));
    int right=max(0, maxdown(root->right, maxi));

    maxi=max(maxi,left + right + root->val);
    return max(left, right) + root->val;
}
int maxPathSum(TreeNode* root) {
    int maxi=INT_MIN;
    maxdown(root, maxi);
    return maxi;
}

int main(){
    struct TreeNode *root = new TreeNode(1);

    root->left=new TreeNode(2);
    root->right=new TreeNode(3);

    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left = new TreeNode(8);

    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->right->right->left=new TreeNode(9);
    root->right->right->right=new TreeNode(10);

    int ans=maxPathSum(root);
    cout<<"maxPathSum of Tree: "<<ans;

    return 0;
}