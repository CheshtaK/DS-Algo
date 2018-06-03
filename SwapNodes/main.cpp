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

void swapNodes(int x, int y){
    if(x == y)
        return;

    Node *currX = head, *prevX = NULL;
    while(currX && currX -> data != x){
        prevX = currX;
        currX = currX -> next;
    }

    Node *currY = head, *prevY = NULL;
    while(currY && currY -> data != y){
        prevY = currY;
        currY = currY -> next;
    }

    if(currX == NULL || currY == NULL)
        return;

    if(prevX != NULL)
        prevX -> next = currY;
    else
        head = currY;

    if(prevY != NULL)
        prevY -> next = currX;
    else
        head = currX;

    Node *temp = currY -> next;
    currY -> next = currX -> next;
    currX -> next = temp;
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

    swapNodes(3, 2);

    printList(head);
    return 0;
}
