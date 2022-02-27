#include "sort.h"
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void swapRandomized(long long *a,  long long *b) {
   long long t = *a;
  *a = *b;
  *b = t;
}


 long long randomizedPartition(vector<long long> &v,  long long i, long long j){
    long long pivot = v[rand() % (j - i + 1) + i];

    while(i<=j){
        while(v[i] < pivot){
            i++;
        };

        while(v[j] > pivot){
            j--;
        };

        if(i<=j){
            swapRandomized(&v[i], &v[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSortRandomized(vector<long long> &v,  long long start,  long long end){

	if (start >= end) {
		return;
	}

    long long pivot = randomizedPartition(v, start, end);

	quickSortRandomized(v, start, pivot - 1);
	quickSortRandomized(v, pivot, end);
}

void QuickSortRandomized::sort(vector<long long> &v,  long long n){
    quickSortRandomized(v, 0, n-1);
}
