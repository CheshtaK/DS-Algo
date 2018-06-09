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
    Node *last;

    cout<<"Traversal in forward direction ";
    while(head != NULL){
        cout<<head -> data<<" ";
        last = head;
        head = head -> next;
    }

    cout<<endl;
    cout<<"Traversal in reverse direction ";
    while(last != NULL){
        cout<<last -> data<<" ";
        last = last -> prev;
    }
    cout<<endl;
}

void deleteNode(Node** head, Node* del){
    if(*head == NULL || del == NULL)
        return;

    if(*head == del)
        *head = del -> next;

    if(del -> next != NULL)
        del -> next -> prev = del -> prev;

    if(del -> prev != NULL)
        del -> prev -> next = del -> next;

    delete del;
    return;
}

int main()
{
    Node *head = NULL;

    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printList(head);

    deleteNode(&head, head);
    deleteNode(&head, head -> next);
    deleteNode(&head, head -> next);

    printList(head);

    return 0;
}
