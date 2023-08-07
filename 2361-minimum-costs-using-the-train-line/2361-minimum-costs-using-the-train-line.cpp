#define ll long long

class Solution {
private:
    ll findMinCosts(vector<vector<ll>> &dp, vector<int> &regular, vector<int> &express, 
                     int expressCost, int i, int route, int n)
    {
        if(i < 0)
            return 0;
        
        if(dp[route][i] != -1)
            return dp[route][i];
        
        ll reg = regular[i] + findMinCosts(dp, regular, express, expressCost, i - 1, 0, n);
        ll exp = express[i] + findMinCosts(dp, regular, express, expressCost, i - 1, 1, n);
        
        exp += route == 0 ? expressCost : 0;
        
        return dp[route][i] = min(reg, exp);
    }
    
public:
    vector<ll> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        vector<vector<ll>> dp(2, vector<ll> (n, -1));
        vector<ll> answer(n);
        
        findMinCosts(dp, regular, express, expressCost, n - 1, 0, n);
        
        return dp[0];
    }
};