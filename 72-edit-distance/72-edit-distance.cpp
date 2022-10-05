class Solution {
public:
    int minimumDistance(string word1, string word2, int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 or j < 0)
        {
            if(j < 0)
                return i + 1;
            
            if(i < 0)
                return j + 1;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
            return dp[i][j] = minimumDistance(word1, word2, i - 1, j - 1, dp);
        
        else
        {
            return dp[i][j] = min(1 + minimumDistance(word1, word2, i, j - 1, dp), // Insert
                       min(1 + minimumDistance(word1, word2, i - 1, j, dp), // Delete
                           1 + minimumDistance(word1, word2, i - 1, j - 1, dp))); // Replace
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return minimumDistance(word1, word2, n - 1, m - 1, dp);
    }
};