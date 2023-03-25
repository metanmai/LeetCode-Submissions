class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long answer = 0;
        vector<vector<int>> adj(n);
        vector<bool> visited(n);
        vector<int> components;
        
        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        function<int(int)> findComponent = [&](int curr) -> int
        {
            if(visited[curr])
                return 0;
            
            visited[curr] = true;
            int comps = 1;
            
            for(auto next : adj[curr])
                comps += findComponent(next);
            
            return comps;
        };
        
        int remaining = n;
        
        for(int i = 0; i < n; i++)
            if(!visited[i])
            {
                long component = findComponent(i);
                answer += component * (remaining - component);
                remaining -= component;
            }
        
        return answer;
    }
};