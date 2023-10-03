/*
Tarjan's Algorithm to find Bridges in a graph.
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
private:
    void findBridges(vector<vector<int>> &adj, vector<vector<int>> &bridges, 
                     vector<int> &insertion, vector<int> &minInsertion, 
                     int curr, int parent, int epoch)
    {
        insertion[curr] = minInsertion[curr] = epoch; // This is the first time you encounter this node.
        
        for(int next : adj[curr])
        {
            if(next == parent)
                continue;
            
            if(insertion[next] == -1) 
            {
                findBridges(adj, bridges, insertion, minInsertion, next, curr, epoch + 1);
                minInsertion[curr] = min(minInsertion[curr], minInsertion[next]);
                
                if(minInsertion[next] > insertion[curr]) // This is a bridge.
                    bridges.push_back({curr, next});
            }
            
            else
                minInsertion[curr] = min(minInsertion[curr], minInsertion[next]);
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), bridges;
        vector<int> insertion(n, -1), minInsertion(n, -1);
        
        for(auto conn : connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        findBridges(adj, bridges, insertion, minInsertion, 0, -1, 1);
        
        return bridges;
    }
};