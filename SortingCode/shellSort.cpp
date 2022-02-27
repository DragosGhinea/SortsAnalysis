#include "sort.h"
#include<bits/stdc++.h>
using namespace std;

void ShellSort::sort(vector<long long> &v, long long n){
    long long gap,i,j,temp;
    for(gap = n/2; gap > 0; gap /= 2){
        for(i=gap; i < n; i++){
            temp=v[i];

            for(j = i; j >= gap && v[j-gap] > temp; j-= gap)
                v[j] = v[j-gap];
            v[j]=temp;
        }
    }
}
