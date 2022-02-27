#include "sort.h"
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

long long maxim(vector<long long> &v){
    auto maxGasit = v[0];
    for(auto i = v.begin()+1; i!=v.end(); i++)
        if(maxGasit < *i)
            maxGasit = *i;
    return maxGasit;
}

vector<long long> output;

void countSort10(vector<long long> &v, long long n, unsigned long long poz){
    long long count[10] = {};
    long long i;

    for(i = 0; i<n; i++)
        count[(v[i] / poz)%10]++;

    for(i = 1; i < 10; i++)
        count[i] += count[i-1];

    for(i = n - 1; i >= 0; i--){
        output[count[(v[i] / poz) % 10] - 1] = v[i];
        count[(v[i] / poz) % 10]--;
    }

    v=output;
}

void countSort2(vector<long long> &v, long long n, unsigned long long power, long long calculated){
    long long count[calculated+1] = {};
    long long i;

    for(i = 0; i<n; i++)
        count[(v[i] >> power) & calculated]++;

    for(i = 1; i <= calculated; i++)
        count[i] += count[i-1];

    for(i = n - 1; i >= 0; i--){
        output[count[(v[i] >> power) & calculated] - 1] = v[i];
        count[(v[i] >> power) & calculated]--;
    }

    v=output;
}

void RadixSort::sort10(vector<long long> &v, long long n){
    long long m=maxim(v);
    output=vector<long long>(n);

    for(long long poz = 1; m / poz > 0; poz *= 10){
        countSort10(v, n, poz);
    }
}

void RadixSort::sort2(vector<long long> &v, long long n, long long power){
    long long m=maxim(v);
    output=vector<long long>(n);
    long long calculated=pow(2, power)-1; //used instead of modulo

    for(long long poz = 0; m >> poz > 0; poz += power){
        countSort2(v, n, poz, calculated);
    }
}
