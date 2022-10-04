class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);
        
        for(int i = n - 1; i >= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++)
                if(canBuy)
                    curr[canBuy] = max(next[0] - prices[i] - fee, next[1]);

                else
                    curr[canBuy] = max(next[1] + prices[i], next[0]);
            
            next = curr;
        }
        
        return curr[1];
    }
};