#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node (int val){
        data=val;
        left=right=NULL;
    }
    
};

int dfshegiht(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh = dfshegiht(root->left);
    if(lh==-1) return -1;

    int rh = dfshegiht(root->right);
    if(lh==-1) return -1;

    if(abs(rh-lh)>1){
        return -1;
    }
    return 1+max(lh,rh);
}
bool checkBalancedBT(Node* root){
    return dfshegiht(root)!=-1;

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

    bool ans=checkBalancedBT(root);
    if(ans){
        cout<<"Balanced Tree";
    }
    else{
        cout<<"Not a Balanced Tree";
    }

    return 0;
}