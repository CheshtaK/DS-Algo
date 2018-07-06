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

bool printAncestors(Node* root, int target){
    if(root == NULL)
        return false;

    if(root -> data == target)
        return true;

    if(printAncestors(root->left, target) || printAncestors(root->right, target)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(7);

    printAncestors(root, 7);

    return 0;
}
