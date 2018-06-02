//Program to cyclically rotate an array by one

#include <iostream>

using namespace std;

void rotate(int a[], int n){
    int temp = a[n-1];
    for(int i= n-1; i > 0; i--){
        a[i] = a[i-1];
    }
    a[0] = temp;
}

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n, a[20];
    cin>> n;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    rotate(a, n);
    printArray(a, n);

    return 0;
}

