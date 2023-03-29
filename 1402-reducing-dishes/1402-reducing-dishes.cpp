class Solution {
private:
    int n;
    
    int findMaxSatisfaction(vector<int> &satisfaction, vector<vector<int>> &dp, int i, int time)
    {
        if(i == n)
            return 0;
        
        if(dp[i][time] != -1)
            return dp[i][time];
        
        int take = satisfaction[i] * time + findMaxSatisfaction(satisfaction, dp, i + 1, time + 1);
        int notTake = findMaxSatisfaction(satisfaction, dp, i + 1, time);
        
        return dp[i][time] = max(take, notTake);
        
    }
    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return findMaxSatisfaction(satisfaction, dp, 0, 1);
    }
};