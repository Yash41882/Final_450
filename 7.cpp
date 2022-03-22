// Problem Statement - Given an array, rotate the array by one position in clock-wise direction.

#include<bits/stdc++.h>
using namespace std;


void Rotate(int arr[], int size)  
{
    int temp = arr[size-1];
    
    for(int i=size-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void inputArr(int arr[], int size)
{
    cout<<"\nEnter the values in the array : ";
    for(int i=0; i<size ; i++)
    {
        cin>>arr[i];
    }
}

void printArr(int arr[], int size)
{
    cout<<"\nThe Values in the array : ";
    for(int i=0; i<size ; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


int main()
{
    int n;
    cout<<"\nEnter the size of Array A: ";
    cin>>n;

    int A[n];
    inputArr(A,n);

    Rotate(A,n);

    cout<<"\nRotated Array: ";
    printArr(A,n);
    return 0;
}
