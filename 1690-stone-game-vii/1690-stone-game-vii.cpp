class Solution {
private:
    int findDifference(vector<int> &prefix, vector<vector<int>> &dp,
                  int start, int end, bool alice)
    {
        if(start == end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int diff = 0;
        
        int left = findDifference(prefix, dp, start + 1, end, !alice);
        int right = findDifference(prefix, dp, start, end - 1, !alice);
        
        if(alice)
            diff = max(prefix[end + 1] - prefix[start + 1] + left, 
                        prefix[end] - prefix[start] + right);
        
        else
            diff = min(left - (prefix[end + 1] - prefix[start + 1]), 
                        right - (prefix[end] - prefix[start]));
        
        return dp[start][end] = diff;
    }
    
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size(), total = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n, vector<int> (n, -1));
        vector<int> prefix = {0};
        
        for(int stone : stones)
            prefix.push_back(prefix.back() + stone);
        
        return findDifference(prefix, dp, 0, n - 1, true);
    }
};