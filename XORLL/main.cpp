#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* npx;
};

Node *XOR(Node *a, Node *b){
    return (Node*) ((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insertNode(Node **head, int n){
    Node *node = new Node;
    node -> data = n;

    node -> npx = XOR(*head, NULL);

    if(*head != NULL){
        Node *next = XOR((*head) -> npx, NULL);
        (*head) -> npx = XOR(node, next);
    }
    *head = node;
}

void printList(Node *head){
    Node *current = head;
    Node *prev = NULL;
    Node *next;

    while(current != NULL){
        cout<<current -> data<<" ";
        next = XOR(prev, current -> npx);

        prev = current;
        current = next;
    }
}

int main()
{
    Node *head = NULL;

    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    printList(head);

    return 0;
}
