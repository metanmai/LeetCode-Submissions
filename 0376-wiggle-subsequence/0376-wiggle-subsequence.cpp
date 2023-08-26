// DP Approach

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int n = nums.size(), up = 1, down = 1;
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i - 1])
                up = down + 1;
            
            else if(nums[i] < nums[i - 1])
                down = up + 1;
        }
        
        return max(up, down);
    }
};