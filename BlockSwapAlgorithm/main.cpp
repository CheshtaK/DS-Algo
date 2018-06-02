//Block swap algorithm for array rotation

#include <iostream>

using namespace std;

void swap(int a[], int fi, int si, int d){
    int i, temp;
   for(i = 0; i<d; i++)
   {
     temp = a[fi + i];
     a[fi + i] = a[si + i];
     a[si + i] = temp;
   }
}

void leftRotate(int a[], int n, int d){
    int i, j;
    if(d == 0 || d == n)
        return;
    i = d;
    j = n-d;
    while(i != j){
        if(i < j){
            swap(a, d-i, d+j-i, i);
            j -= i;
        }
        else{
            swap(a, d-i, d, j);
            i -= j;
        }
    }
    swap(a, d-i, d, i);
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

