#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **head, int n){
    Node *node = new Node;
    Node *temp = *head;

    node -> data = n;
    node -> next = *head;

    if(*head != NULL){
        while(temp -> next != *head)
            temp = temp -> next;
        temp -> next = node;
    }
    else
        node -> next = node;

    *head = node;
}

void printList(Node *head){
    Node *temp = head;

    if(head != NULL){
        do{
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        while(temp != head);
    }
}

void split(Node* head, Node** head1, Node** head2){
    Node *slow = head;
    Node *fast = head;

    if(head == NULL)
        return;

    while(fast -> next != head && fast -> next -> next != head){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    if(fast -> next -> next == head)
        fast = fast -> next;

    *head1 = head;

    if(head -> next != head)
        *head2 = slow -> next;

    fast -> next = slow -> next;
    slow -> next = head;
}

int main()
{
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printList(head);
    cout<<endl;

    split(head, &head1, &head2);

    printList(head1);
    cout<<endl;
    printList(head2);

    return 0;
}
