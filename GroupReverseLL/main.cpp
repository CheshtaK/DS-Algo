#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node** start, int n){
    Node* node = new Node;
    node -> data = n;
    node -> next = *start;
    *start = node;
}

void printList(Node *n){
    while(n != NULL){
        cout<<n -> data<<" ";
        n = n -> next;
    }
}

Node* reverseG(Node* head, int k){
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;

    while(current != NULL && count < k){
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next != NULL)
        head -> next = reverseG(next, k);

    return prev;
}

int main()
{
    Node* head = NULL;

    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);
    cout<<endl;

    head = reverseG(head, 3);
    printList(head);

    return 0;
}
