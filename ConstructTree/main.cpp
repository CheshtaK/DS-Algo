//Time Complexity - O(n)

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node* node = new Node;
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int search(int a[], int start, int ends, int value){
    for(int i = start; i <= ends; i++){
        if(a[i] == value)
            return i;
    }
}

Node* buildUtil(int in[], int post[], int inStart, int inEnd, int *pIndex){
    if(inStart > inEnd)
        return NULL;
    Node *node = newNode(post[*pIndex]);
    (*pIndex)--;

    if(inStart == inEnd)
        return node;

    int iIndex = search(in, inStart, inEnd, node->data);

    node->right = buildUtil(in, post, iIndex+1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStart, iIndex-1, pIndex);
}

Node *buildTree(int in[], int post[], int n){
    int pIndex = n-1;
    return buildUtil(in, post, 0, n-1, &pIndex);
}

void preOrder(Node* node){
    if(node == NULL)
        return;
    cout<<node -> data<<" ";
    preOrder(node -> left);
    preOrder(node -> right);
}

int main()
{
    int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in)/sizeof(in[0]);

    Node *root = buildTree(in, post, n);

    preOrder(root);
    return 0;
}
