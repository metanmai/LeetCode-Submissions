class Solution {
 public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int> (target + 1));
        
        dp[n][target] = 1;
        
        for(int die = n - 1; die >= 0; die--)
            for(int currSum = 0; currSum <= target; currSum++)
                for(int i = 1; i <= min(k, target - currSum); i++)
                    dp[die][currSum] = (dp[die + 1][currSum + i] + dp[die][currSum]) % MOD;
        
        return dp[0][0];
    }
};