class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        vector<int> degree(n);
        vector<vector<int>> adjMatrix(n, vector<int> (n));
        
        for(auto road : roads)
        {
            degree[road[0]]++, degree[road[1]]++;
            adjMatrix[road[0]][road[1]] = adjMatrix[road[1]][road[0]] = 1;
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j)
                    maxRank = max(maxRank, degree[i] + degree[j] - adjMatrix[i][j]);
        
        return maxRank;
    }
};