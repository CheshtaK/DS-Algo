#include <iostream>
#include <map>

using namespace std;

struct Node{
    int key;
    Node *left, *right, *random;
};

Node* newNode(int data){
    Node* node = new Node;
    node -> key = data;
    node -> left = node -> right = node -> random = NULL;
    return node;
}

void printInorder(Node* node){
    if(node == NULL)
        return;
    printInorder(node -> left);

    cout<<"["<< node -> key<<" ";
    if(node -> random == NULL)
        cout<<"NULL], ";
    else
        cout<< node -> random -> key<<"], ";

    printInorder(node -> right);
}

Node* copyLeftRightNode(Node* treeNode, map<Node*, Node*> *mymap){
    if(treeNode == NULL)
        return NULL;
    Node* cloneNode = newNode(treeNode -> key);
    (*mymap)[treeNode] = cloneNode;
    cloneNode -> left = copyLeftRightNode(treeNode -> left, mymap);
    cloneNode -> right = copyLeftRightNode(treeNode -> right, mymap);
    return cloneNode;
}

void copyRandom(Node* treeNode, Node* cloneNode, map<Node*, Node*> *mymap){
    if(cloneNode == NULL)
        return;
    cloneNode -> random = (*mymap)[treeNode -> random];
    copyRandom(treeNode -> left, cloneNode -> left, mymap);
    copyRandom(treeNode -> right, cloneNode -> right, mymap);
}

Node* cloneTree(Node* tree){
    if(tree == NULL)
        return NULL;
    map<Node*, Node*> *mymap = new map<Node*, Node*>;
    Node* newTree = copyLeftRightNode(tree, mymap);
    copyRandom(tree, newTree, mymap);
    return newTree;
}

int main()
{
    Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;

    printInorder(tree);

    Node* clone = cloneTree(tree);
    printInorder(clone);
    return 0;
}
