class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0), target = totalSum / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool> (totalSum, false));
        if(totalSum % 2)
            return false;
        
        for(int currSum = target; currSum >= 0; currSum--)
            for(int i = n - 1; i >= 0; i--)
            {
                if(currSum == target)
                    dp[i][currSum] = true;
                
                else if(currSum + nums[i] > target)
                    dp[i][currSum] = dp[i + 1][currSum];
        
                else
                    dp[i][currSum] = dp[i + 1][currSum + nums[i]] or dp[i + 1][currSum];
            }
    
        return dp[0][0];
    }
    
};