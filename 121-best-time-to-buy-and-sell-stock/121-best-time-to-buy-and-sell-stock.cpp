class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumSoFar = 0, maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++)
            if(prices[i] < prices[minimumSoFar])
                minimumSoFar = i;
            else
                maxProfit = max(maxProfit, prices[i] - prices[minimumSoFar]);
        
        return maxProfit;
    }
};