class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), perimeter = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j])
                {
                    perimeter += 4;
                    for(int k = 0; k < 4; k++)
                    {
                        int r = i + dirs[k], c = j + dirs[k + 1];
                        if(r >= 0 and c >= 0 and
                           r < m and c < n and grid[r][c])
                            perimeter--;
                    }
                }
        
        return perimeter;
    }
};