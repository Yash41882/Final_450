// Problem Statement - Given two arrays a[] and b[] of size n and m respectively.
// The task is to find union between these two arrays.

#include<bits/stdc++.h>
using namespace std;


int doUnion(int a[], int n, int b[], int m)  
{
    // using hashmap - it wont store the duplicate value
    // storing values of both array in a single hashtable
    unordered_set<int> p;
    for(int i=0;i<n;i++)
    {
        p.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        p.insert(b[i]);
    }
    return p.size();
}

void input(int arr[], int size)
{
    cout<<"\nEnter the values in the array : ";
    for(int i=0; i<size ; i++)
    {
        cin>>arr[i];
    }
}


int main()
{
    int n1, n2;
    cout<<"\nEnter the size of Array A: ";
    cin>>n1;

    int A[n1];
    input(A,n1);

    cout<<"\nEnter the size of Array B: ";
    cin>>n2;
    
    int B[n2];
    input(B,n2);

    cout<<"\n Size of Union Array: "<< doUnion(A,n1,B,n2);
    return 0;
}
