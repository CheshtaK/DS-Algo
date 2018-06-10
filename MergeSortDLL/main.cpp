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

void swapNode(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

Node *split(Node *head){
    Node *fast = head, *slow = head;
    while(fast -> next && fast -> next -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    Node *temp = slow -> next;
    slow -> next = NULL;
    return temp;
}

Node *mergeNode(Node *first, Node *second){
    if(!first)
        return second;

    if(!second)
        return first;

    if(first -> data < second -> data){
        first->next = mergeNode(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else{
        second->next = mergeNode(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node *mergeSort(Node *head){
    if (!head || !head -> next)
        return head;

    struct Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return mergeNode(head,second);
}

int main()
{
    Node *head = NULL;

    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
    push(&head, 10);

    head = mergeSort(head);

    printList(head);
    return 0;
}
