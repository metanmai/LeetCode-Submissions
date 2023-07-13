class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        int topoLen = 0;
        
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
            
            topoLen++;
            
            for(int node : adj[curr])
            {
                indegree[node]--;
                
                if(indegree[node] == 0)
                    q.push(node);
            }
        }
        
        return topoLen == numCourses;
    }
};