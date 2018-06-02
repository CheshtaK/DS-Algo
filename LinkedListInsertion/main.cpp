#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
} *start, *newptr, *save, *ptr;

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

int main()
{
    start = new Node;

    start -> data = 4;
    start -> next = NULL;

    int data;
    cin>> data;

    newptr = newNode(data);
    insertBeg(newptr);
    printList(start);
    return 0;
}
