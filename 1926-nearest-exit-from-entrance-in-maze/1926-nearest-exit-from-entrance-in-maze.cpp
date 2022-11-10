class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<int> dirs = {0, 1, 0, -1, 0};
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            int r = cell[0], c = cell[1], dist = cell[2];
            
            if(r >= 0 and c >= 0 and
               r < m and c < n and maze[r][c] == '.')
            {
                maze[r][c] = '+';
                
                if((r == 0 or c == 0 or r == m - 1 or c == n - 1) and
                   !(r == entrance[0] and c == entrance[1]))
                    return dist;
                
                else
                    for(int i = 0; i < 4; i++)
                        q.push({r + dirs[i], c + dirs[i + 1], dist + 1});
            }
        }
        
        return -1;
    }
};