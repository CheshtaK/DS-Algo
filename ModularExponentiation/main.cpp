/* x^n mod M
   Time complexity is O(log n)*/

#include <iostream>

using namespace std;

long mod(long x, long n, int M){
    long y;

    if (n == 0)
        return 1;
    else if (n%2 == 0){
        y = mod(x, n/2, M);
        return (y*y) % M;
    }
    else
        return ((x%M) * mod(x, n-1, M)) % M;
}

int main()
{
    long x, n;
    int M;
    cin>> x;
    cin>> n;
    cin>> M;

    float result = mod(x, n, M);
    cout<< result;
    return 0;
}
