// Problem Statement.
// Brute Force Approach = Sorting Algo O(N2) 
// Lil Optimised Approach = Counting Sort {Counts the number of 0,1,2} O(2N)
// Optimised Approach using pointers = Low, Mid, High O(N)

#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void PrintArray(int arr[], int n)
{
    cout<<"\nArray :   ";
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
}


void Sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n-1;
    while(mid<=high)
    {
        switch(arr[mid])
        {
            case 0:  swap(arr[low++], arr[mid++]);
            break;

            case 1: mid++;
            break;

            case 2: swap(arr[mid], arr[high--]);
            break;
        }
    }
}


int main()
{
    
    int size;
    cout<<"\nEnter the size of array = ";
    cin>>size;
    int arr[size];
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    PrintArray(arr,size);
    Sort012(arr,size);
    PrintArray(arr,size);
    return 0;
}
