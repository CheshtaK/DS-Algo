#include <iostream>

using namespace std;

struct LNode{
    int data;
    LNode *next;
};

struct TNode{
    int data;
    TNode *left;
    TNode *right;
};

TNode *newNode(int data){
    TNode *node = new TNode;
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void preOrder(TNode *node){
    if(node == NULL)
        return;
    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

void printList(LNode *node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node -> next;
    }
}

int countLNodes(LNode *head){
    int countN = 0;
    LNode *temp = head;
    while(temp){
        temp = temp -> next;
        countN++;
    }
    return countN;
}

void push(LNode **head_ref, int new_data){
    LNode *new_node = new LNode;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

TNode *sortedListToBSTRecur(LNode **head_ref, int n){
    if(n <= 0)
        return NULL;
    TNode *left = sortedListToBSTRecur(head_ref, n/2);

    TNode *root = newNode((*head_ref) -> data);
    root -> left = left;

    *head_ref = (*head_ref) -> next;

    root -> right = sortedListToBSTRecur(head_ref, n - n/2 -1);
    return root;
}

TNode *sortedListToBST(LNode *head){
    int n = countLNodes(head);
    return sortedListToBSTRecur(&head, n);
}

int main()
{
    LNode *head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);
    TNode *root = sortedListToBST(head);
    preOrder(root);
    return 0;
}
