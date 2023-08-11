class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size(), mini = 0, maxi = 0, swaps = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < nums[mini])
                mini = i;
            
            if(nums[i] >= nums[maxi])
                maxi = i;
        }
        
        swaps = n - maxi - 1 + mini;
        
        if(mini > maxi)
            swaps--;
        
        return swaps;
    }
};