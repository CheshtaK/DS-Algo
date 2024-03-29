#include <iostream>
#include <queue>

using namespace std;

void generateBinaryNumbers(int n){
    queue<string> q;
    q.push("1");

    while(n--){
        string s1 = q.front();
        q.pop();
        cout<<s1<<" ";

        string s2 = s1;
        q.push(s1.append("0"));

        q.push(s2.append("1"));
    }
}

int main()
{
    int n = 10;
    generateBinaryNumbers(n);
    return 0;
}
