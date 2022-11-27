class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Reverse all edges.
        int n = graph.size();
        vector<int> indegree(n), topo;
        map<int, vector<int>> newAdj;
        queue<int> q;
        
        for(int i = 0; i < n; i++)
            for(int conn : graph[i])
                newAdj[conn].push_back(i), indegree[i]++;
        
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            topo.push_back(curr);
            
            for(int node : newAdj[curr])
            {
                indegree[node]--;
                
                if(indegree[node] == 0)
                    q.push(node);
            }
        }
        
        sort(topo.begin(), topo.end());
        return topo;
    }
};