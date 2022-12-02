// BFS Solution.

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        vector<int> dirs = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        vector<bool> visited(jug1Capacity + jug2Capacity + 1);
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            if(curr < 0 or curr > jug1Capacity + jug2Capacity or
               visited[curr])
                continue;
            
            visited[curr] = true;
            
            if(curr == targetCapacity)
                return true;
            
            for(int i = 0; i < 4; i++)
                q.push(curr + dirs[i]);
        }
        
        return false;
    }
};