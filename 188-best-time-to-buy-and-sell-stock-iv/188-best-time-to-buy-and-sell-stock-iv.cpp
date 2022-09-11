class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int trans = 2 * k;
        vector<int> currProfit(trans + 1, 0), nextProfit(trans + 1, 0);
        
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            for(int t = 1; t <= trans; t++)
                if(t % 2)
                    currProfit[t] = max(nextProfit[t - 1] + prices[i], nextProfit[t]);
                else
                    currProfit[t] = max(nextProfit[t - 1] - prices[i], nextProfit[t]);
            
            nextProfit = currProfit;
        }
        return currProfit[trans];
    }
};