#define ll long long

class Solution {
private:
    ll findMaxSum(vector<int> &nums, vector<vector<ll>> &dp, 
                  int sign, int i)
    {
        if(i == nums.size())
            return 0;
        
        if(dp[i][sign + 1] != INT_MAX)
            return dp[i][sign + 1];
        
        ll take = (sign * nums[i]) + findMaxSum(nums, dp, sign * -1, i + 1);
        ll notTake = findMaxSum(nums, dp, sign, i + 1);
        
        return dp[i][sign + 1] = max(take, notTake);
    }
    
public:
    ll maxAlternatingSum(vector<int>& nums) {
        vector<vector<ll>> dp(nums.size(), vector<ll> (3, INT_MAX));
        return findMaxSum(nums, dp, 1, 0);
    }
};