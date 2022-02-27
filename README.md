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

To which we add the **STL Sort** from the C++

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

# Comparation (General Overview)
![Graph1](https://github.com/DragosGhinea/SortsAnalysis/blob/main/Graph1.png)
For the graph above we can already create a hierarchy (#1 being the most efficient):
 1. Radix Sort (Base 2^16)
 2. Radix Sort (Base 10)
 3. Quick Sort (Simple)
 4. Quick Sort (Three Way | Median of Three)
 5. Quick Sort (Randomized)
 6. STL Sort
 7. Merge Sort
 8. Heap Sort
 9. Shell Sort

But is it true all the time? Of course not.

![Graph2](https://github.com/DragosGhinea/SortsAnalysis/blob/main/Graph2.png)

In this second graph we see that even though most of the hierarchy above is kept, **Radix Sort (Base 10)** is having a hard time keeping up. What was modified that caused the **2nd place** to fall down to the **6th place** in performance? Well, as you can see in the mentioned input, the second graph was generated based on input with higher numbers which affects the performance of all sorts, but has a greater impact on the sort discussed above.

In this context, is it worth using base 10 instead of 2^16 seeing that it remains somehow constant in the second graph as efficiency? Most likely not. The only thing I have encountered is that base 2^16 doesn't handle well maximum values of 10^15 and above, no matter how small the amount of numbers.

## Shell Sort & Heap Sort Notice

![Graph3](https://github.com/DragosGhinea/SortsAnalysis/blob/main/Graph3.png)
Unlike the other graphs, we notice that on bigger amount of numbers shell sort is overall more efficient than heap sort. Is that correct all the time or just coincidence?

![Graph4](https://github.com/DragosGhinea/SortsAnalysis/blob/main/Graph4.png)
![Graph5](https://github.com/DragosGhinea/SortsAnalysis/blob/main/Graph5.png)

From the graphs above we see that it is true, but only for rather small maximum values.

## Variable Maximum Value and constant N

![Graph6](https://github.com/DragosGhinea/SortsAnalysis/blob/main/Graph6.png)
![Graph7](https://github.com/DragosGhinea/SortsAnalysis/blob/main/Graph7.png)

Once again from the graphs above we see that the maximum value of the generated number does not have a noticeable impact, unless we are talking about **Radix Sort (Base 10)**.

# Other observations

In general, the randomized version of quick sort should get more efficient than the simple and three way versions, but for some reason in my implementations it didn't happen.
