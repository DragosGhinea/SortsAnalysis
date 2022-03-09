#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<algorithm>
#include<chrono>
#include "sort.h"
using namespace std;
using namespace std::chrono;

void generate_vector2(vector<long long> &v, long long maxim){
    for (auto i = v.begin() ; i != v.end() ; i++){
        *i = rand()% maxim;
    }
}

void generate_vector(vector<long long> &v, long long maxim){
    mt19937_64 gen(time(NULL));

    uniform_int_distribution<long long> random(0, maxim);

    for(auto i = v.begin(); i!=v.end(); i++){
        *i = random(gen);
    }
}

bool test_sort(vector<long long> initial, vector<long long>& afterSort, long long n){
    sort(initial.begin(), initial.end());
    for(int i = 0; i < n; i++)
        if(initial[i] != afterSort[i]) return false;
    return true;
}

//This one only tests if the vector is a sorted one, we still need to check if
//the vector has the same elements before and after sort, and is not overwritting values
//destroying the sort purpouse. Therefore we use the test_sort above ^


/*bool test_sort(vector<long long> &v, long long n){
    for(long long i=1;i<n;i++)
        if(v[i]<v[i-1])
            return false;
    return true;
}*/

void screen_print(){
    ifstream tests("tests.in");

    long long N, maxim;
    while(tests>>N && tests>>maxim){

        vector<long long> randomGenerated(N);
        vector<long long> generatedCopy(N);

        generate_vector(randomGenerated, maxim);

        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        cout<<"Input: N="<<N<<" MAXIM="<<maxim<<endl;


        auto start = high_resolution_clock::now();
        sort(generatedCopy.begin(), generatedCopy.end());
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"STL Sort: "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        //==================================================================================================================


        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        RadixSort radixSort;
        start = high_resolution_clock::now();
        radixSort.sort10(generatedCopy, N);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout<<"Radix Sort (Base 10): "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        if(maxim>281474976710656){
                cout<<"Radix Sort (Base 2^16): Detected MAXIM="<<maxim<<" that might cause the process to exceed the long long allocated space, aborted sort.\n";
        }
        else{

            generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

            start = high_resolution_clock::now();
            radixSort.sort2(generatedCopy, N, 16);
            stop = high_resolution_clock::now();

            duration = duration_cast<microseconds>(stop - start);
            cout<<"Radix Sort (Base 2^16): "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;
        }

        //==================================================================================================================

        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        ShellSort shellSort;
        start = high_resolution_clock::now();
        shellSort.sort(generatedCopy, N);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout<<"Shell Sort: "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        //==================================================================================================================

        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        MergeSort mergeSort;
        start = high_resolution_clock::now();
        mergeSort.sort(generatedCopy, N);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout<<"Merge Sort: "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        //==================================================================================================================

        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        HeapSort heapSort;
        start = high_resolution_clock::now();
        heapSort.sort(generatedCopy, N);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout<<"Heap Sort: "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        //==================================================================================================================

        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        QuickSortThreeWay quickSortThreeWay;
        start = high_resolution_clock::now();
        quickSortThreeWay.sort(generatedCopy, N);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout<<"Quick Sort (Three Way): "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        //==================================================================================================================

        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        QuickSortRandomized quickSortRandomized;
        start = high_resolution_clock::now();
        quickSortRandomized.sort(generatedCopy, N);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout<<"Quick Sort (Randomized): "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        //==================================================================================================================

        generatedCopy.assign(randomGenerated.begin(), randomGenerated.end());

        QuickSortSimple quickSortSimple;
        start = high_resolution_clock::now();
        quickSortSimple.sort(generatedCopy, N);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout<<"Quick Sort (Simple): "<<duration.count()<<" microseconds | test_sort="<<test_sort(randomGenerated, generatedCopy, N)<<endl;

        cout<<endl<<endl;


    }

    tests.close();
}

//0=STL Sort
//1=Radix Sort (Base 10)
//2=Radix Sort (Base 2^16)
//3=Shell Sort
//4=Heap Sort
//5=Merge Sort
//6=Quick Sort (Three Way)
//7=Quick Sort (Randomized)
//8=Quick Sort (Simple)
long long getMicroseconds(int sortType, long long N, long long maxim, vector<long long> randomGenerated){
    if(sortType == 0){
            auto start = high_resolution_clock::now();
            sort(randomGenerated.begin(), randomGenerated.end());
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 1){
            RadixSort radixSort;
            auto start = high_resolution_clock::now();
            radixSort.sort10(randomGenerated, N);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 2){
            if(maxim>281474976710656){
                cout<<"[Radix Sort (Base 2^16)] Detected MAXIM="<<maxim<<" that might cause the process to exceed the long long allocated space, aborted sort.\n";
                return -100;
            }
            RadixSort radixSort;
            auto start = high_resolution_clock::now();
            radixSort.sort2(randomGenerated, N, 16);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 3){
            ShellSort shellSort;
            auto start = high_resolution_clock::now();
            shellSort.sort(randomGenerated, N);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 4){
            HeapSort heapSort;
            auto start = high_resolution_clock::now();
            heapSort.sort(randomGenerated, N);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 5){
            MergeSort mergeSort;
            auto start = high_resolution_clock::now();
            mergeSort.sort(randomGenerated, N);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 6){
            QuickSortThreeWay quickSort;
            auto start = high_resolution_clock::now();
            quickSort.sort(randomGenerated, N);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 7){
            QuickSortRandomized quickSort;
            auto start = high_resolution_clock::now();
            quickSort.sort(randomGenerated, N);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
    else if(sortType == 8){
            QuickSortSimple quickSort;
            auto start = high_resolution_clock::now();
            quickSort.sort(randomGenerated, N);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            return duration.count();
    }
}

void generate_csv(long long nMin, long long nMax, long long nStep, long long maxim){
    ofstream data("data.csv");
    data<<",STL Sort,Radix Sort(Base 10),Radix Sort(Base 2^16),Shell Sort,Heap Sort,Merge Sort,Quick Sort(Three Way),Quick Sort(Randomized),Quick Sort(Simple)\n";
    for(long long n = nMin; n<=nMax; n+=nStep){
        data<<n;
        vector<long long> randomGenerated(n);
        generate_vector(randomGenerated, maxim);
        for(int i=0;i<9;i++){
            data<<","<<getMicroseconds(i, n, maxim, randomGenerated);
        }
        data<<"\n";
    }

    data.close();
}

void generate_csv2(long long maximMin, long long maximMax, long long n){
    ofstream data("data.csv");
    data<<",STL Sort,Radix Sort(Base 10),Radix Sort(Base 2^16),Shell Sort,Heap Sort,Merge Sort,Quick Sort(Three Way),Quick Sort(Randomized),Quick Sort(Simple)\n";
    for(long long maxim = maximMin; maxim<=maximMax; maxim*=10){
        data<<maxim;
        vector<long long> randomGenerated(n);
        generate_vector(randomGenerated, maxim);
        for(int i=0;i<9;i++){
            data<<","<<getMicroseconds(i, n, maxim, randomGenerated);
        }
        data<<"\n";
    }

    data.close();
}


int main(){
    srand(time(NULL));

    screen_print();

    return 0;
}
