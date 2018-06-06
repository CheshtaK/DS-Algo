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

//Using Dummy Node
Node* SortedMergeD(Node* a, Node* b){
    Node dummy;
    Node* tail = &dummy;

    dummy.next = NULL;

    while(1){
        if(a == NULL){
            tail -> next = b;
            break;
        }
        else if(b == NULL){
            tail -> next = a;
            break;
        }

        if(a -> data <= b -> data)
            MoveNode(&(tail -> next), &a);
        else
            MoveNode(&(tail -> next), &b);
        tail = tail -> next;
    }
    return dummy.next;
}

//Using pointer pointing to last node of result
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

//Using Recursion
Node* SortedMergeR(Node* a, Node* b){
    Node* result = NULL;

    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;

    if(a -> data <= b -> data){
        result = a;
        result -> next = SortedMergeR(a -> next, b);
    }
    else{
        result = b;
        result -> next = SortedMergeR(a, b -> next);
    }
    return result;
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
    Node* b = NULL;
    Node* res1 = NULL;
    Node* res2 = NULL;
    Node* res3 = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);

    res1 = SortedMergeD(a, b);
    res2 = SortedMergeP(a, b);
    res3 = SortedMergeR(a, b);

    printList(res1);
    cout<<endl;
    printList(res2);
    cout<<endl;
    printList(res3);

    return 0;
}
