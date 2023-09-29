class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(), prev = -1;
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i - 1] > 0)
            {
                if(prev == -1)
                    prev = 1;
                
                else if(prev == 1)
                    continue;
                
                else
                    return false;
            }
            
            if(nums[i] - nums[i - 1] < 0)
            {
                if(prev == -1)
                    prev = 0;
                
                else if(prev == 0)
                    continue;
                
                else
                    return false;
            }
        }
        
        return true;
    }
};