//Given two numbers represented by two lists, write a function that returns sum list

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void printList(Node *n){
    while(n != NULL){
        cout<< n -> data;
        n = n -> next;
    }
}

Node* newNode(int n){
    Node *ptr = new Node;
    ptr -> data = n;
    ptr -> next = NULL;
    return ptr;
}

void push(Node** start, int n){
    Node* node = new Node;
    node -> data = n;
    node -> next = *start;
    *start = node;
}

Node* add(Node* a, Node* b){
    Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    while(a != NULL || b != NULL){
        sum = carry + (a ? a->data : 0) + (b ? b->data : 0);

        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;

        temp = newNode(sum);

        if(res == NULL)
            res = temp;
        else
            prev -> next = temp;

        prev = temp;

        if(a)
            a = a -> next;
        if(b)
            b = b -> next;
    }

    if(carry > 0)
        temp -> next = newNode(carry);

    return res;
}

int main()
{
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;

    push(&a, 6);
    push(&a, 4);
    push(&a, 9);
    push(&a, 5);
    push(&a, 7);
    printList(a);
    cout<<endl;

    push(&b, 4);
    push(&b, 8);
    printList(b);
    cout<<endl;

    res = add(a, b);
    printList(res);

    return 0;
}
