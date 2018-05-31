/* Pow(x, n)
   {
      if(n == 0)
        return 1;
      else
        return x * Pow(x, n-1);
   }

   For above we have O(n).
   The following has O(log n). */

#include <iostream>

using namespace std;

float pow(int x, int n){
    float y;
    if(n == 0){
        return 1;
    }
    else if(n%2 == 0){
        y = pow(x, n/2);
        return y*y;
    }
    else
        return x*pow(x, n-1);
}

int main()
{
    int x, n;
    cin>> x;
    cin>> n;

    float result = pow(x, n);
    cout<< result;
    return 0;
}
