#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

Node* kthelement(Node *temp, int k){
    k-=1;
    while (temp !=nullptr && k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}

Node *revereLL(Node *temp){
    Node *prev=nullptr;
    Node *front=nullptr;
    while(temp != nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node *reverseKthGrp(Node *head, int k){
    Node *temp=head;
    Node *prevlast=nullptr;
    Node *kthnode;

    while(temp != nullptr){
        kthnode=kthelement(temp, k);
        if(kthnode==NULL){
            if(prevlast) prevlast->next=temp;
            break;
        }

        Node *nextnode=kthnode->next;
        kthnode->next=nullptr;
        revereLL(temp);

        if(temp==head){
            head=kthnode;
        }else{
            prevlast->next=kthnode;
        }
        prevlast=temp;
        temp=nextnode;
    }
    return head;
}

int main(){

    cout<<"Enter N and K: ";
    int n, k;
    cin>>n>>k;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node *newhead = reverseKthGrp(head, k);
    // Print the reversed list
    Node* temp = newhead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}