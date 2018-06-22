#include <iostream>

using namespace std;

struct Queue{
    int frontQ, rear, sizeQ;
    unsigned capacity;
    int* arrayQ;
};

Queue* create(unsigned capacity){
    Queue* queueL = new Queue;
    queueL -> capacity = capacity;
    queueL -> frontQ = queueL -> sizeQ = 0;
    queueL -> sizeQ = capacity - 1;
    queueL -> arrayQ = new int[queueL -> capacity];
    return queueL;
}

int isFull(Queue* queueL){
    return (queueL -> sizeQ == queueL -> capacity);
}

int isEmpty(Queue* queueL){
    return (queueL -> sizeQ == 0);
}

void enqueue(Queue* queueL, int item){
    if(isFull(queueL))
        return;

    queueL -> rear = (queueL -> rear + 1) % (queueL -> capacity);
    queueL -> arrayQ[queueL -> rear] = item;
    queueL -> sizeQ = queueL -> sizeQ + 1;
    cout<<"Enqueued to queueL "<<item<<endl;
}

int dequeue(Queue* queueL){
    if(isEmpty(queueL))
        return 0;

    int item = queueL -> arrayQ[queueL -> frontQ];
    queueL -> frontQ = (queueL -> frontQ + 1) % (queueL -> capacity);
    queueL -> sizeQ = queueL -> sizeQ - 1;
    return item;
}

int frontQ(Queue* queueL){
    if(isEmpty(queueL))
        return 0;
    return queueL -> arrayQ[queueL -> frontQ];
}

int rear(Queue* queueL){
    if(isEmpty(queueL))
        return 0;
    return queueL -> arrayQ[queueL -> rear];
}

int main()
{
    Queue* queueL = create(1000);

    enqueue(queueL, 10);
    enqueue(queueL, 20);
    enqueue(queueL, 30);
    enqueue(queueL, 40);

    cout<<dequeue(queueL)<<endl;
    cout<<frontQ(queueL)<<endl;
    cout<<rear(queueL);

    return 0;
}
