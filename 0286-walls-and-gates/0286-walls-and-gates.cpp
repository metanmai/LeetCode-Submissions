class Solution {
private:
    struct cell
    {
        int row;
        int col;
        int dist;
        cell(int x, int y, int z) : row(x), col(y), dist(z) {}
    };
    
    vector<int> dirs = {0, 1, 0, -1, 0};
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n));
        queue<cell> q;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == 0)
                    q.push({i, j, 0});
        
        while(!q.empty())
        {
            cell ce = q.front();
            q.pop();
            
            if(ce.row >= 0 and ce.col >= 0
               and ce.row < m and ce.col < n and 
               rooms[ce.row][ce.col] != -1 and
               !visited[ce.row][ce.col])
            {
                visited[ce.row][ce.col] = true;
                
                if(rooms[ce.row][ce.col] == INT_MAX)
                    rooms[ce.row][ce.col] = ce.dist;
                
                for(int i = 0; i < 4; i++)
                    q.push({ce.row + dirs[i], ce.col + dirs[i + 1], ce.dist + 1});
            }
        }
    }
};