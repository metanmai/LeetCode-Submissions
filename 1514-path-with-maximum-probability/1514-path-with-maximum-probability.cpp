class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        vector<double> maxProb(n);
        priority_queue<pair<double, int>> pq; // {val, node}.
        
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        pq.push({1, start});
        
        while(!pq.empty())
        {
            auto [currProb, currNode] = pq.top(); pq.pop();
            
            for(auto next : adj[currNode])
            {
                auto [nextNode, nextProb] = next;
                
                if(currProb * nextProb > maxProb[nextNode])
                    pq.push({maxProb[nextNode] = currProb * nextProb, nextNode});
            }
        }
        
        return maxProb[end];
    }
};