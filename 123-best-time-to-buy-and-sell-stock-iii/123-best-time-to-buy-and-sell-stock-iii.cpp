class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(5, 0), next(5, 0);
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int transactions = 1; transactions <= 4; transactions++)
                if(transactions % 2 == 0)
                    curr[transactions] = max(next[transactions - 1] - prices[i],
                                             next[transactions]);

                else
                    curr[transactions] = max(next[transactions - 1] + prices[i],
                                             next[transactions]);
            
            next = curr;
        }
        return curr[4];
    }
};