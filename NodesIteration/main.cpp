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

int getCount(Node *head){
    int count = 0;
    Node *current = head;
    while(current != NULL){
        count ++;
        current = current -> next;
    }
    return count;
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
    cout<<"Count of nodes is "<<getCount(head);
    return 0;
}
