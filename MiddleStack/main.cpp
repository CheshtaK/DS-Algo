//We use DLL as deleting middle element - O(1) and we can move in both directions

#include <iostream>

using namespace std;

struct DLLNode{
    int data;
    DLLNode *prev;
    DLLNode *next;
};

struct Stack{
    DLLNode *head;
    DLLNode *mid;
    int count;
};

Stack *createStack(){
    Stack *s = new Stack;
    s -> count = 0;
    return s;
}

void push(Stack *s, int n){
    DLLNode *node = new DLLNode;

    node -> data = n;
    node -> prev = NULL;
    node -> next = s -> head;
    s -> count += 1;

    if(s -> count == 1)
        s -> mid = node;
    else{
        s -> head -> prev = node;
        if((s -> count) & 1)
            s -> mid = s -> mid -> prev;
    }

    s -> head = node;
}

int pop(Stack *s){
    if(s -> count == 0){
        cout<<"Stack is empty";
        return -1;
    }

    DLLNode *head = s -> head;
    int item = head -> data;
    s -> head = head -> next;

    if(s -> head != NULL)
        s -> head -> prev = NULL;

    s -> count = -1;

    if(((s -> count) & 1) == 0)
        s -> mid = s -> mid -> next;

    delete head;
    return item;
}

int middle(Stack *s){
    if(s -> count == 0){
        cout<<"Stack is empty";
        return -1;
    }
    return s -> mid -> data;
}

int main()
{
    Stack *s = createStack();

    push(s, 11);
    push(s, 22);
    push(s, 33);
    push(s, 44);
    push(s, 55);
    push(s, 66);
    push(s, 77);

    cout<<pop(s)<<" ";
    cout<<pop(s)<<" ";
    cout<<middle(s);
    return 0;
}
