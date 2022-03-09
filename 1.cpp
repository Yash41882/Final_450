// Reverse the array
// Time Complexity = O(n/2) as half of the array is traversed.

#include<iostream>
using namespace std;

int PrintArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}

int revArr(int arr[],int size)
{
    for(int i=0;i<size/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
    return 0;
}

int main()
{
    int size;
    cout<<"\nEnter the size of Array = ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
       cin>>arr[i];
    }
    cout<<endl;
    revArr(arr,size);
    cout<<"\nReversed Array = ";
    PrintArray(arr,size);
    return 0;
}
