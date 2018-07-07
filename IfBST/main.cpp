//O(n)

#include <iostream>
#include <climits>

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

int isBSTUtil(Node *node, int minT, int maxT){
    if(node == NULL)
        return 1;

    if(node->key < minT || node->key > maxT)
        return 0;

    return
        isBSTUtil(node->left, minT, node->key-1) &&
        isBSTUtil(node->right, node->key+1, maxT);
}

/*int isBST(Node *node){
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}*/

bool isBST(Node *root){
    Node *prev = NULL;

    if(root){
        if(!isBST(root->left))
            return false;
        if(prev != NULL && root->key <= prev->key)
            return false;
        prev = root;
        return isBST(root->right);
    }
    return true;
}

int main()
{
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if(isBST(root))
        cout<<"BST";
    else
        cout<<"Not";
    return 0;
}
