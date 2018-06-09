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
        cout<< n -> data<<" ";
        n = n -> next;
    }
}

void rotateLL(Node** head, int k){
    if(k == 0)
        return;

    Node* current = *head;

    int count = 1;
    while(count < k && current != NULL){
        current = current -> next;
        count ++;
    }

    if(current == NULL)
        return;

    Node* kthNode = current;

    while(current->next != NULL)
        current = current -> next;

    current -> next = *head;
    *head = kthNode -> next;
    kthNode -> next = NULL;
}

int main()
{
    Node* head = NULL;

    for(int i = 60; i > 0; i -= 10)
        push(&head, i);

    printList(head);
    cout<<endl;

    rotateLL(&head, 4);
    printList(head);
    return 0;
}
