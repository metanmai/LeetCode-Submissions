class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int swaps = 0;
        vector<vector<int>> forward(n), backward(n);
        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        
        for(auto conn : connections)
        {
            forward[conn[0]].push_back(conn[1]);
            backward[conn[1]].push_back(conn[0]);
        }
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            visited[curr] = true;
            
            // Nodes for which the incoming edge is not towards 0.
            for(auto node : forward[curr])
                if(!visited[node])
                    q.push(node), swaps++;
            
            /* If there is a node that faces inward to us that we haven't visited yet, 
            it would be in the backward vector. 
            We need to add inward facing nodes to the queue as well, 
            since they might have neighbors that need to be flipped.*/
            
            // Nodes for which the incoming edge is towards 0.
            for(auto node : backward[curr])
                if(!visited[node])
                    q.push(node);
        }
        
        return swaps;
    }
};