class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k + maxPts);
        dp[0] = 1;
        
        double sum = 0;
        
        for(int i = k; i < k + maxPts; i++)
            sum += dp[i] = i <= n;
        
        for(int i = k - 1; i >= 0; i--)
        {
            dp[i] = (double) sum / maxPts;
            sum += dp[i] - dp[i + maxPts];
        }
        
        return dp[0];
    }
};