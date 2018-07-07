#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data){
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printInorder(Node *node){
    if(node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

void storeInorder(Node *node, int inorder[], int *index_ptr){
    if(node == NULL)
        return;
    storeInorder(node->left, inorder, index_ptr);

    inorder[*index_ptr] = node->data;
    (*index_ptr)++;

    storeInorder(node->right, inorder, index_ptr);
}

int *merge(int a1[], int a2[], int m, int n){
    int *merged = new int[m+n];
    int i = 0, j = 0, k = 0;

    while(i < m && j < n){
        if(a1[i] < a2[j]){
            merged[k] = a1[i];
            i++;
        }
        else{
            merged[k] = a2[j];
            j++;
        }
        k++;
    }

    while(i < m){
        merged[k] = a1[i];
        i++;
        k++;
    }

    while(j < n){
        merged[k] = a2[j];
        j++;
        k++;
    }

    return merged;
}

Node *sortedArrayToBST(int a[], int startA, int endA){
    if(startA > endA)
        return NULL;

    int mid = (startA + endA)/2;
    Node *root = newNode(a[mid]);

    root->left = sortedArrayToBST(a, startA, mid-1);
    root->right = sortedArrayToBST(a, mid+1, endA);
    return root;
}

Node* mergeTrees(Node *root1, Node *root2, int m, int n){
    int *a1 = new int[m];
    int i = 0;
    storeInorder(root1, a1, &i);

    int *a2 = new int[n];
    int j = 0;
    storeInorder(root2, a2, &j);

    int *merged = merge(a1, a2, m, n);

    return sortedArrayToBST(merged, 0, m+n-1);
}

int main()
{
    Node *root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    Node *root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    Node *mergedTree = mergeTrees(root1, root2, 5, 3);
    printInorder(mergedTree);
    return 0;
}
