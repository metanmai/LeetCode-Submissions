// Interative Solution 2 (Top-Down)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> currProfit(5, 0), nextProfit(5, 0);
        
        for(int startIndex = prices.size() - 1; startIndex >= 0; startIndex--)
        {
            // Counting buying and selling as seperate transactions, hence there are 4 transactions.
            for(int transactions = 1; transactions <= 4; transactions++)
                if(transactions % 2) // You can only sell when the number of remaining transactions is odd and can only buy when it is even.
                    currProfit[transactions] = max(nextProfit[transactions - 1] + prices[startIndex],
                                                   nextProfit[transactions]);
                else
                    currProfit[transactions] = max(nextProfit[transactions - 1] - prices[startIndex],
                                                   nextProfit[transactions]);
            
            nextProfit = currProfit;
        }
        return currProfit[4];
    }
};