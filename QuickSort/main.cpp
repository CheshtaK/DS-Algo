#include <iostream>

using namespace std;

int partitionE(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j <= high-1; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return (i+1);
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int pi = partitionE(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n, a[20];

    cout<<"Enter the size";
    cin>> n;

    cout<<"Enter an array";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    quickSort(a, 0, n-1);

    printArray(a, n);
    return 0;
}
