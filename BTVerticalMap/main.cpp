#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

Node *newNode(int key){
    Node *node = new Node;
    node -> key = key;
    node -> left = node -> right = NULL;
    return node;
}

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m){
    if(root == NULL)
        return;

    m[hd].push_back(root->key);
    getVerticalOrder(root->left, hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrder(Node *root){
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);

    map<int, vector<int>>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        for(int i = 0; i < it->second.size(); ++i)
            cout<<it->second[i]<<" ";
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

    printVerticalOrder(root);

    return 0;
}
