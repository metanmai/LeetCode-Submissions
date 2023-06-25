class Solution {
private:
    int MOD = 1e9 + 7;
    
    int findAllRoutes(vector<vector<int>> &dp, vector<int> &locations, 
                      int start, int finish, int fuel, int n)
    {
        if(dp[start][fuel] != -1)
            return dp[start][fuel];
        
        int count = (start == finish);
        
        for(int i = 0; i < n; i++)
            if(i != start and fuel >= abs(locations[i] - locations[start]))
                count = (count + findAllRoutes(dp, locations, i, finish, 
                                               fuel - abs(locations[i] - locations[start]), n)) % MOD;
        
        return dp[start][fuel] = count;
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int> (fuel + 1, -1));
        
        return findAllRoutes(dp, locations, start, finish, fuel, n);
    }
};