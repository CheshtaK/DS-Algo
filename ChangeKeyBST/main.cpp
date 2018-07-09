#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
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

Node *insert(Node *node, int key){
    if(node == NULL)
        return newNode(key);
    if(key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

Node* minValueNode(Node *node){
    Node *current = node;

    while(current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int key){
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else{
        if(root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node *changeKey(Node *root, int oldVal, int newVal){
    root = deleteNode(root, oldVal);
    root = insert(root, newVal);
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printInorder(root);
    cout<<endl;

    root = changeKey(root, 40, 10);
    printInorder(root);

    return 0;
}
