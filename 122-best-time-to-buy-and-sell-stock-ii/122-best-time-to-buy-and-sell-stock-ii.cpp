// Iteration + Tabulation Solution (Bottom-Up)

class Solution {
public:
    int profit(vector<int> prices, int startIndex, int buy, vector<vector<int>> &maxProf)
    {
        if(startIndex == prices.size())
            return 0;
        
        if(maxProf[startIndex][buy] != -1)
            return maxProf[startIndex][buy];
        
        if(buy)
            maxProf[startIndex][buy] = max(profit(prices, startIndex + 1, 0, maxProf) - prices[startIndex], // Decided to buy.
                                           profit(prices, startIndex + 1, 1, maxProf)); // Decided to not buy.

        else
            maxProf[startIndex][buy] = max(profit(prices, startIndex + 1, 1, maxProf) + prices[startIndex], // Decided to sell.
                                           profit(prices, startIndex + 1, 0, maxProf)); // Decided to not sell.
        
        return maxProf[startIndex][buy];
    }
    
    int maxProfit(vector<int>& prices) {
        // Top row : Max profit in can't buy state, Bottom Row : Max profit in can buy state.
        vector<vector<int>> maxProf(prices.size() + 1, vector<int> (2, -1));
        
        // Filling the table.
        maxProf[prices.size()][0] = maxProf[prices.size()][1] = 0;
        for(int startIndex = prices.size() - 1; startIndex >= 0; startIndex--)
            for(int buy = 0; buy <= 1; buy++)
                if(buy)
                    maxProf[startIndex][buy] = max(maxProf[startIndex + 1][0] - prices[startIndex], // Decided to buy.
                                                   maxProf[startIndex + 1][1]); // Decided to not buy.

                else
                    maxProf[startIndex][buy] = max(maxProf[startIndex + 1][1] + prices[startIndex], // Decided to sell.
                                                   maxProf[startIndex + 1][0]); // Decided to not sell.
        
        return maxProf[0][1];
    }
};