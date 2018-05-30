//Juggling algorithm for array rotation

#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

void leftRotate(int a[], int n, int d){
    for(int i=0; i<gcd(d, n); i++){
        int temp = a[i];
        int j = i;

        while(1){
            int k = j + d;
            if(k >= n)
                k = k - n;
            if(k == i)
                break;
            a[j] = a[k];
            j = k;
        }

        a[j] = temp;
    }
}

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n, a[20], d;
    cin>> n;

    cin>>d;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    leftRotate(a, n, d);
    printArray(a, n);

    return 0;
}
