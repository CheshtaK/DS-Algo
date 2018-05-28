#include <iostream>

using namespace std;

int n, a[20], k;

void deleteItem(int a[], int n, int k){
    for(int i=k; i<n; i++){
        a[i] = a[i+1];
    }
    n--;

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

    cout<<"Enter the position of the number to be deleted";
    cin>> k;

    deleteItem(a, n, k);
    return 0;
}
