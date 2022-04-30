/* Problem - Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease by K to each tower.

Time Complexity - O(N)
*/

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) 
    {
        sort(arr,arr+n);
        int Min, Max, diff = arr[n-1] - arr[0];
        
        for(int i=1 ; i<=n-1 ; i++)
        {
            if (arr[i] >= k)
            {
                Min = min(arr[0]+k , arr[i]-k);
                Max = max(arr [i-1]+k, arr[n-1]-k);
              //  cout<< Min << " " << Max << " " << " " << diff << endl;
                diff = min(diff, Max-Min);
               // cout<<diff<<endl;
            }        
        }
        
        return diff;
    }
};
