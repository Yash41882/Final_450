//Using Divide and Conqueror or Tournament Method
// Complexity = T(n) = (3n/2) – 2
  

#include <iostream>
using namespace std;
 
/* This structure is used to return 
 two values from a function */
struct MaxMin {
    int min;
    int max;
}; 
 
/* Implementation of tournament method using recursion */
struct MaxMin Min_Max(int *array, int left, int right) {
    struct MaxMin result, Left, Right;       
    int mid;
    
    result.max = array[left];
    result.min = array[left];
   
    if(right == left)
        return result; 
    /* Split the array into two equal sub arrays and 
    recursively find max and min in both sub array */
    mid = (left + right)/2;  
    Left = Min_Max(array, left, mid);
    Right = Min_Max(array, mid+1, right);  
    
    /* Take the maximum of both sub array */
    if (Left.max > Right.max)
       result.max = Left.max;
    else
       result.max = Right.max;    
     
    /* Take the minimum of both sub array */
    if (Left.min < Right.min)
       result.min = Left.min;
    else
       result.min = Right.min;     
  
    /* Return the maximum and minimum of whole array */
    return result;
}
 
int main(){
    int size;

    cout<<"\nEnter the size of Array = ";
    cin>>size;
    
    //Input of array
    int array[size];
    cout<<"\nEnter the values in Array = ";
    for(int i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    struct MaxMin maxmin = Min_Max(array, 0, size-1); 
     
    cout<< "Maximum = "<< maxmin.max<< endl;
    cout<< "Minimum = "<< maxmin.min<< endl;
     
    return 0;
}
