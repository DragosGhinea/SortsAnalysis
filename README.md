# Sorting Analysis Project
This project wants to present comparations between implementations of various popular (and rather efficient) sorting algorithms. 

The implemented sorting algorithms are:
 * **Radix Sort**
    * Base 10
    * Base 2^16
 * **Quick Sort**
    * Simple (Middle Pivot)
    * Randomized
    * Median of Three
 * **Merge Sort**
 * **Heap Sort**
 * **Shell Sort**

# Intern Functionality

The code can generate the relevant data in three ways:
 1. Generating to a file **data.csv** with a N that varies.
```cpp
generate_csv(long long nMin, long long nMax, long long nStep, long long maxim)
```
 2. Generating to a file **data.csv** with a MAXIM that varies, being multipled by 10 each step.
```cpp
generate_csv2(long long maximMin, long long maximMax, long long n)
```
 3. Printing to **screen** based on file input **tests.in**. An example of input file can be found inside the project, each line should contain **2 numbers**, representing **N (number of elements)** and **MAXIM (Maximal Value)**, in this order.
```cpp
screen_print()
```
By default, the **main.cpp** file contains the third option, the others two being used for generating the graphs below.
