#include <iostream>
#include <algorithm>

using namespace std;

bool isSubset(int a1[], int a2[], int m, int n){
    int i = 0, j = 0;
    if(m < n)
        return 0;

    sort(a1, a1 + m);
    sort(a2, a2 + n);

    while(i < n && j < m){
        if(a1[j] < a2[i])
            j++;
        else if(a1[j] == a2[i]){
            j++;
            i++;
        }
        else if(a1[j] > a2[i])
            return 0;
    }

    return (i < n)? false: true;
}

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};

    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    if(isSubset(arr1, arr2, m, n))
      cout<<"Subset";
    else
      cout<<"Not";
    return 0;
}
