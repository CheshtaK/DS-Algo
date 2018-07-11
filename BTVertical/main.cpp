#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node *newNode(int data){
    Node *temp = new Node;
    temp -> data = data;
    temp -> left = temp -> right = NULL;
    return temp;
}

void findMinMax(Node *node, int *minD, int *maxD, int hd){
    if(node == NULL)
        return;

    if(hd < *minD)
        *minD = hd;
    else if(hd > *maxD)
        *maxD = hd;

    findMinMax(node->left, minD, maxD, hd-1);
    findMinMax(node->right, minD, maxD, hd+1);
}

void printVerticalLine(Node *node, int line, int hd){
    if(node == NULL)
        return;

    if(hd == line)
        cout<<node->data<<" ";

    printVerticalLine(node->left, line, hd-1);
    printVerticalLine(node->right, line, hd+1);
}

void verticalOrder(Node *root){
    int minD = 0, maxD = 0;
    findMinMax(root, &minD, &maxD, 0);

    for(int line = minD; line <= maxD; line++){
        printVerticalLine(root, line, 0);
        cout<<endl;
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    verticalOrder(root);
    return 0;
}
