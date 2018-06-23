#include <iostream>

using namespace std;

class Deque{
    int arr[100];
    int frontDQ;
    int rearDQ;
    int sizeDQ;
public:
    Deque(int sizeDQ){
        frontDQ = -1;
        rearDQ = 0;
        this -> sizeDQ = sizeDQ;
    }

    void insertFront(int key);
    void insertRear(int key);
    void deleteFront();
    void deleteRear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
};

bool Deque::isFull(){
    return ((frontDQ == 0 && rearDQ == sizeDQ - 1) ||
            frontDQ == rearDQ + 1);
}

bool Deque::isEmpty(){
    return (frontDQ == -1);
}

void Deque::insertFront(int key){
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }

    if(frontDQ == -1){
        frontDQ = 0;
        rearDQ = 0;
    }

    else if(frontDQ == 0)
        frontDQ = sizeDQ - 1;

    else
        frontDQ = frontDQ - 1;

    arr[frontDQ] = key;
}

void Deque::insertRear(int key){
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }

    if(frontDQ == -1){
        frontDQ = 0;
        rearDQ = 0;
    }

    else if(rearDQ == sizeDQ - 1)
        rearDQ = 0;

    else
        rearDQ = rearDQ + 1;

    arr[rearDQ] = key;
}

void Deque::deleteFront(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return;
    }

    if(frontDQ == rearDQ){
        frontDQ = -1;
        rearDQ = -1;
    }
    else
        if(frontDQ == sizeDQ - 1)
            frontDQ = 0;
        else
            frontDQ = frontDQ + 1;
}

void Deque::deleteRear(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return;
    }

    if(frontDQ == rearDQ){
        frontDQ = -1;
        rearDQ = -1;
    }

    else if(rearDQ == 0)
        rearDQ = sizeDQ - 1;
    else
        rearDQ = rearDQ - 1;
}

int Deque::getFront(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return -1;
    }
    return arr[frontDQ];
}

int Deque::getRear(){
    if(isEmpty() || rearDQ < 0){
        cout<<"Underflow"<<endl;
        return -1;
    }
    return arr[rearDQ];
}

int main()
{
    Deque dq(5);
    cout << "Insert element at rear end  : 5 \n";
    dq.insertRear(5);

    cout << "insert element at rear end : 10 \n";
    dq.insertRear(10);

    cout << "get rear element " << " "
         << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;

    cout << "inserting element at front end \n";
    dq.insertFront(15);

    cout << "get front element " << " "
         << dq.getFront() << endl;

    dq.deleteFront();

    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl;

    return 0;
}
