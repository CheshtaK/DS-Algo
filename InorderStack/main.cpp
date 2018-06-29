#include <iostream>

using namespace std;

struct tNode{
    int data;
    tNode *left, *right;
};

struct sNode{
    tNode *t;
    sNode *next;
};

tNode* newNode(int n){
    tNode* node = new tNode;
    node -> data = n;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

bool isEmpty(sNode *top){
    return (top == NULL)? 1:0;
}

void push(sNode **top, tNode *t){
    sNode* new_tnode = new sNode;
    if(new_tnode == NULL){
        cout<<"Stack Overflow";
        exit(0);
    }
    new_tnode -> t = t;
    new_tnode -> next = (*top);
    (*top) = new_tnode;
}

tNode* pop(sNode** top){
    tNode *res;
    sNode *tops;

    if(isEmpty(*top)){
        cout<<"Stack Underflow";
        exit(0);
    }
    else{
        tops = *top;
        res = tops -> t;
        *top = tops -> next;
        delete(top);
        return res;
    }
}

void inOrder(tNode *root){
    tNode *current = root;
    sNode *s = NULL;
    bool done = 0;

    while(!done){
        if(current != NULL){
            push(&s, current);
            current = current -> left;
        }
        else{
            if(!isEmpty(s)){
                current = pop(&s);
                cout<<current -> data;
                current = current -> right;
            }
            else
                done = 1;
        }
    }
}

int main()
{
    tNode* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left  = newNode(4);
    root -> left -> right = newNode(5);
    inOrder(root);
    return 0;
}
