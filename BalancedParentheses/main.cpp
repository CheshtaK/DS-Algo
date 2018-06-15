#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool balanced(char exp[]){
    stack<char> s;
    char a,b,c;

    for(int i = 0; i < strlen(exp); i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            s.push(exp[i]);
        else{
            switch(exp[i]){
                case ')': {
                    if(s.empty())
                        return false;
                    a = s.top();
                    s.pop();
                    if(a == '{' || a == '[')
                        return false;
                    break;
                }

                case '}': {
                    if(s.empty())
                        return false;
                    b = s.top();
                    s.pop();
                    if(b == '(' || b == '[')
                        return false;
                    break;
                }

                case ']': {
                    if(s.empty())
                        return false;
                    c = s.top();
                    s.pop();
                    if(c == '(' || c == '{')
                        return false;
                    break;
                }
            }
        }
    }

    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    char exp[] = "{()}[]";

    if(balanced(exp))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}
