/* Given a sorted and rotated array, find if there is a pair with a given sum
   Time complexity - O(n)*/
#include <iostream>

using namespace std;

bool sumFound(int a[], int n, int sum){
    int i;
    for(i=0; i<n-1; i++){
        if(a[i] > a[i+1])
            break;
    }
    int l = (i+1) % n;
    int r = i;

    while(l != r){
        if(a[l] + a[r] == sum)
            return true;
        if(a[l] + a[r] < sum)
            l = (l+1) % n;
        else
            r = (n + r -1) % n;
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
