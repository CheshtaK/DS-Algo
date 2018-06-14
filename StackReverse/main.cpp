#include <iostream>
#include <stack>

using namespace std;

string reverseUsingStack(string s){
    int l = s.length();
    stack<char> st;
    string ns;
    int i;

    for(i = 0; i < l; i++)
        st.push(s[i]);

    for(i = 0; i < l; i++){
        char c = st.top();
        st.pop();
        ns += c;
    }

    return ns;
}

int main()
{
    string str = "Hello";
    string newS;

    newS = reverseUsingStack(str);
    cout<<newS;
    return 0;
}
