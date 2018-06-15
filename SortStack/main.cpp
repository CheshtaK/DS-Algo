#include <iostream>
#include <stack>

using namespace std;

stack<char> st;
string ns;

char sortedInsert(char x){
    if(st.empty() || x > st.top()){
        st.push(x);
        return 'N';
    }

    int temp = st.top();
    st.pop();
    sortedInsert(temp);

    st.push(temp);
}

char sortStack(){
    if(!st.empty()){
        int x = st.top();
        st.pop();
        sortStack();

        sortedInsert(x);
    }
}

int main()
{
    st.push('30');
    st.push('-5');
    st.push('18');
    st.push('14');
    st.push('-3');

    sortStack();

    while(!st.empty()){
        char p = st.top();
        st.pop();
        ns += p;
    }

    cout<<ns[4]<<ns[3]<<ns[2]<<ns[1]<<ns[0];
    return 0;
}
