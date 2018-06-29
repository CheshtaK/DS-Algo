//Time Complexity - O(n^2)

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

Node* newNode(int n){
    Node* node = new Node;
    node -> data = n;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int max(int a, int b){
    return (a >= b)? a: b;
}

int height(Node* node){
    if(node == NULL)
        return 0;

    return 1 + max(height(node -> left), height(node -> right));
}

int diameter(Node* tree){
    if(tree == NULL)
        return 0;

    int lheight = height(tree -> left);
    int rheight = height(tree -> right);

    int ldiameter = diameter(tree -> left);
    int rdiameter = diameter(tree -> right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

//Time Complexity - O(n)
int diameterOpt(Node* root, int* height){
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;

    if(root == NULL){
        *height = 0;
        return 0;
    }

    ldiameter = diameterOpt(root -> left, &lh);
    rdiameter = diameterOpt(root -> right, &rh);
    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int main()
{
    int height = 0;
    Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left  = newNode(4);
    root -> left -> right = newNode(5);
    cout<<diameter(root);
    cout<<diameterOpt(root, &height);
    return 0;
}
