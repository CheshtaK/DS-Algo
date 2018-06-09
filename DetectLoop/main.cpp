#include <iostream>
#include <tr1/unordered_set>

using namespace std;
using std::tr1::unordered_set;

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

//Using Hashing
/*bool detectLoop(Node* h){
    unordered_set<Node*> s;
    while(h != NULL){
        if(s.find(h) != s.end())
            return true;

        s.insert(h);
        h = h -> next;
    }
    return false;
}*/


//Using Floyd's Cycle-Finding Algorithm
int detectLoop(Node *nodes){
    Node *slow = nodes, *fast = nodes;
    while(slow && fast && fast->next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            cout<<"Found loop";
            return 1;
        }
    }
    cout<<"Not found";
    return 0;
}

int main()
{
    Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    head->next->next->next->next = head;

    /*if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;*/

    detectLoop(head);
}
