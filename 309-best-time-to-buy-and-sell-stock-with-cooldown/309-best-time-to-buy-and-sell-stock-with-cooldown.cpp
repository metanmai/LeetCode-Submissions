class Solution {
public:
    int maxProf(vector<int> prices, int i, int canBuy)
    {
        if(i >= prices.size())
            return 0;
        
        int profit = 0;
        
        if(canBuy)
            profit = max(maxProf(prices, i + 1, 0) - prices[i],
                         maxProf(prices, i + 1, 1));
        
        else
            profit = max(maxProf(prices, i + 2, 1) + prices[i],
                         maxProf(prices, i + 1, 0));
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0), nextnext(2, 0);
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int canBuy = 0; canBuy <= 1; canBuy++)
            {
                if(canBuy)
                    curr[canBuy] = max(next[0] - prices[i],
                                        next[1]);

                else
                    curr[canBuy] = max(nextnext[1] + prices[i],
                                        next[0]);
            }
            nextnext = next;
            next = curr;
        }
        
        return curr[1];
    }
};