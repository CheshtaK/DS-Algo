#include <iostream>

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int a[], int sizeA){
    for(int i = 0; i < sizeA; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

class MinHeap{
    int *harr;
    int heap_size;
public:
    MinHeap(int a[], int sizeA);
    void MinHeapify(int);

    int left(int i) {return (2*i + 1);}
    int right(int i) {return (2*i + 2);}

    int replaceMin(int x);
    int extractMin();
};

MinHeap::MinHeap(int a[], int sizeA){
    heap_size = sizeA;
    harr = a;
    int i = (heap_size - 1)/2;
    while(i >= 0){
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin(){
    int root = harr[0];
    if(heap_size > 1){
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
    }
    return root;
}

int MinHeap::replaceMin(int x){
    int root = harr[0];
    harr[0] = x;
    if(root < x)
        MinHeapify(0);
    return root;
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && harr[l] < harr[i])
        smallest = l;
    if(r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void sortK(int a[], int n, int k){
    int *harr = new int[k+1];
    for(int i = 0; i <= k && i < n; i++)
        harr[i] = a[i];
    MinHeap hp(harr, k+1);

    for(int i = k+1, ti = 0; ti < n; i++, ti++){
        if(i < n)
            a[ti] = hp.replaceMin(a[i]);
        else
            a[ti] = hp.extractMin();
    }
}

int main()
{
    int k = 3;
    int a[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(a)/sizeof(a[0]);
    sortK(a, n, k);

    printArray(a, n);
    return 0;
}
