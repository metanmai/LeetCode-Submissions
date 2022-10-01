class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= m; i2++)
                if(text1[i1 - 1] == text2[i2 - 1]) // Index is shifted by 1.
                    dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                
                else
                    dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
        
        return dp[n][m];
    }
};