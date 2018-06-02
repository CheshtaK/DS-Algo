/* An element in a sorted array can be found in O(log n) time via binary search.
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
Devise a way to find an element in the rotated array in O(log n) time.*/

#include <iostream>

using namespace std;

int searchItem(int a[], int l, int h, int item){
    if(l > h)
        return -1;
    int mid = (l + h)/2;
    if(a[mid] == item)
        return mid;
    if(a[l] <= a[mid]){
        if(item >= a[l] && item <= a[mid])
            return searchItem(a, l, mid-1, item);
        return searchItem(a, mid+1, h, item);
    }

    if(item >= a[mid] && item <= a[h])
        return searchItem(a, mid+1, h, item);
    return searchItem(a, l, mid-1, item);
}

int main()
{
    int n, a[20], item;
    cin>> n;
    cin>> item;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int x = searchItem(a, 0, n-1, item);
    if(x != -1)
        cout<<"Index: "<<x;
    else
        cout<<"Key not found";

    return 0;
}
