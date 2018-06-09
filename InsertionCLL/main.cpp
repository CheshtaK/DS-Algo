#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *addToEmpty(Node *last, int n){
    if(last != NULL)
        return last;

    Node *temp = new Node;
    temp -> data = n;
    last = temp;

    last -> next = last;
    return last;
}

Node *addBegin(Node *last, int n){
    if(last == NULL)
        return addToEmpty(last, n);

    Node *temp = new Node;
    temp -> data = n;

    temp -> next = last -> next;
    last -> next = temp;

    return last;
}

Node *addEnd(Node *last, int n){
    if(last == NULL)
        return addToEmpty(last, n);

    Node *temp = new Node;
    temp -> data = n;

    temp -> next = last -> next;
    last -> next = temp;
    last = temp;

    return last;
}

Node *addAfter(Node *last, int n, int item){
    if(last == NULL)
        return addToEmpty(last, n);

    Node *temp, *p;
    p = last -> next;

    do{
        if(p -> data == item){
            temp = new Node;
            temp -> data = n;
            temp -> next = p -> next;
            p -> next = temp;

            if(p == last)
                last = temp;
            return last;
        }

        p = p -> next;
    }
    while(p != last -> next);

    cout<< item <<" not present in the list"<<endl;
    return last;
}

void traverse(Node *last){
    Node *p;

    if(last == NULL){
        cout<<"List is empty";
        return;
    }

    p = last -> next;

    do{
        cout<< p -> data<< " ";
        p = p -> next;
    }
    while(p != last -> next);
}

int main()
{
    Node *last = NULL;

    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);

    traverse(last);

    return 0;
}
