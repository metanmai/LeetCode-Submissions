class Solution {
private:
    double findProb(vector<double> &prob, vector<vector<double>> &dp, 
                    int target, int i, int n)
    {
        if(i == n)
            return target == 0 ? 1 : 0;
        
        if(target == 0)
        {
            double prod = 1;
            
            for(int k = i; k < n; k++)
                prod *= 1 - prob[k];
            
            return prod;
        }
        
        if(dp[target][i] != -1)
            return dp[target][i];
        
        double head = prob[i] * findProb(prob, dp, target - 1, i + 1, n);
        double tail = (1 - prob[i]) * findProb(prob, dp, target, i + 1, n);
        
        return dp[target][i] = head + tail;
    }
    
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n + 1, vector<double> (n + 1, -1));
        
        return findProb(prob, dp, target, 0, n);
    }
};