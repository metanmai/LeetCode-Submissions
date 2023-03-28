class Solution {
private:
    int findMinimumCost(vector<int> &days, vector<int> &costs, vector<int> &dp,
                        vector<bool> &present, int currDay)
    {
        while(currDay <= 365 and !present[currDay])
            currDay++;
        
        if(currDay > 365)
            return 0;
        
        if(dp[currDay] != -1)
            return dp[currDay];
        
        int cost1 = costs[0] + findMinimumCost(days, costs, dp, present, currDay + 1);
        int cost7 = costs[1] + findMinimumCost(days, costs, dp, present, currDay + 7);
        int cost30 = costs[2] + findMinimumCost(days, costs, dp, present, currDay + 30);
            
        return dp[currDay] = min(cost1, min(cost7, cost30));
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<bool> present(366);
        vector<int> dp(366, -1);
        
        for(int i = 0; i < n; i++)
            present[days[i]] = 1;
        
        return findMinimumCost(days, costs, dp, present, days[0]);
    }
};