//Time Complexity - O(n)
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int maxDepth(Node* node){
    if(node == NULL)
        return 0;
    else{
        int lDepth = maxDepth(node -> left);
        int rDepth = maxDepth(node -> right);

        if(lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

Node* newNode(int data){
    Node* node = new Node;
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<maxDepth(root);
    return 0;
}
