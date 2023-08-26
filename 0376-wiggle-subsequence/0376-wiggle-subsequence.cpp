// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (2, 1)); // 0 for down, 1 for up.
        
        for(int i = n - 1; i >= 0; i--)
            for(int j = i + 1; j < n; j++)
            {
                if(nums[i] == nums[j])
                     continue;
                
                bool dir = nums[i] < nums[j];
                
                dp[i][dir] = max(dp[i][dir], 1 + dp[j][!dir]);
            }
        
        auto mySort = [&] (vector<int> &a, vector<int> &b) -> bool 
        {
            return max(a[0], a[1]) < max(b[0], b[1]);
        };
        
        auto maxChain = *max_element(dp.begin(), dp.end(), mySort);
        
        return *max_element(maxChain.begin(), maxChain.end());
    }
};