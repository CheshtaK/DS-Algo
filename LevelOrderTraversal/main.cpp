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

int height(Node* node){
    if(node == NULL)
        return 0;
    else{
        int lheight = height(node -> left);
        int rheight = height(node -> right);

        if(lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printGivenLevel(Node* root, int level){
    if(root == NULL)
        return;
    if(level == 1)
        cout<<root -> data<<" ";
    else if(level > 1){
        printGivenLevel(root -> left, level - 1);
        printGivenLevel(root -> right, level - 1);
    }
}


void printLevelOrder(Node* root){
    int h = height(root);
    for(int i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

int main()
{
    Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left  = newNode(4);
    root -> left -> right = newNode(5);
    printLevelOrder(root);
    return 0;
}
