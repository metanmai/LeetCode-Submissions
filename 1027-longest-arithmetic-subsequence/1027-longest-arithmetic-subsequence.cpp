class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int n = nums.size(), maxDiff = maxi - mini, maxLen = 1;
        vector<vector<int>> dp(2 * maxDiff + 1, vector<int> (maxDiff + maxi + 1));
        
        for(int k = -maxDiff; k <= maxDiff; k++)
            for(int i = n - 1; i >= 0; i--)
                if(nums[i] + k >= 0)
                    maxLen = max(maxLen, 
                                 dp[k + maxDiff][nums[i]] = dp[k + maxDiff][nums[i] + k] + 1);
                else 
                     dp[k + maxDiff][nums[i]] = 1;
        
        return maxLen;
    }
};