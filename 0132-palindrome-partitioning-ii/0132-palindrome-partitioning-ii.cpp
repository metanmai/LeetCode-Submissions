class Solution {
private:
    void findMinimumCuts(int startIdx, int endIdx, 
                         vector<int> &dp, string s, int n) 
    {
        for(int start = startIdx, end = endIdx;
             start >= 0 and end < n and s[start] == s[end];
             start--, end++) 
        {
            int newCut = start == 0 ? 0 : dp[start - 1] + 1;
            dp[end] = min(dp[end], newCut);
        }
    }
    
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, INT_MAX);
        
        for(int mid = 0; mid < n; mid++) 
        {
            findMinimumCuts(mid, mid, dp, s, n);
            findMinimumCuts(mid - 1, mid, dp, s, n);
        }
        
        return dp[n - 1];
    }
};