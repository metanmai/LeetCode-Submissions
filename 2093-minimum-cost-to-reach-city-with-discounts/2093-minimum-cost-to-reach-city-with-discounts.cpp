class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        queue<vector<int>> pq;
        dist[0] = 0;
        
        for(auto edge : highways)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        pq.push({0, 0, discounts}); // {distance, node, discounts}.
        
        while(!pq.empty())
        {
            auto curr = pq.front(); pq.pop();
            int currDist = curr[0], currNode = curr[1], currDisc = curr[2];
            
            for(auto [nextNode, nextDist] : adj[currNode])
            {
                int lastDist = dist[nextNode];
                
                if(currDist + nextDist < lastDist)
                    pq.push({dist[nextNode] = currDist + nextDist, nextNode, currDisc});
                
                if(currDisc > 0 and currDist + (nextDist / 2) < lastDist)
                    pq.push({dist[nextNode] = currDist + (nextDist / 2), nextNode, currDisc - 1});
            }
        }
        
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};