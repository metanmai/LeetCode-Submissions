// Iteration DP Solution (Bottom-Up)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Top row : Max profit in can't buy state, Bottom Row : Max profit in can buy state.
        vector<int> nextIndex(2, 0), currIndex(2, 0);
        
        // Filling the table.
        for(int startIndex = prices.size() - 1; startIndex >= 0; startIndex--)
        {
            for(int buy = 0; buy <= 1; buy++)
                if(buy)
                    currIndex[buy] = max(nextIndex[0] - prices[startIndex], // Decided to buy.
                                         nextIndex[1]); // Decided to not buy.

                else
                    currIndex[buy] = max(nextIndex[1] + prices[startIndex], // Decided to sell.
                                                   nextIndex[0]); // Decided to not sell.
            
            nextIndex = currIndex;
        }
        return currIndex[1];
    }
};