#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void push(Node** head, int n){
    Node* node = new Node;
    node -> data = n;

    node -> next = *head;
    node -> prev = NULL;

    if(*head != NULL)
        (*head) -> prev = node;

    *head = node;
}

void insertAfter(Node *prev, int n){
    if(prev == NULL){
        cout<<"The given previous node cannot be NULL";
        return;
    }

    Node *node = new Node;

    node -> data = n;
    node -> next = prev -> next;
    prev -> next = node;
    node -> prev = prev;

    if(node -> next != NULL)
        node -> next -> prev = node;
}

void append(Node** head, int n){
    Node* node = new Node;
    Node *last = *head;

    node -> data = n;
    node -> next = NULL;

    if(*head == NULL){
        node -> prev = NULL;
        *head = node;
        return;
    }

    while(last -> next != NULL)
        last = last -> next;

    last -> next = node;
    node -> prev = last;

    return;
}

void printList(Node* head){
    Node *last;

    cout<<"Traversal in forward direction ";
    while(head != NULL){
        cout<<head -> data<<" ";
        last = head;
        head = head -> next;
    }

    cout<<endl;
    cout<<"Traversal in reverse direction ";
    while(last != NULL){
        cout<<last -> data<<" ";
        last = last -> prev;
    }
}

int main()
{
    Node *head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head -> next, 8);

    printList(head);
    return 0;
}
