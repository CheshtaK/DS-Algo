//Program for array rotation

#include <iostream>

using namespace std;

void leftRotateByOne(int a[], int n){
    int temp = a[0];
    int i;
    for(i=0; i<n-1; i++)
        a[i] = a[i+1];
    a[i] = temp;
}

void leftRotate(int a[], int n, int d){
    for(int i=0; i<d; i++)
        leftRotateByOne(a, n);
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
