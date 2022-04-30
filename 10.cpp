/* problem - 
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.
Time Comeplexity - O(N)
*/


class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int i = 0;
        int count = 0;
        if(n ==1)
            return 0;
        if(arr[0] == 0)
            return -1;
        while(i<n)
        {
            int temp = arr[i];
            if(temp == 0 )
                return -1;
            if((i+temp+1)>=n)
                return count+1;
            int step = 0;
            int maxStep = 0;
            for(int j = 1; j<=temp;j++)
            {
                if((j+arr[i+j])>=maxStep)
                {
                    maxStep=j+arr[i+j];
                    step = j;
                }
            }
            i = i+step;
            count++;
        }
        
        return count;
    }
};
