class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0, start = 0, n = prices.size();
    
        for(int i = 1; i < n; i++)
        {
            if(prices[i] - prices[start] < 0)
                start = i;
            maximum = max(maximum, prices[i] - prices[start]);
                
        }
        
        return maximum;
    }
};