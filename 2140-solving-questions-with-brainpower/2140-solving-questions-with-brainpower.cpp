#define ll long long

class Solution {
private:
    ll findMaxPoints(vector<vector<int>> &questions, vector<ll> &dp, 
                     int pos, int n)
    {
        if(pos >= questions.size())
            return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        ll take = (questions[pos][0] + 
                    findMaxPoints(questions, dp, pos + questions[pos][1] + 1, n));
                    
        ll notTake = findMaxPoints(questions, dp, pos + 1, n);
        
        return dp[pos] = max(take, notTake);        
    }
    
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n, -1);
        
        return findMaxPoints(questions, dp, 0, n);
    }
};