class Solution {
private:
    using lolo = long long;
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        priority_queue<pair<lolo, lolo>, vector<pair<lolo, lolo>>, greater<>> pq;
        vector<vector<pair<int, int>>> adj(n);
        vector<lolo> dists(n, numeric_limits<lolo>::max()), ways(n);
        dists[0] = 0, ways[0] = 1;
        
        for(auto road : roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        pq.push({0, 0});
        
        while(!pq.empty())
        {
            auto [currDist, currNode] = pq.top(); pq.pop();
            
            if(currDist > dists[currNode])
                continue;
            
            for(auto [nextNode, nextDist] : adj[currNode])
            {
                if(currDist + nextDist < dists[nextNode])
                {
                    // Reset to ways[currNode] if you encounter a smaller dist value.
                    ways[nextNode] = ways[currNode];
                    pq.push({dists[nextNode] = currDist + nextDist, nextNode});
                }
                
                else if(currDist + nextDist == dists[nextNode])
                    ways[nextNode] = (ways[nextNode] + ways[currNode]) % MOD;
            }
        }
        
        return ways[n - 1];
    }
};