class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
            dp.push_back(max(dp[i], nums[i] + dp[i - 1]));
        
        return dp[dp.size() - 1];
    }
};