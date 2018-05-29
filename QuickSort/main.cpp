#include <iostream>

using namespace std;

int partition(int a[], int start, int end){
    int pivotValue = a[start];
    int pivotPosition = start;
     for (int i=start+1; i<=end; i++)
     {
        if (pivotValue > a[i])
       {
          swap(a[pivotPosition+1], a[i]);
          swap(a[pivotPosition] , a[pivotPosition+1]);
          pivotPosition++;
       }
     }
    return pivotPosition;
}

void quickSort(int a[], int n, int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, n, low, pi-1);
        quickSort(a, n, pi+1, high);
    }

    for(int j=0; j<n; j++){
        cout<<a[j]<<" ";
    }
}

int main()
{
    int n, a[20];
    int low = 0;
    int high = n;

    cout<<"Enter the size";
    cin>> n;

    cout<<"Enter an array";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    quickSort(a, n, low, high);
    return 0;
}
