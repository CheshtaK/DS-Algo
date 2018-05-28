#include <iostream>

using namespace std;

int n, a[20], k, item;

void insertItem(int a[], int n, int k, int item){
    for(int i=n-1; i>=k; i--){
        a[i] = a[i+1];
    }
    a[k] = item;
    n++;

    cout<<"Done";

    for(int j=0; j<n; j++){
        cout<<a[j]+" ";
    }
}

int main()
{
    cout<<"Enter the size";
    cin>> n;

    cout<<"Enter an array";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"Enter the position where you want to enter the number";
    cin>> k;

    cout<<"Enter the number you want to insert";
    cin>> item;

    insertItem(a, n, k, item);

    return 0;
}

