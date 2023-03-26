class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long answer = LLONG_MAX;
        vector<long long> topPrefix = {0}, bottomPrefix = {0};
        
        for(int i = 0; i < n; i++)
        {
            topPrefix.push_back(topPrefix[i] + grid[0][i]);
            bottomPrefix.push_back(bottomPrefix[i] + grid[1][i]);
        }
        
        for(int i = 1; i <= n; i++)
        {
            long long top = topPrefix[n] - topPrefix[i];
            long long bottom = bottomPrefix[i - 1];
            
            answer = min(answer, max(top, bottom));
        }
        
        return answer;
    }
};