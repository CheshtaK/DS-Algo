//Reversal algorithm for array rotation

#include <iostream>

using namespace std;

void reverseArray(int a[], int start, int endw){
    while(start < endw){
        int temp = a[start];
        a[start] = a[endw];
        a[endw] = temp;
        start ++;
        endw --;
    }
}

void leftRotate(int a[], int n, int d){
    reverseArray(a, 0, d-1);
    reverseArray(a, d, n-1);
    reverseArray(a, 0, n-1);
}

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n, a[20], d;
    cin>> n;

    cin>>d;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    leftRotate(a, n, d);
    printArray(a, n);

    return 0;
}
