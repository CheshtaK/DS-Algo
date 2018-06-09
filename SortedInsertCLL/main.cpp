#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

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

void sortedInsert(Node** head, Node* node){
    Node* current = *head;

    if(current == NULL){
        node -> next = node;
        *head = node;
    }
    else if(current -> data >= node -> data){
        while(current -> next != *head)
            current = current -> next;

        current -> next = node;
        node -> next = *head;
        *head = node;
    }
    else{
        while(current -> next != NULL && current -> next -> data < node -> data)
            current = current -> next;

        node -> next = current -> next;
        current -> next = node;
    }
}

int main()
{
    int a[] = {12, 56, 2, 11, 1, 90};

    Node *head = NULL;
    Node *temp;

    for(int i = 0; i < 6; i++){
        temp = new Node;
        temp -> data = a[i];
        sortedInsert(&head, temp);
    }

    printList(head);

    return 0;
}
