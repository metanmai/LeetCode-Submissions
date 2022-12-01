class Solution {
private:
    bool isBipartiteComponent(vector<vector<int>> &graph, vector<int> &colors, int start)
    {
        queue<int> q;
        q.push(start);
        colors[start] = 0;
        
        while(!q.empty())
        {
            int currNode = q.front();
            q.pop();
            
            for(int node : graph[currNode])
                if(colors[node] == -1)
                {
                    colors[node] = !colors[currNode];
                    q.push(node);
                }
                
                else if(colors[node] == colors[currNode])
                    return false;       
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);
        
        // There can be multiple components in the graph.
        for(vector<int> conn : graph)
            for(int node : conn)
                if(colors[node] == -1 and !isBipartiteComponent(graph, colors, node))
                    return false;
        
        return true;
    }
};