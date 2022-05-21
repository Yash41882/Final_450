/* problem - 
Given an arr with n+1 size and elements from range 1-n. Find the duplicate element in it.
Time Comeplexity = O(N)
*/

// Using Hashmap, Time Comeplexity - O(N) Space Complexity - O(N)
int findDuplicate(vector<int>& nums) {
        unordered_map <int, int> umap;
        
        for(int i=0; i< nums.size(); i++)
        {
            if(umap.find(nums[i])==umap.end())
            {
                umap[nums[i]]=i;
            }
            else
            {

                return nums[i];
            }
        }
        return 0;
    }



// Floyd tortoise hare method, Time Comeplexity - O(N)
int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
