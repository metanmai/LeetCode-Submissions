class Solution {
public:   
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> profit(prices.size() + 1, vector<vector<int>> (2, vector<int> (2, 0)));
        
        for(int i = prices.size() - 1; i >= 0; i--)
            for(int canBuy = 0; canBuy <= 1; canBuy++)
                for(int wait = 0; wait <= 1; wait++)
                {
                    if(wait)
                        profit[i][canBuy][wait] = profit[i + 1][1][0];

                    else if(canBuy) // This has to be else if and not just if because if wait it true then no other statement should get executed.
                        profit[i][canBuy][wait] = max(profit[i + 1][0][0] - prices[i],
                                                      profit[i + 1][1][0]);

                    else
                        profit[i][canBuy][wait] = max(profit[i + 1][1][1] + prices[i], // Wait becomes true only when you sell. 
                                                      profit[i + 1][0][0]);
                }
        
        return profit[0][1][0];
    }
};