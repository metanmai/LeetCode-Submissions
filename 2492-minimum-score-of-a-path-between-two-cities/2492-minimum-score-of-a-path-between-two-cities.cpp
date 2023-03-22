class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int lowScore = INT_MAX;
        
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<bool> visited(n + 1);
        queue<int> q;
        
        for(auto road : roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        q.push(1);
        
        while(!q.empty())
        {
            int currNode = q.front(); q.pop();
            
            for(auto nextNode : adj[currNode])
            {
                if(!visited[nextNode.first])
                {
                    visited[nextNode.first] = true;
                    q.push(nextNode.first);
                }
                
                lowScore = min(lowScore, nextNode.second);
            }
        }
        
        return lowScore;
    }
};