class Solution {
private:
    int findDistinctSubsequences(vector<vector<int>> &dp, string &s, string &t, 
                                 int i, int j, int n1, int n2)
    {
        if(j == n2)
            return 1;
        
        if(i == n1)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int take = 0, notTake = 0;
        
        if(s[i] == t[j])
            take = findDistinctSubsequences(dp, s, t, i + 1, j + 1, n1, n2);
        
        notTake = findDistinctSubsequences(dp, s, t, i + 1, j, n1, n2);
        
        return dp[i][j] = take + notTake;
    }
    
public:
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        
        return findDistinctSubsequences(dp, s, t, 0, 0, n1, n2);
    }
};