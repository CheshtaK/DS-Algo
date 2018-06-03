#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
} *start, *newptr, *save, *ptr;

void printList(Node *n){
    while(n != NULL){
        cout<<" "<<n -> data;
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

void deleteNode(){
    if(start == NULL)
        cout<<"Overflow";
    else{
        ptr = start;
        start = start -> next;
        delete ptr;
    }
}

int main()
{
    start = new Node;

    start -> data = 0;
    start -> next = NULL;

    newptr = newNode(1);
    insertBeg(newptr);

    newptr = newNode(2);
    insertBeg(newptr);

    newptr = newNode(3);
    insertBeg(newptr);

    newptr = newNode(4);
    insertBeg(newptr);

    printList(start);
    cout<<endl;

    deleteNode();

    printList(start);

    return 0;
}
