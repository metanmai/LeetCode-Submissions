class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses), topo;
        map<int, vector<int>> adj;
        queue<int> q;
        
        for(auto edge : prerequisites)
        {
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            topo.push_back(curr);
            
            for(int node : adj[curr])
            {
                indegree[node]--;
                
                if(indegree[node] == 0)
                    q.push(node);
            }
        }
        
        if(topo.size() != numCourses)
            return {};
        
        reverse(topo.begin(), topo.end());
        return topo;
    }
};