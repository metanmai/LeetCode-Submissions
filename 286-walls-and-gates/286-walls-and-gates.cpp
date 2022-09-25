class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == 0)
                {
                    q.push({i, j, 0}); // Perform BFS from all the gates simultaneously. That way all rooms will always have min distance from the nearest gate.
                }
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            for(auto dir : directions)
            {
                int r = front[0] + dir[0], c = front[1] + dir[1], currMin = front[2];
                if(r < 0 or c < 0 or 
                   r >= m or c >= n or
                   rooms[r][c] != INT_MAX) // You don't need a visited array because if a room has been visited then it won't be INT_MAX.
                    continue;
            
                rooms[r][c] = currMin + 1;
                q.push({r, c, rooms[r][c]});
            }
        }
    }
};