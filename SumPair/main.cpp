#include <iostream>
#include <unordered_set>

using namespace std;

void printPairs(int a[], int arr_size, int sum){
    unordered_set<int> s;
    for(int i = 0; i < arr_size; i++){
        int temp = sum - a[i];
        if(temp >= 0 && s.find(temp) != s.end())
            cout<<a[i]<<" + "<<temp;
        s.insert(a[i]);
    }
}

int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);

    printPairs(A, arr_size, n);
    return 0;
}
