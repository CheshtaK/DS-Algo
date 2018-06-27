#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int n){
    Node* node = new Node;
    node -> data = n;
    node -> left = NULL;
    node -> right = NULL;
    return(node);
}

void printPostorder(Node* node){
    if(node == NULL)
        return;

    printPostorder(node -> left);
    printPostorder(node -> right);
    cout<< node -> data<<" ";
}

void printInorder(Node* node){
    if(node == NULL)
        return;

    printInorder(node -> left);
    cout<< node -> data<<" ";
    printInorder(node -> right);
}

void printPreorder(Node* node){
    if(node == NULL)
        return;

    cout<< node -> data<<" ";
    printPreorder(node -> left);
    printPreorder(node -> right);
}

int main()
{
    Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);

    printPreorder(root);
    cout<<"\n";
    printInorder(root);
    cout<<"\n";
    printPostorder(root);
    return 0;
}
