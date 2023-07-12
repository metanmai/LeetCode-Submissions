class Solution {
private:
    int findLastStoneWeight(vector<vector<int>> &dp, vector<int> &stones, 
                            int currSum, int target, int total, int start, int n)
    {
        if(currSum >= target)
            return abs(total - (2 * currSum));
        
        if(dp[start][currSum] != -1)
            return dp[start][currSum];
        
        int minVal = total;
        
        for(int i = start; i < n; i++)
            minVal = min(minVal, findLastStoneWeight(dp, stones, currSum + stones[i], 
                                                     target, total, i + 1, n));
        
        return dp[start][currSum] = minVal;
    }
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), total = accumulate(stones.begin(), stones.end(), 0);
        int target = (total + 1) / 2;
        int maxVal = *max_element(stones.begin(), stones.end());
        vector<vector<int>> dp(n + 1, vector<int> (target + maxVal + 1, -1));
        
        return findLastStoneWeight(dp, stones, 0, target, total, 0, n);
    }
};