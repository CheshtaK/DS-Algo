#include <iostream>

using namespace std;

struct StackNode{
    int data;
    StackNode* next;
};

StackNode* newNode(int n){
    StackNode* stackNode = new StackNode;
    stackNode -> data = n;
    stackNode -> next = NULL;
    return stackNode;
}

int isEmpty(StackNode* root){
    return !root;
}

void push(StackNode** root, int n){
    StackNode* stackNode = newNode(n);
    stackNode -> next = *root;
    *root = stackNode;
}

int pop(StackNode** root){
    if(isEmpty(*root))
        return 0;

    StackNode* temp = *root;
    *root = (*root) -> next;

    int popped = temp -> data;
    delete temp;
    return popped;
}

int peek(StackNode* root){
    if(isEmpty(root))
        return 0;
    return root -> data;
}

int main()
{
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout<<"Popped from the stack "<<pop(&root)<<endl;
    cout<<"Top element is "<<peek(root);

    return 0;
}
