#pragma once
#include<bits/stdc++.h>

using namespace std;

class RadixSort{
    public:
        void sort10(vector<long long> &v, long long n);
        void sort2(vector<long long> &v, long long n, long long powerOf2);

};

class MergeSort{
    public:
        void sort(vector<long long> &v, long long n);
};

class ShellSort{
    public:
        void sort(vector<long long> &v, long long n);
};

class QuickSortSimple{
    public:
        void sort(vector<long long> &v, long long n);
};

class QuickSortThreeWay{
    public:
        void sort(vector<long long> &v, long long n);
};

class QuickSortRandomized{
    public:
        void sort(vector<long long> &v, long long n);
};

class HeapSort{
    public:
        void sort(vector<long long> &v, long long n);
};
