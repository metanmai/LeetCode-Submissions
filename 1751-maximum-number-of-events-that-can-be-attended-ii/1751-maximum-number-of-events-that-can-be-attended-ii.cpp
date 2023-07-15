class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int> (n + 1));
        vector<int> startTime(n);
        sort(events.begin(), events.end());
        
        for(int i = 0; i < n; i++)
            startTime[i] = events[i][0];
        
        for(int kk = 1; kk <= k; kk++)
        {
            for(int i = n - 1; i >= 0; i--)
            {
                int nextPos = (upper_bound(startTime.begin(), startTime.end(), events[i][1]) - 
                               startTime.begin());

                int take = events[i][2] + dp[kk - 1][nextPos];
                int notTake = dp[kk][i + 1];

                dp[kk][i] = max(take, notTake);
            }
        }
        
        return dp[k][0];
    }
};