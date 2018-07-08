#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *newNode(int data){
    Node *node = new Node;
    node -> data = data;
    node -> prev = NULL;
    node -> next = NULL;
    return node;
}

void preOrder(Node *node){
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->prev);
    preOrder(node->next);
}

void printList(Node *node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node -> next;
    }
}

int countNodes(Node *head){
    int countN = 0;
    Node *temp = head;
    while(temp){
        temp = temp -> next;
        countN++;
    }
    return countN;
}

void push(Node **head_ref, int new_data){
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

Node *sortedListToBSTRecur(Node **head_ref, int n){
    if(n <= 0)
        return NULL;
    Node *left = sortedListToBSTRecur(head_ref, n/2);

    Node *root = *head_ref;
    root -> prev = left;

    *head_ref = (*head_ref) -> next;
    root -> next = sortedListToBSTRecur(head_ref, n - n/2 - 1);
    return root;
}

Node *sortedListToBST(Node *head){
    int n = countNodes(head);
    return sortedListToBSTRecur(&head, n);
}

int main()
{
    Node *head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);

    Node *root = sortedListToBST(head);
    preOrder(root);
    return 0;
}
