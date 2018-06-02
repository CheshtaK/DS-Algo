/* A program that, given an array A[] of n numbers and another number x,
determines whether or not there exist two elements in S whose sum is exactly x.*/

#include <iostream>

using namespace std;

void sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

bool sumFound(int a[], int n, int sum){
    int l, r;
    sort(a, n);

    l = 0;
    r = n-1;
    while(l < r){
        if(a[l] + a[r] == sum)
            return 1;
        else if(a[l] + a[r] < sum)
            l++;
        else
            r--;
    }
    return false;
}

int main()
{
    int n, a[20], sum;
    cin>> n;
    cin>> sum;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    if(sumFound(a, n, sum))
        cout << "Array has two elements with given sum";
    else
        cout << "Array doesn't have two elements with given sum";
    return 0;
}
