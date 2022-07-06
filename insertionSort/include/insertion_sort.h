#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_
#include <iostream>
using namespace std;
template<class T>
void insertionSort(T& array)
{
    int size = array.size();
    class T::iterator it; 
    class T::iterator tempIt; 
    for(it = next(array.begin()); it != array.end(); it = next(it))
    {
        auto value = *it;
        tempIt = prev(it);
        while(tempIt != prev(array.begin()) && *tempIt > value)
        {
            iter_swap(next(tempIt), tempIt);
            tempIt--;
        }
    }
}
template<class T>
void insertionSort(T* array, int size)
{ 
    for(int i = 1; i < size; i++)
    {
        T value = array[i];
        int compIdx = i-1;
        while(compIdx >= 0 && array[compIdx] > value)
        {
            array[compIdx+1] = array[compIdx];
            compIdx--;
        } 
        array[compIdx+1] = value;
    }
}
#endif