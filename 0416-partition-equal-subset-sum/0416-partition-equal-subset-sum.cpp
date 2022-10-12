class Solution {
public:
    bool subsetSum(vector<int> nums, int target, int i, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;
        
        if(i < 0 or target < 0)
            return false;
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        return dp[i][target] = (subsetSum(nums, target - nums[i], i - 1, dp) or
                                subsetSum(nums, target, i - 1, dp));
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), target = accumulate(nums.begin(), nums.end(), 0);
        
        if(target % 2 != 0)
            return false;
        
        target /= 2;
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return subsetSum(nums, target, n - 1, dp);
    }
};