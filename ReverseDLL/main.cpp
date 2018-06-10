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

void printList(Node* head){
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
}

void reverseDLL(Node **head){
    Node *temp = NULL;
    Node *current = *head;

    while(current != NULL){
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }

    if(temp != NULL)
        *head = temp -> prev;
}

int main()
{
    Node *head = NULL;

    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printList(head);
    cout<<endl;

    reverseDLL(&head);

    printList(head);

    return 0;
}
