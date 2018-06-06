#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void MoveNode(Node** dest, Node** source){
    Node* node = *source;
    if(node != NULL){
        *source = node -> next;
        node -> next = *dest;
        *dest = node;
    }
}

Node* SortedMergeP(Node* a, Node* b){
    Node* result = NULL;
    Node** lastPtr = &result;

    while(1){
       if(a == NULL){
            *lastPtr = b;
            break;
        }
        else if(b == NULL){
            *lastPtr = a;
            break;
        }

        if(a -> data <= b -> data)
            MoveNode(lastPtr, &a);
        else
            MoveNode(lastPtr, &b);
        lastPtr = &((*lastPtr) -> next);
    }
    return result;
}


void Split(Node* source, Node** frontL, Node** backL){
    Node* fast;
    Node* slow;
    slow = source;
    fast = source -> next;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    *frontL = source;
    *backL = slow -> next;
    slow -> next = NULL;
}

void MergeSort(Node** headR){
    Node* head = *headR;
    Node* a;
    Node* b;

    if((head == NULL) || (head -> next == NULL))
        return;

    Split(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headR = SortedMergeP(a, b);
}

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

int main()
{
    Node* a = NULL;
    Node* res = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    MergeSort(&a);

    printList(a);

    return 0;
}
