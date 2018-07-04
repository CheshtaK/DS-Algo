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

int height(Node* node){
    if(node == NULL)
        return 0;
    else{
        int lHeight = height(node -> left);
        int rHeight = height(node -> right);

        return (lHeight > rHeight)? (lHeight+1): (rHeight+1);
    }
}

int getMax(int a[], int n){
    int maxW = a[0];
    for(int i=0; i<n; i++){
        if(a[i] > maxW)
            maxW = a[i];
    }
    return maxW;
}

void getMaxWidthRecur(Node *root, int countW[], int level){
    if(root){
        countW[level]++;
        getMaxWidthRecur(root -> left, countW, level+1);
        getMaxWidthRecur(root -> right, countW, level+1);
    }
}

int getMaxWidth(Node* root){
    int width;
    int h = height(root);

    int *countW = new int[h];
    int level = 0;
    getMaxWidthRecur(root, countW, level);
    return getMax(countW, h);
}

int main()
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);

    cout<<getMaxWidth(root);

    return 0;
}
