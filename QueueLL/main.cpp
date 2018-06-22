#include <iostream>

using namespace std;

struct QNode{
    int key;
    QNode *next;
};

struct Queue{
    QNode *frontQ, *rearQ;
};

QNode* newNode(int n){
    QNode* temp = new QNode;
    temp -> key = n;
    temp -> next = NULL;
    return temp;
}

Queue* createQueue(){
    Queue *q = new Queue;
    q -> frontQ = q -> rearQ = NULL;
    return q;
}

void enqueue(Queue *q, int n){
    QNode *temp = newNode(n);

    if(q -> rearQ == NULL){
        q -> frontQ = q -> rearQ = temp;
        return;
    }

    q -> rearQ -> next = temp;
    q -> rearQ = temp;
}

QNode *dequeue(Queue *q){
    if(q -> frontQ == NULL)
        return NULL;

    QNode *temp = q -> frontQ;
    q -> frontQ = q -> frontQ -> next;

    if (q -> frontQ == NULL)
        q -> rearQ = NULL;

    return temp;
}

int main()
{
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    QNode *n = dequeue(q);
    if (n != NULL)
        cout<<"Dequeued "<<n -> key;
    return 0;
}
