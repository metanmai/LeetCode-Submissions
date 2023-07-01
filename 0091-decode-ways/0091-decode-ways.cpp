class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        
        dp[n] = 1;
        
        for(int i = n - 1; i >= 0; i--)
            if(s[i] != '0')
                dp[i] = dp[i + 1] + ((i + 1 < n and 
                                      stoi(s.substr(i, 2)) <= 26) ? dp[i + 2] : 0);
        
        return dp[0];
    }
};