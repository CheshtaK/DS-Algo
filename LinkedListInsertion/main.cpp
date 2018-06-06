#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
} *start, *second, *third, *newptr, *save, *ptr, *last;

void printList(Node *n){
    while(n != NULL){
        cout<< n -> data;
        n = n -> next;
    }
}

Node* newNode(int n){
    ptr = new Node;
    ptr -> data = n;
    ptr -> next = NULL;
    return ptr;
}

void insertBeg(Node* np){
    if(start == NULL)
        start = np;
    else{
        save = start;
        start = np;
        np -> next = save;
    }
}

void insertEnd(Node* np){
    last = start;

    if(start == NULL)
        start = np;
    else{
        while(last -> next != NULL)
            last = last -> next;
        last -> next = np;
    }
}

void insertAfter(Node* prev, Node* np){
    if(prev == NULL)
        cout<<"The previous node cannot be null";
    np -> next = prev -> next;
    prev -> next = np;
}

int main()
{
    start = new Node;
    second = new Node;
    third = new Node;

    start -> data = 4;
    start -> next = second;

    second -> data = 5;
    second -> next = third;

    third -> data = 6;
    third -> next = NULL;

    int data;
    cin>> data;

    newptr = newNode(data);
    insertBeg(newptr);
    //insertEnd(newptr);
    //insertAfter(second, newptr);
    printList(start);
    return 0;
}
