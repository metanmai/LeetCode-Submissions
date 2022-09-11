// Interation + Tabulation Solution 2 (Top-Down)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> maxProfit(prices.size() + 1, vector<int> (5, 0));
        int transactions = 4; // Counting buying and selling as seperate transactions, hence there are 4 transactions.
        
        for(int startIndex = prices.size() - 1; startIndex >= 0; startIndex--)
            for(int transactions = 1; transactions <= 4; transactions++)
                if(transactions % 2) // You can only sell when the number of remaining transactions is odd and can only buy when it is even.
                    maxProfit[startIndex][transactions] = max(maxProfit[startIndex + 1][transactions - 1] + prices[startIndex],
                                                              maxProfit[startIndex + 1][transactions]);
                else
                    maxProfit[startIndex][transactions] = max(maxProfit[startIndex + 1][transactions - 1] - prices[startIndex],
                                                              maxProfit[startIndex + 1][transactions]);
        
        return maxProfit[0][4];
    }
};