class Solution {
private:
    int m, n;
    vector<int> dirs = {0, 1, 0, -1, 0};
    
    int findPath(vector<vector<int>> &matrix, vector<vector<int>> &longestPath, int x, int y)
    {   
        if(longestPath[x][y] != -1)
            return longestPath[x][y];
        
        int currLen = 1;
        
        for(int k = 0; k < 4; k++)
        {
            int nx = x + dirs[k], ny = y + dirs[k + 1];
            
            if(min(nx, ny) >= 0 and nx < m and ny < n and 
               matrix[nx][ny] > matrix[x][y])
                currLen = max(currLen, 1 + findPath(matrix, longestPath, nx, ny));
        }
        
        return longestPath[x][y] = currLen;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int maxLen = 1;
        vector<vector<int>> longestPath(m, vector<int> (n, -1));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                maxLen = max(maxLen, findPath(matrix, longestPath, i, j));
        
        return maxLen;
    }
};