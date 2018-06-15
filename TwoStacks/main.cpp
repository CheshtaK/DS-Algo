#include <iostream>

using namespace std;

class twoStacks{
    int *arr;
    int size;
    int top1, top2;
public :
    twoStacks(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x){
        if(top1 < top2 - 1){
            top1 ++;
            arr[top1] = x;
        }
        else{
            cout<<"Overflow";
            exit(1);
        }
    }

    void push2(int x){
        if(top1 < top2 - 1){
            top2 --;
            arr[top2] = x;
        }
        else{
            cout<<"Overflow";
            exit(1);
        }
    }

    int pop1(){
        if(top1 >= 0){
            int x = arr[top1];
            top1 --;
            return x;
        }
        else{
            cout<<"Underflow";
            exit(1);
        }
    }

    int pop2(){
        if(top2 < size){
            int x = arr[top2];
            top2 ++;
            return x;
        }
        else{
            cout<<"Underflow";
            exit(1);
        }
    }
};

int main()
{
    twoStacks stacks(5);

    stacks.push1(5);
    stacks.push2(10);
    stacks.push2(15);
    stacks.push1(11);
    stacks.push2(7);

    cout<<"Popped element from stack 1 "<< stacks.pop1();
    cout<<endl;
    stacks.push2(40);
    cout<<"Popped element from stack 2 "<< stacks.pop2();

    return 0;
}
