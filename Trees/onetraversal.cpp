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

vector<vector<int>> OneTraversal(Node* root){
    stack<pair<Node* , int>> st;
    vector<int> pre, post, in;

    if (root==NULL){
        return {};
    }
    st.push({root,1});
    while (!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    } 
    return {pre, in, post};
}

int main(){
    struct Node *root = new Node(1);

    root->left=new Node(2);
    root->right=new Node(5);

    root->left->left=new Node(3);
    root->left->right=new Node(4);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<vector<int>> res = OneTraversal(root);

    cout << "Preorder : ";
    for(auto val : res[0]){
        cout << val << " ";
    }

    cout << endl;

    cout << "Inorder : ";
    for(auto val : res[1]){
        cout << val << " ";
    }

    cout << endl;

    cout << "Postorder : ";
    for(auto val : res[2]){
        cout << val << " ";
    }

    cout << endl;

    return 0;
}