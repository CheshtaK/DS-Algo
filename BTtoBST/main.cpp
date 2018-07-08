#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data){
    Node *node = new Node;
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void printInorder(Node *node){
    if(node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

int countNodes(Node *root){
    if(root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

void storeInorder(Node *node, int inorder[], int *index_ptr){
    if(node == NULL)
        return;
    storeInorder(node->left, inorder, index_ptr);

    inorder[*index_ptr] = node->data;
    (*index_ptr)++;

    storeInorder(node->right, inorder, index_ptr);
}

void arrayToBST(int *a, Node *root, int *index_ptr){
    if(root == NULL)
        return;
    arrayToBST(a, root->left, index_ptr);

    root->data = a[*index_ptr];
    (*index_ptr)++;

    arrayToBST(a, root->right, index_ptr);
}

void BTtoBST(Node *root){
    if(root == NULL)
        return;

    int n = countNodes(root);

    int *a = new int[n];
    int i = 0;
    storeInorder(root, a, &i);

    std::sort(a, a+n);

    i = 0;
    arrayToBST(a, root, &i);

    delete a;
}

int main()
{
    Node *root = NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    BTtoBST(root);
    printInorder(root);
    return 0;
}
