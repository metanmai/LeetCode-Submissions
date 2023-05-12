#define ll long long

class Solution {
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n + 1);
        
        for(int pos = n - 1; pos >= 0; pos--)
        {
            ll take = questions[pos][0];
            if(pos + questions[pos][1] + 1 < n)
                take += dp[pos + questions[pos][1] + 1];
            
            ll notTake = dp[pos + 1];
            
            dp[pos] = max(take, notTake);
        }
        
        return dp[0];
    }
};