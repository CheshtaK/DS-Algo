//O(n)

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* node = new Node;
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void printK(Node* root, int k){
    if(root == NULL)
        return;
    if(k == 0){
        cout<<root -> data;
    }
    else{
        printK(root -> left, k-1);
        printK(root -> right, k-1);
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(8);

    printK(root, 2);

    return 0;
}
