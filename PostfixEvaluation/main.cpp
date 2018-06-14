#include <iostream>
#include <stack>

using namespace std;

int evaluate(string s){
    stack<int> st;
    int l = s.length();

    for(int i = 0; i < l; i++){
        if(isdigit(s[i])){
            st.push(s[i]);
            cout<<st.top();
        }

        else{
            int a = st.top();
            st.pop();
            cout<<"a: "<<a<<endl;

            int b = st.top();
            st.pop();
            cout<<"b: "<<b<<endl;

            switch(s[i]){
                case '+' : st.push(a + b); break;
                case '-' : st.push(a - b); break;
                case '*' : st.push(a * b); break;
                case '/' : st.push(b / a); break;
            }
        }
    }
    return st.top();
}

int main()
{
    string exp = "231*+9-";
    cout<<evaluate(exp);
    return 0;
}
