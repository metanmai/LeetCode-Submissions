class Solution {
private:
public:
    int rearrangeSticks(int n, int k) {
        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long> (k + 1));
        
        for(int i = 0; i <= k; i++)
            dp[i][i] = 1;
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        
        return dp[n][k];
    }
};