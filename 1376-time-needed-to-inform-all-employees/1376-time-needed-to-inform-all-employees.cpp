class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int minTime = 0;
        vector<vector<int>> adj(n);
        queue<vector<int>> q; // {node, time}.
        q.push({headID, 0});
        
        for(int i = 0; i < n; i++)
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int currNode = curr[0], currTime = curr[1];
            for(auto node : adj[currNode])
                q.push({node, currTime + informTime[currNode]});
            
            minTime = max(minTime, currTime);
        }
        
        return minTime;
    }
};