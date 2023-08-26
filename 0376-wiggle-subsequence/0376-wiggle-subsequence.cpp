class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), maxChain = 0;
        vector<vector<int>> dp(n, vector<int> (2, 1)); // 0 for down, 1 for up.
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(nums[i] == nums[j])
                     continue;
                
                bool dir = nums[i] < nums[j];
                
                dp[i][dir] = max(dp[i][dir], 1 + dp[j][!dir]);
            }
        }
        
        for(int i = 0; i < n; i++)
            maxChain = max(maxChain, max(dp[i][0], dp[i][1]));
        
        return maxChain;
    }
};