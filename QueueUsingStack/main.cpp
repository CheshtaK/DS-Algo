#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Queue{
    Node *stack1;
    Node *stack2;
};

void push(Node **top, int n){
    Node* newNode = new Node;

    if(newNode == NULL){
        cout<<"Overflow";
        exit(0);
    }

    newNode -> data = n;
    newNode -> next = (*top);
    (*top) = newNode;
}

int pop(Node **top_ref){
    int res;
    Node *top;

    if((*top_ref) == NULL){
        cout<<"Underflow";
        exit(0);
    }
    else{
        top = *top_ref;
        res = top -> data;
        *top_ref = top -> next;
        delete top;
        return res;
    }
}

void enQueue(Queue *q, int x){
    push(&q -> stack1, x);
}

int deQueue(Queue *q){
    int x;

    if(q -> stack1 == NULL && q -> stack2 == NULL){
        cout<<"Q is empty";
        exit(0);
    }

    if(q -> stack2 == NULL){
        while(q -> stack1 != NULL){
            x = pop(&q -> stack1);
            push(&q -> stack2, x);
        }
    }

    x = pop(&q -> stack2);
    return x;
}

int main()
{
    Queue *q = new Queue;
    q -> stack1 = NULL;
    q -> stack2 = NULL;

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    cout<<deQueue(q)<<endl;
    cout<<deQueue(q)<<endl;
    cout<<deQueue(q);

    return 0;
}
