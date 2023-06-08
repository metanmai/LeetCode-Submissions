class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0, j = n;
        
        for(int i = 0; i < m; i++)
        {
            while(j > 0 and 
                  grid[i][j - 1] < 0)
                j--;
            
            count += n - j;
        }
        
        return count;
    }
};