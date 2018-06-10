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

Node *lastNode(Node *head){
    while(head && head -> next)
        head = head -> next;
    return head;
}

Node *partitionN(Node *low, Node *high){
    int pivot = high -> data;
    Node *i = low -> prev;

    for(Node *j = low; j != high; j = j -> next){
        if(j -> data <= pivot){
            i = (i == NULL)? low : i -> next;
            swapNode(&(i -> data), &(j -> data));
        }
    }

    i = (i == NULL)? low : i -> next;
    swapNode(&(i -> data), &(high -> data));
    return i;
}

void _quicksort(Node *low, Node *high){
    if(high != NULL && low != high && low != high -> next){
        Node *p = partitionN(low, high);
        _quicksort(low, p -> prev);
        _quicksort(p -> next, high);
    }
}

void quicksort(Node *head){
    Node *h = lastNode(head);
    _quicksort(head, h);
}

int main()
{
    Node *a = NULL;

    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    printList(a);
    cout<<endl;

    quicksort(a);

    printList(a);

    return 0;
}
