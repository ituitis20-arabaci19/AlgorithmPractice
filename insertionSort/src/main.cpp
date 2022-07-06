
#include <iostream>
#include <vector>
#include <list>
#include "insertion_sort.h"

using namespace std;


int main()
{

    vector<int> vecInt = {5,4,3,2,1};
    list<int> listInt = {5,4,3,2,1};
    vector<double> vecDouble = {5,4,4.5,2,1.1};
    list<double> listDouble = {5,4,4.5,2,1.1};
    int* arr = new int[5]{5,4,3,2,1};
    insertionSort(vecInt);
    insertionSort(listInt);

    insertionSort(vecDouble);
    insertionSort(listDouble);
    insertionSort(arr, 5);
    for(auto n : vecInt)
    {
        cout << n << " ";
    }
    cout<<endl;
    for(auto n : listInt)
    {
        cout << n << " ";
    }
    cout<<endl;
    for(auto n : vecDouble)
    {
        cout << n << " ";
    }
    cout<<endl;
    for(auto n : listDouble)
    {
        cout << n << " ";
    }
    cout<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    //insertionSort(vecDouble);
    //insertionSort(arr,5, 5);
}