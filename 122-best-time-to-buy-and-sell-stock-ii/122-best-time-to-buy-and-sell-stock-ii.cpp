// Iteration DP Solution (Bottom-Up)

class Solution {
public:
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