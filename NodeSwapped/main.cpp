#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

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

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void correctBSTUtil(Node *root, Node **first, Node **middle, Node **last, Node **prev){
    if(root){
        correctBSTUtil(root->left, first, middle, last, prev);

        if(*prev && root->data < (*prev)->data){
            if(!*first){
                *first = *prev;
                *middle = root;
            }
            else
                *last = root;
        }

        *prev = root;

        correctBSTUtil(root->right, first, middle, last, prev);
    }
}

void correctBST(Node *root){
    Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    correctBSTUtil(root, &first, &middle, &last, &prev);

    if(first && last)
        swap(&(first->data), &(last->data));
    else if(first && middle)
        swap(&(first->data), &(middle->data));
}

int main()
{
    Node *root = newNode(6);
    root->left = newNode(10);
    root->right = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);

    printInorder(root);
    correctBST(root);
    printInorder(root);

    return 0;
}
