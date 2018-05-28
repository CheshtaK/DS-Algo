#include <iostream>

using namespace std;

int a[20], n, item;
int flag = 0;

void linearSearch(int a[], int n, int item){
    for(int i=0; i<n; i++){
        if(a[i] == item)
            flag++;
    }

    if(flag)
        cout<<"Found";
    else
        cout<<"Not Found";
}

int main()
{
    cout<<"Enter the size";
    cin>> n;

    cout<<"Enter an array";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"Enter the item to be searched";
    cin>> item;

    linearSearch(a, n, item);
    return 0;
}
