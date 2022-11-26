class Solution {
private:
    void visitRooms(vector<vector<int>> rooms, vector<int> &visited, int pos)
    {
        if(visited[pos])
            return;
        
        visited[pos] = 1;
        for(int i = 0; i < rooms[pos].size(); i++)
            visitRooms(rooms, visited, rooms[pos][i]);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n);
        
        visitRooms(rooms, visited, 0);
        return accumulate(visited.begin(), visited.end(), 0) == n;
    }
};