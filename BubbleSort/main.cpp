#include <iostream>

using namespace std;

int n, a[20];

void bubbleSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }

    for(int k=0; k<n; k++){
        cout<<a[k]<<" ";
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

    bubbleSort(a, n);
    return 0;
}
