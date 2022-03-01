// BY sorting array using STL and printing the element (K-1).
// Other ways are by using Max/Min Heap
// Time Complexity by using both method is O(nlogn)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int k, size;
    cout<<"\nEnter the size of Array = ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
       cin>>arr[i];
    }
    sort(arr,arr + size);
    cout<<"\nEnter the Kth Element = ";
    cin>>k;
    cout<<"\nKth smallest element = "<<arr[k-1]<<endl;
    return 0;
}
