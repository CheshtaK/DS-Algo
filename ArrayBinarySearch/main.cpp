#include <iostream>

using namespace std;

int a[20], n, item;
int low, high;

int binarySearch(int a[], int n, int item){
    low = 0;
    high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == item)
            return mid;
        else if(a[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    cout<<"Enter the size";
    cin>> n;

    cout<<"Enter an array";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"Enter the item to be searched";
    cin>> item;

    int x = binarySearch(a, n, item);

    if(x != -1)
        cout<<"Found at "<<x+1 ;
    else
        cout<<"Not found";

    return 0;
}
