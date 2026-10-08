#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    
    Node(int val){
        data=val;
        left = right = nullptr;
    }
};

int height(Node *root, int &diameter){
    if(root==nullptr) return 0;
    int lh=height(root->left, diameter);
    int rh=height(root->right, diameter);

    diameter=max(diameter, lh+rh);
    return 1 + max(lh, rh);
}

int main(){
    struct Node *root= new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->left->left=new Node(5);
    root->right->left->left->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->right=new Node(5);
    root->right->right->right->right=new Node(6);   

    int diameter=0;
    height(root, diameter);

    cout<<"Diameter: "<<diameter;
    return 0;
}