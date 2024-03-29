#include <iostream>

using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

Node *newNode(int item){
    Node *temp = new Node;
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

Node *lca(Node *root, int n1, int n2){
    if(root == NULL)
        return NULL;
    if(root->key > n1 && root->key > n2)
        root = root->left;
    if(root->key < n1 && root->key < n2)
        root = root->right;
    return root;
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    Node *t = lca(root, n1, n2);
    cout<<t->key;
    return 0;
}
