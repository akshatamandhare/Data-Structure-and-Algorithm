#include <iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //counstrructor
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

//deleting a node
void deleteNode(Node* &tail, int value){
    //empty list
    if(tail==NULL){
        cout<<"list is empty, please check again"<<endl;
        return;
    }
    else{
        //non-empty
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;

        //1 node case
        if (curr==prev)
        {
            tail=NULL;
        }
        
        //>=2 node case
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
    
}


//insert node;
void insertNode(Node *&tail, int element, int data)
{
    if(tail==NULL){
        Node* newnode=new Node(data);
        tail=newnode;
        tail->next=newnode;
    }
    else{
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        Node* newnode=new Node(data);
        newnode->next=curr->next;
        curr->next=newnode;
    }
}

//traversing a circular linked list
void print(Node* &tail){
    Node* temp = tail;  
    
    if(tail==NULL){
        cout << "List is empty" << endl;
        return;
    }
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(tail != temp);
    cout << endl;
}

bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

bool detectLoop(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main(){

    Node *tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);


    deleteNode(tail, 5);
    print(tail);

    insertNode(tail, 10, 4);
    print(tail);

    deleteNode(tail, 4);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    if (isCircularList(tail))
    {
        cout << "Linked List is Circular in nature" << endl;
    }
    else
    {
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}
