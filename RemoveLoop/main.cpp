#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node** start, int n){
    Node* node = new Node;
    node -> data = n;
    node -> next = *start;
    *start = node;
}

void printList(Node *n){
    while(n != NULL){
        cout<< n -> data<<" ";
        n = n -> next;
    }
}

//Method 1
/*void removeLoop(Node *loopNode, Node* head){
    Node *ptr1, *ptr2;

    ptr1 = head;
    while(1){
        ptr2 = loopNode;
        while(ptr2 -> next != loopNode && ptr2 -> next != ptr1)
            ptr2 = ptr2 -> next;

        if(ptr2 -> next == ptr1)
            break;

        ptr1 = ptr1 -> next;
    }
    ptr2 -> next = NULL;
}*/

void removeLoop(Node *loopNode, Node *head){
    Node *ptr1 = loopNode, *ptr2 = loopNode;

    unsigned int k = 1, i;
    while(ptr1 -> next != ptr2){
        ptr1 = ptr1 -> next;
        k++;
    }

    ptr1 = head;

    ptr2 = head;
    for(i = 0; i < k; i++)
        ptr2 = ptr2 -> next;

    while(ptr1 != ptr2){
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    ptr2 = ptr2 -> next;
    while(ptr2 -> next != ptr1)
        ptr2 = ptr2 -> next;

    ptr2 -> next = NULL;
}

int detectAndRemove(Node *nodes){
    Node *slow = nodes, *fast = nodes;
    while(slow && fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            removeLoop(slow, nodes);
            return 1;
        }
    }
    return 0;
}

int main()
{
    Node* head = NULL;

    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);

    head->next->next->next->next->next = head->next->next;

    detectAndRemove(head);

    printList(head);

    return 0;
}
