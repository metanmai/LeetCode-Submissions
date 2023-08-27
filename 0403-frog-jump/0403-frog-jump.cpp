class Solution {
private:
    bool canFrogJump(vector<vector<int>> &dp, vector<int> &stones, int i, int k, int n)
    {
        if(i >= n - 1)
            return i == n - 1;
        
        if(k == 0)
            return false;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int pos1 = lower_bound(stones.begin() + i + 1, stones.end(), stones[i] + k - 1) - stones.begin();
        int pos2 = lower_bound(stones.begin() + i + 1, stones.end(), stones[i] + k) - stones.begin();
        int pos3 = lower_bound(stones.begin() + i + 1, stones.end(), stones[i] + k + 1) - stones.begin();
        
        bool jump1 = pos1 != n and stones[pos1] == stones[i] + k - 1 ? canFrogJump(dp, stones, pos1, k - 1, n) : false;
        bool jump2 = pos2 != n and stones[pos2] == stones[i] + k ? canFrogJump(dp, stones, pos2, k, n) : false;
        bool jump3 = pos3 != n and stones[pos3] == stones[i] + k + 1 ? canFrogJump(dp, stones, pos3, k + 1, n) : false;
        
        return dp[i][k] = jump1 or jump2 or jump3;
    }
    
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] != 1)
            return false;
        
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        
        return canFrogJump(dp, stones, 1, 1, n); // Do not start the jump from position 0.
    }
};