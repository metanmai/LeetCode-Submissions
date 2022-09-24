class Solution {
public:
    // Check if it has a chromatic number of 2.
    bool bfs(vector<vector<int>> graph, vector<int> &colors, int start)
    {
        queue<int> q;
        q.push(start);
        colors[start] = 0;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            for(int adj : graph[front])
            {
                if(colors[adj] == -1)
                {
                    colors[adj] = !colors[front];
                    q.push(adj);
                }
                
                // If it's already colored (a.k.a visited) it must not be pushed into the queue. Instead, just check if it has the same color as the parent node.
                else if(colors[adj] == colors[front]) 
                    return false;
            }
        }
        
        // If the is successfully emptied without clash of colors, then it is bipartite.
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> colors(v, -1);
        
        // The for loop is required as there may be multiple components.
        for(int i = 0; i < v; i++)
            if(colors[i] == -1 and !bfs(graph, colors, i)) // If the color is -1, that means it is an unvisited component and we perform bfs from there.
                    return false;
        
        // If every component is the graph is bipartite, then the entire graph is bipartite.
        return true;
    }
};