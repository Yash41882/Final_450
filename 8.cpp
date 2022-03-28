// Problem Statement - Given an array Arr[] of N integers.
// Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

#include<bits/stdc++.h>
using namespace std;


//Using Brute Force Approach --> That Means we are gonna check for evey possible case. (Time Complexity = N^3)
//It is more time consuming and thus is more complex.

int Largest_SubArray_Sum(int arr[], int n)
{
    int Largest_Sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int SubArray_Sum = 0;
            for(int k = i; k <= j; k++)
            {
                SubArray_Sum += arr[k] ;
            }
            if(SubArray_Sum > Largest_Sum)
            {
                Largest_Sum = SubArray_Sum;
            }
        }
    }
    return Largest_Sum;
}

// Using Prefix Sum Approach (Time Complexity = N^2)
// In this case the time taken to compute sum is irrespective the size of array

int Largest_SubArray_Sum2(int arr[], int n)
{
    int Largest_Sum = INT_MIN;
    int prefix_sum[100] = {0};
    prefix_sum[0] = arr[0];

    for(int i = 0; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[ i - 1] + arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int SubArray_Sum = 0;
            SubArray_Sum = (i > 0) ? prefix_sum[j] - prefix_sum[i-1] : arr[j];
            if(SubArray_Sum > Largest_Sum)
            {
                Largest_Sum = SubArray_Sum;
            }
        }
    }
    return Largest_Sum;
}

// Using Kadane's Algorith (Time Complexity = N)
// In this case the the rsult is get in a linear interation

int Largest_SubArray_Sum3(int arr[], int n)
{
    int Largest_Sum = INT_MIN;
    int Current_Sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        Current_Sum = Current_Sum + arr[i];
        
        if(Largest_Sum < Current_Sum)
        {
            Largest_Sum = Current_Sum;
        }
        
        if(Current_Sum < 0)
        {
            Current_Sum = 0;
        }
    }

    return Largest_Sum;
}


int Print_Array(int arr[], int n)
{
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"\t"<<arr[i];
    }
    cout<<endl;
    return 0;
}


int Input_Array(int arr[], int n)
{
    cout<<"\nEnter the Elements in Array = ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    return 0;
}


int main()
{
    system("CLS");
    int n;
    cout<<"\nEnter the size of Array = ";
    cin>>n;
    int arr[n];

    Input_Array(arr,n);

    Print_Array(arr,n);

    cout<<"\nLargest Sub Array Sum1 is = "<<Largest_SubArray_Sum(arr,n);

    cout<<"\nLargest Sub Array Sum3 is = "<<Largest_SubArray_Sum3(arr,n);

    return 0;
}
