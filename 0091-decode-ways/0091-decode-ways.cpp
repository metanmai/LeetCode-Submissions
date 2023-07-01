class Solution {
private:
    int findDecodings(vector<int> &dp, string &s, int i, int n)
    {
        if(i == n)
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int pick = findDecodings(dp, s, i + 1, n), notPick = 0;
        
        if(i + 1 < n and stoi(s.substr(i, 2)) <= 26)
            notPick = findDecodings(dp, s, i + 2, n);
        
        return dp[i] = pick + notPick;
    }
    
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        
        return findDecodings(dp, s, 0, n);
    }
};