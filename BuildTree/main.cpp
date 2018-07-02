//Time Complexity - O(n^2)

#include <iostream>

using namespace std;

struct Node{
    char data;
    Node *left, *right;
};

Node* newNode(char data){
    Node* node = new Node;
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int search(char a[], int start, int ends, char value){
    for(int i = start; i <= ends; i++){
        if(a[i] == value)
            return i;
    }
}

Node* buildTree(char in[], char pre[], int inStart, int inEnd){
    static int preIndex = 0;
    if(inStart > inEnd)
        return NULL;

    Node* tNode = newNode(pre[preIndex++]);
    if(inStart == inEnd)
        return tNode;

    int inIndex = search(in, inStart, inEnd, tNode -> data);

    tNode -> left = buildTree(in, pre, inStart, inIndex - 1);
    tNode -> right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void printInorder(Node* node){
    if(node == NULL)
        return;
    printInorder(node -> left);
    cout<<node -> data<<" ";
    printInorder(node -> right);
}
int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in)/sizeof(in[0]);
    Node* root = buildTree(in, pre, 0, len-1);
    printInorder(root);

    return 0;
}
