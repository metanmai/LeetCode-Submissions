class Solution {
private:
    bool wildcardMatching(vector<vector<int>> &dp, string &s, string &p, 
                          int i, int j, int n1, int n2)
    {
        if(i == n1 and j == n2)
            return true;
        
        if(j == n2)
            return false;
        
        if(i == n1)
            return p[j] == '*' and wildcardMatching(dp, s, p, i, j + 1, n1, n2);
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] or p[j] == '?')
            return dp[i][j] = wildcardMatching(dp, s, p, i + 1, j + 1, n1, n2);
        
        else if(p[j] == '*')
            return dp[i][j] = (wildcardMatching(dp, s, p, i + 1, j, n1, n2) or
                               wildcardMatching(dp, s, p, i + 1, j + 1, n1, n2) or
                               wildcardMatching(dp, s, p, i, j + 1, n1, n2));

        return false;
    }
    
public:
    bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        
        return wildcardMatching(dp, s, p, 0, 0, n1, n2);
    }
};