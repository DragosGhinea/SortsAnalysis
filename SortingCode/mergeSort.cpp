#include "sort.h"
#include<bits/stdc++.h>
using namespace std;

vector<long long> leftArray;
vector<long long> rightArray;

void merge(vector<long long> &v, long long left, long long mid, long long right){
    auto leftSize = mid - left + 1;
    auto rightSize = right - mid;

    //it is more efficient if declared globally
    //vector<long long> leftArray(leftSize);
    //vector<long long> rightArray(rightSize);

    for(auto i = 0; i < leftSize; i++)
        leftArray[i]=v[left+i];
    for(auto j = 0; j < rightSize; j++)
        rightArray[j] = v[mid+1+j];

    auto indexArrayOne = 0, indexArrayTwo = 0;
    long long indexOfMergedArray = left;

    while(indexArrayOne < leftSize && indexArrayTwo < rightSize){
        if(leftArray[indexArrayOne] <= rightArray[indexArrayTwo]){
            v[indexOfMergedArray] = leftArray[indexArrayOne];
            indexArrayOne++;
        }
        else{
            v[indexOfMergedArray] = rightArray[indexArrayTwo];
            indexArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(indexArrayOne < leftSize){
        v[indexOfMergedArray] = leftArray[indexArrayOne];
        indexArrayOne++;
        indexOfMergedArray++;
    }

    while(indexArrayTwo < rightSize){
        v[indexOfMergedArray] = rightArray[indexArrayTwo];
        indexArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(vector<long long> &v, long long begin, long long end){
    if(begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(v, begin, mid);
    mergeSort(v, mid+1, end);
    merge(v, begin, mid, end);
}

void MergeSort::sort(vector<long long> &v, long long n){
    leftArray= vector<long long>(n);
    rightArray= vector<long long>(n);
    mergeSort(v, 0, n-1);
}
