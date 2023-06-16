class Solution {
private:
    int findUniqueTrees(vector<int> &dp, int start, int end)
    {
        if(start > end)
            return 1;
        
        if(dp[end - start] != -1)
            return dp[end - start];
        
        int answer = 0;
        
        for(int i = start; i <= end; i++)
        {
            int left = findUniqueTrees(dp, start, i - 1);
            int right = findUniqueTrees(dp, i + 1, end);
            
            answer += left * right;
        }
        
        return dp[end - start] = answer;
    }
    
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        
        return findUniqueTrees(dp, 1, n);
    }
};