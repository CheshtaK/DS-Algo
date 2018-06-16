//Time complexity - 0(n^2)

#include <iostream>

using namespace std;

void calculate(int price[], int n, int S[]){
    S[0] = 1;

    for(int i = 1; i < n; i++){
        S[i] = 1;

        for(int j = i-1; (j >= 0) && (price[i] >= price[j]); j--)
            S[i]++;
    }
}

void print(int S[], int n){
    for(int i = 0; i < n; i++)
        cout<<S[i]<<" ";
}

int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];

    calculate(price, n, S);
    print(S,n);
    return 0;
}
