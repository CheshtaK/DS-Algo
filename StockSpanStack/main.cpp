#include <iostream>
#include <stack>

using namespace std;

void calculate(int price[], int n, int S[]){
    stack<int> st;
    st.push(0);

    S[0] = 1;

    for(int i = 1; i < n; i++){
        while(!st.empty() && price[st.top()] <= price[i])
            st.pop();

        S[i] = (st.empty()) ? (i+1) : (i - st.top());
        st.push(i);
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
