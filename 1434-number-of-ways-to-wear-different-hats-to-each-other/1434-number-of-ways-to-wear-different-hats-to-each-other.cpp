/* 
Instead of trying to assign people to hats, we assign hats to people, 
because there are way more hats than people.
*/

class Solution {
private:
    int MOD = 1e9 + 7;
    
    int findNumberOfWays(vector<vector<int>> &dp, map<int, vector<int>> &hatsToPeople, 
                         int i, int taken, int total)
    {
        if(taken == total)
            return 1;
        
        if(i > 40)
            return 0;
        
        if(dp[i][taken] != -1)
            return dp[i][taken];
        
        int ways = 0;
        
        if(hatsToPeople.count(i))
            for(int person : hatsToPeople[i])
                if((taken & (1 << person)) == 0) // Not assigned a hat.
                    ways = (ways + findNumberOfWays(dp, hatsToPeople, i + 1, taken | (1 << person), total)) % MOD; // Assign a hat to the person'th bit from the right.
        
        ways = (ways + findNumberOfWays(dp, hatsToPeople, i + 1, taken, total)) % MOD;
        
        return dp[i][taken] = ways;
    }
    
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size(), total = pow(2, n) - 1;
        map<int, vector<int>> hatsToPeople;
        vector<vector<int>> dp(41, vector<int> (total, -1));
        
        for(int i = 0; i < n; i++)
            for(int hat : hats[i])
                hatsToPeople[hat].push_back(i);
        
        return findNumberOfWays(dp, hatsToPeople, 1, 0, total);
    }
};