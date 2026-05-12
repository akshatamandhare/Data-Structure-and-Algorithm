#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node (int val){
        data=val;
        left=right=NULL;
    }
    
};

int maxdepth(Node* root, int &diameter){
    if(root==NULL){
        return 0;
    }

    int lh = maxdepth(root->left, diameter);
    int rh = maxdepth(root->right,diameter);
    diameter=max(diameter, lh+rh+1);
    return 1+max(lh,rh);
}

int diameter(Node* root){
    int diameter=0;
    maxdepth( root,diameter);
    return diameter;
}

int main(){
    struct Node *root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left = new Node(8);

    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);

    int ans=diameter(root);
    cout<<"Diameter of BT: "<<ans;

    return 0;
}