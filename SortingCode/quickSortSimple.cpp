#include "sort.h"
#include<bits/stdc++.h>
using namespace std;

void swapSimple(long long *a, long long *b) {
  long long t = *a;
  *a = *b;
  *b = t;
}

long long partition(vector<long long> &v, long long i, long long j) {
  long long pivot = v[(i+j)/2];

  while(i<=j){
    while(v[i] < pivot){
        i++;
    };

    while(v[j] > pivot){
        j--;
    };

    if(i<=j){
        swapSimple(&v[i], &v[j]);
        i++;
        j--;
    }
  }
  return i;
}

void quicksort(vector<long long> &v, long long low, long long high) {
  if (low < high) {
    long long pi = partition(v, low, high);
    quicksort(v, low, pi-1);
    quicksort(v, pi, high);
  }
}


void QuickSortSimple::sort(vector<long long> &v, long long n){
    quicksort(v, 0, n-1);
}
