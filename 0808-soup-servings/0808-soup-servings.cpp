// This problem is tight af.

class Solution {
public:
    double soupServings(int n) {
        int m = ceil(n / 25.0f);
        unordered_map<int, unordered_map<int, double>> dp;
        dp[0][0] = 0.5;

        auto getDP = [&] (int i, int j) -> double 
        {
            return (dp[max(0, i - 4)][j] + 
                    dp[max(0, i - 3)][j - 1] +
                    dp[max(0, i - 2)][max(0, j - 2)] + 
                    dp[i - 1][max(0, j - 3)]) / 4;
        };
        
        for(int k = 1; k <= m; k++) 
        {
            dp[0][k] = 1;
            dp[k][0] = 0;
            
            for(int j = 1; j <= k; j++) 
            {
                dp[j][k] = getDP(j, k);
                dp[k][j] = getDP(k, j);
            }
            
            if(dp[k][k] > 1 - 1e-5)
                return 1;
            
        }
        
        return dp[m][m];
    }
};