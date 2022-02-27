#include "sort.h"
#include<bits/stdc++.h>
using namespace std;

void swapThreeWay(long long *a, long long *b) {
  long long t = *a;
  *a = *b;
  *b = t;
}

//https://stackoverflow.com/questions/5666717/median-3-quick-sort-implementation/7199398
long long medianOfThreePartition(vector<long long> &a,long long p, long long r) {
    long long x=a[p],y=a[(r-p)/2+p],z=a[r-1],i=p-1,j=r;
    if (y>x && y<z || y>z && y<x ) x=y;
    else if (z>x && z<y || z>y && z<x ) x=z;
    while (1) {
        do  {j--;} while (a[j] > x);
        do  {i++;} while (a[i] < x);
        if  (i < j) swapThreeWay(&a[i],&a[j]);
        else return j+1;
    }
}

void quickSortThreeWay(vector<long long> &a,long long start,long long end) {
    long long q;
    if (end-start<2) return;
    q=medianOfThreePartition(a,start,end);
    quickSortThreeWay(a,start,q);
    quickSortThreeWay(a,q,end);
}

void QuickSortThreeWay::sort(vector<long long> &v, long long n){
    quickSortThreeWay(v, 0, n);
}
