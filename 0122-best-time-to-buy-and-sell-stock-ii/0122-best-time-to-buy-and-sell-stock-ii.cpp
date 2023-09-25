class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> curr(2), next(2);
        
        for(int i = prices.size() - 1; i >= 0; i--){
            for(int canBuy = 0; canBuy <= 1; canBuy++)
                if(canBuy)
                    curr[canBuy] = max(next[0] - prices[i], next[1]);

                else
                    curr[canBuy] = max(next[1] + prices[i], next[0]);
            
            next = curr;
        }
        
        return curr[1];
    }
};