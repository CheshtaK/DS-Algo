#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
} *head, *newptr, *save, *ptr, *last;

Node* newNode(int n){
    ptr = new Node;
    ptr -> data = n;
    ptr -> next = NULL;
    return ptr;
}

void insertEnd(Node* np){
    last = head;

    if(head == NULL)
        head = np;
    else{
        while(last -> next != NULL)
            last = last -> next;
        last -> next = np;
    }
}

void printList(Node *n){
    while(n != NULL){
        cout<<" "<<n -> data;
        n = n -> next;
    }
}

void reverseLL(){
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void reverseRecursive(Node *p){
    if(head == NULL)
        return;
    if(p -> next == NULL){
        head = p;
        return;
    }
    reverseRecursive(p -> next);

    Node *q = p -> next;
    q -> next = p;
    p -> next = NULL;
}

int main()
{
    head = new Node;

    head -> data = 0;
    head -> next = NULL;

    newptr = newNode(1);
    insertEnd(newptr);

    newptr = newNode(2);
    insertEnd(newptr);

    newptr = newNode(3);
    insertEnd(newptr);

    newptr = newNode(4);
    insertEnd(newptr);

    printList(head);
    cout<<endl;

    //reverseLL();
    reverseRecursive(head);

    printList(head);
    return 0;
}
