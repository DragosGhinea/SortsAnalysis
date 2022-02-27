#include "sort.h"
#include<bits/stdc++.h>
using namespace std;

void swapHeap(long long *a, long long *b) {
  long long t = *a;
  *a = *b;
  *b = t;
}

void heapify(vector<long long> &v, long long n, long long i)
{
    long long largest = i; // set largest as root
    long long l = 2 * i + 1; // left = 2*i + 1
    long long r = 2 * i + 2; // right = 2*i + 2

    if (l < n && v[l] > v[largest])
        largest = l;

    if (r < n && v[r] > v[largest])
        largest = r;

    if (largest != i) {
        swapHeap(&v[i], &v[largest]);

        heapify(v, n, largest);
    }
}

void heapSort(vector<long long> &v, long long n) {

    long long i = n / 2 - 1;
    while(1){
        heapify(v, n, i);
        if(i==0)
            break;
        i--;
    }

    i = n - 1;
    while(1){
        swapHeap(&v[0], &v[i]);
        heapify(v, i, 0);

        if(i==0)
            break;
        i--;
    }

}

void HeapSort::sort(vector<long long> &v, long long n){
    heapSort(v, n);
}
