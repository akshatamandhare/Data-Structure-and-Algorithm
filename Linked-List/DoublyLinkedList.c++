#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //counstrructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
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
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//gives length of linked list
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

//insert at head;
void insertAtHead(Node* & tail, Node* &head, int data){
    //empty list
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

//insert at tail
void insertAtTail(Node* & tail, Node* &head, int data){
    //empty list
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

//insert at position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // insert at head
    if (position == 1)
    {
        insertAtHead(tail, head, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // ❗ SAFETY CHECK
    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // insert at tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, data);
        return;
    }

    // insert in middle
    Node *newnode = new Node(data);
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

//delete node
void deleteNode(int position, Node* &head){
    //deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        //memory free
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        if(curr->next != NULL){
            curr->next->prev = prev;
        }
        curr->next = NULL;
        //memory free
        delete curr;
    }
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    // cout << getLength(head) << endl;

    insertAtHead(tail, head, 11);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 13);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 8);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtTail(tail, head, 25);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(head, tail, 2, 100);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(head, tail, 1, 101);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 3, 102);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    deleteNode(4, head);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    return 0;
}

