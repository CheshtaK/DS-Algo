#include <iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* newNode(int data){
    node* Nnode = new node;
    Nnode -> data = data;
    Nnode -> left = NULL;
    Nnode -> right = NULL;
    return (Nnode);
}

int main()
{
    node *root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);

    root -> left -> left = newNode(4);
    return 0;
}
