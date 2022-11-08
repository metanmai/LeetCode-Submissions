class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, 
                               {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] or grid[n - 1][n - 1])
            return -1;
        
        queue<vector<int>> q;
        q.push({0, 0, 1});
        
        while(!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int x = cell[0], y = cell[1], currDist = cell[2];
            
            if(x >= 0 and y >= 0 and 
               x < n and y < n and !grid[x][y])
            {
                if(x == n - 1 and y == n - 1)
                    return currDist;
                
                grid[x][y] = 1;
                for(auto dir : directions)
                    q.push({x + dir[0], y + dir[1], currDist + 1});
            }
        }
        
        return -1;
    }
};