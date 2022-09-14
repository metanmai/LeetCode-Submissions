class Solution {
public:
    int findSum(vector<int> nums, int sum, int target, int pos, int maxSum, int &count, vector<vector<int>> &dp)
    {
        if(pos == nums.size())
        {
            if(sum == target)
                return 1;
            else
                return 0;
            
        }
        
        else if(dp[maxSum + sum][pos] != maxSum + 1)
            return dp[maxSum + sum][pos];
        
        else
            return dp[maxSum + sum][pos] = (findSum(nums, sum + nums[pos], target, pos + 1, maxSum, count, dp) +
                                            findSum(nums, sum - nums[pos], target, pos + 1, maxSum, count, dp));
                                            
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0, maxSum = 0;
        for(auto i : nums)
            maxSum += abs(i);
        
        vector<vector<int>> dp(maxSum * 2 + 1, vector<int> (nums.size(), maxSum + 1)); 
        return findSum(nums, 0, target, 0, maxSum, count, dp);
    }
};