class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int totalSquares = 0;
        
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(matrix[i][j] and matrix[i - 1][j - 1] and 
                   matrix[i - 1][j] and matrix[i][j - 1])
                    matrix[i][j] = 1 + min(matrix[i - 1][j - 1], 
                                           min(matrix[i][j - 1], matrix[i - 1][j]));
        
        for(int i = 0; i < m; i++)
            totalSquares += accumulate(matrix[i].begin(), matrix[i].end(), 0);
        
        return totalSquares;
    }
};