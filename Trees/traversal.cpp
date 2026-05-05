#include <bits/stdc++.h>
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

void inorder(Node *root){

    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root){

    if(root==NULL){
        return;
    }
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root){

    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelorder(Node *root){
    if(root==NULL) return;

    
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

    cout<<"Inorder traversal : ";
    inorder(root);

    cout<<endl<<"preorder traversal : ";
    preorder(root);
    
    cout<<endl<<"postorder traversal : ";
    postorder(root);

    cout<<endl<<"Levelorder traversal : ";
    levelorder(root);
    
    return 0;
}

