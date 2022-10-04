class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int trans = 2 * k + 1, n = prices.size();
        vector<int> curr(trans, 0), next(trans, 0);
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int t = 1; t <= 2 * k; t++)
                if(!(t % 2))
                    curr[t] = max(next[t - 1] - prices[i], next[t]);
                
                else
                    curr[t] = max(next[t - 1] + prices[i], next[t]);
            
            next = curr;
        }
        
        return curr[trans - 1];
    }
};