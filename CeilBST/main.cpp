#include <iostream>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};

Node *newNode(int k){
    Node *node = new Node;
    node -> key = k;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int Ceil(Node *root, int input){
    if (root == NULL)
        return -1;
    if(root -> key == input)
        return root -> key;
    if(root -> key < input)
        return Ceil(root->right, input);

    int ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->key;
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);

    for(int i = 0; i < 16; i++)
        cout<<i<<" "<<Ceil(root, i)<<endl;

    return 0;
}
