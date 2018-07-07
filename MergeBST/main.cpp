#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

struct Snode{
    Node *t;
    Snode *next;
};

void push(Snode **s, Node *k){
    Snode *temp = new Snode;
    temp -> t = k;
    temp -> next = *s;
    (*s) = temp;
}

Node *pop(Snode **s){
    Node *t;
    Snode *st;
    st = *s;
    (*s) = (*s) -> next;
    t = st -> t;
    delete st;
    return t;
}

int isEmpty(Snode *s){
    if(s == NULL)
        return 1;
    return 0;
}

Node *newNode(int data){
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printInorder(Node *node){
    if(node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

void merge(Node *root1, Node *root2){
    Snode *s1 = NULL;
    Node *current1 = root1;

    Snode *s2 = NULL;
    Node *current2 = root2;

    if(root1 == NULL){
        printInorder(root2);
        return;
    }

    if(root2 == NULL){
        printInorder(root1);
        return;
    }

    while(current1 != NULL || !isEmpty(s1) ||current2 != NULL || !isEmpty(s2)){
        if(current1 != NULL || current2 != NULL){
            if(current1 != NULL){
                push(&s1, current1);
                current1 = current1 -> left;
            }
            if(current2 != NULL){
                push(&s2, current2);
                current2 = current2 -> left;
            }
        }
        else{
            if(isEmpty(s1)){
                while(!isEmpty(s2)){
                    current2 = pop(&s2);
                    current2->left = NULL;
                    printInorder(current2);
                }
                return;
            }
            if(isEmpty(s2)){
                while(!isEmpty(s1)){
                    current1 = pop(&s1);
                    current1 -> left = NULL;
                    printInorder(current1);
                }
                return;
            }

            current1 = pop(&s1);
            current2 = pop(&s2);

            if(current1->data < current2->data){
                cout<<current1->data<<" ";
                current1 = current1->right;
                push(&s2, current2);
                current2 = NULL;
            }
            else{
                cout<<current2->data<<" ";
                current2 = current2->right;
                push(&s1, current1);
                current1 = NULL;
            }
        }
    }
}

int main()
{
    Node *root1 = NULL, *root2 = NULL;
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);

    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);

    merge(root1, root2);

    return 0;
}
