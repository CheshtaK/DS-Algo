#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
} *start, *newptr, *save, *ptr, *temp1, *temp2;

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

void deleteNode(int n){
    temp1 = start;

    if(n == 1){
        start = temp1 -> next; //head now points to second node
        delete temp1;
        return;
    }
    int i;
    for(i = 0; i < n-2; i++)
        temp1 = temp1 -> next; //n-1 node
    temp2 = temp1 -> next; // n node
    temp1 -> next = temp2 -> next; //n-1 points to n+1
    delete temp2;
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

    int n;
    cin>>n;

    deleteNode(n);

    printList(start);

    return 0;
}
