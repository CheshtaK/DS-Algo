//Time Complexity - O(n^2)

#include <iostream>
#include <queue>

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
        int lHeight = height(node->left);
        int rHeight = height(node->right);

        return (lHeight > rHeight)? (lHeight + 1): (rHeight + 1);
    }
}

int getWidth(Node* root, int level){
    if(root == NULL)
        return 0;
    if(level == 1)
        return 1;
    else if(level > 1)
        return getWidth(root->left, level-1) + getWidth(root->right, level-1);
}

int getMaxWidth(Node* root){
    int maxWidth = 0;
    int width;
    int h = height(root);

    for(int i=1; i<=h; i++){
        width = getWidth(root, i);
        if(width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
}

int widthQueue(Node* root){
    if(root == NULL)
        return 0;
    int result = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        result = max(count, result);
        while(count--){
            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    return result;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    cout<<getMaxWidth(root);
    cout<<widthQueue(root);
    return 0;
}
