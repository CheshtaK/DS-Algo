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

Node* insert(Node* node, int key){
    if(node == NULL)
        return newNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);

    return node;
}

Node *minValue(Node *node){
    Node *current = node;

    while(current->left != NULL)
        current = current->left;

    return current;
}

Node *inOrderSucc(Node *root, Node *n){
    if(n->right != NULL)
        return minValue(n->right);

    Node *succ = NULL;
    while(root != NULL){
        if(n->key < root->key){
            succ = root;
            root = root->left;
        }
        else if(n->key > root->key)
            root = root->right;
        else
            break;
    }
    return succ;
}

int main()
{
    Node *root = NULL, *temp, *succ, *minT;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;

    succ = inOrderSucc(root, temp);
    if(succ != NULL)
        cout<<succ->key;
    else
        cout<<"Does not exist";
    return 0;
}
