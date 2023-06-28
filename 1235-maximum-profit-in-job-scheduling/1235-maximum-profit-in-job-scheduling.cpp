class Solution {
  public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n + 1);
        
        vector<vector<int>> jobs(n);
        
        for(int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        
        for(int i = n - 1; i >= 0; i--)
        {
            int nextPos = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
        
            int take = jobs[i][2] + dp[nextPos];
            int notTake = dp[i + 1];
            
            dp[i] = max(take, notTake);
        }
        
        return dp[0];
    }
};