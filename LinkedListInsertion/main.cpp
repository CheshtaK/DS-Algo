#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
} *start, *second, *newptr, *save, *ptr, *last;

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

int main()
{
    start = new Node;
    second = new Node;

    start -> data = 4;
    start -> next = second;

    second -> data = 5;
    second -> next = NULL;

    int data;
    cin>> data;

    newptr = newNode(data);
    //insertBeg(newptr);
    insertEnd(ptr);
    printList(start);
    return 0;
}
