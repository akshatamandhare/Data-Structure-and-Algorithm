#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

//traversing a linked list
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//insert at head
void insertathead(Node* &head, int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
    }
    else{
        Node* temp=new Node(data);
        temp->next=head;
        head=temp;
    }
}

//insert at tail
void insertattail(Node* &head, int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
    }
    else{
        Node* temp=new Node(data);
        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
        curr=temp;
    }
}

//insert at position
void insertatposition(Node* &head, int position, int data){
    if(position==1){
        insertathead(head, data);
        return;
    }
    else{
        Node* temp= new Node(data);
        Node* curr = head;
        int count=1;
        while(count<position-1){
            curr=curr->next;
            count++;
        }
        
        temp->next=curr->next;
        curr->next=temp;
    }
}

//delete Node
void deletenode(Node* &head, int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        //memory free
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){

    Node *head = NULL;
    // Node *tail = NULL;

    insertathead(head, 5);
    print(head);

    insertathead(head, 6);
    print(head);

    insertattail(head, 7);
    print(head);

    insertattail(head, 10);
    print(head);

    insertatposition(head, 3, 8);
    print(head);

    insertatposition(head, 1, 100);
    print(head);

    deletenode(head, 3);
    print(head);

    return 0;
}