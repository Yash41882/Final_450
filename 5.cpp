// Problem Statement.
// Move all the negative elements to one side of the array.
// Brute Force Approach = Sorting Algo O(N2) 
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


void Sort(int arr[], int n)
{
    int low = 0, mid = 0, high = n-1;
    while(mid<=high)
    {
        if (arr[mid] < 0) 
        {
            swap(arr[low++], arr[mid++]);
        }

        else 
        {
            if (arr[mid] >= 0)
            {
                swap(arr[mid], arr[high--]);
            }
        }
        
            //mid++;
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
    Sort(arr,size);
    PrintArray(arr,size);
    return 0;
}
