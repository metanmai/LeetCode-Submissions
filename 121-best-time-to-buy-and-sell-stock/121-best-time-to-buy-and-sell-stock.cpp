class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0, minimumSoFar = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < prices[minimumSoFar])
                minimumSoFar = i;
            
            maxProf = max(maxProf, prices[i] - prices[minimumSoFar]);
        }
        
        return maxProf;
    }
};